#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <inttypes.h>
#include <getopt.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include "to_string.h"
#include "types.h"
#include "funcs.h"

#define BUF_SIZE 1024

int getopt_long(int argc,
                char * const argv[],
                const char *optstring,
                const struct option *longopts,
                int *longindex);

char *Version = "0.66";
struct option *long_options;
int sock;
struct sockaddr_in serv_addr;
struct hostent *server;

const char* short_options = "-:a:p:vhw:dl:";
char *ipv4_addr_str;
char *port_str;
int ip_flag = 0;
int port_flag = 0;
char buffer[256];
char *log_file_addr;
int log_file_flag = 0;
int daemon_mode = 0;
int wait_mode = 0;
int wait_mode_flag = 0;
int all_calls = 0;
int success_calls = 0;
FILE *logfile;


int show_statistics(int x)
{
    fprintf(logfile, "=-------------------STATISTICS------------------=\n");
    fprintf(logfile, "= ALL CALLS: %d                                 =\n", all_calls);
    fprintf(logfile, "= SUCCESSFUL CALLS: %d                          =\n", success_calls);
    fprintf(logfile, "=-----------------------------------------------=\n");

    if (daemon_mode == 0)
    {
        fprintf(stdout, "=-------------------STATISTICS------------------=\n");
    	fprintf(stdout, "= ALL CALLS: %d                                 =\n", all_calls);
    	fprintf(stdout, "= SUCCESSFUL CALLS: %d                          =\n", success_calls);
    	fprintf(stdout, "=-----------------------------------------------=\n");
    }
    return 0;
}

void* threadFunc(void* thread_data);
int daemon_func(void);

static void SIG_handler(int signum, siginfo_t *s, void *c) 
{
    if (signum == SIGINT)
    {
        fprintf(logfile, "[%s] Signal received: SIGINT\n", getTime());
        fprintf(logfile, "[%s] Ending...\n", getTime());
        if (daemon_mode == 0)
        {
            printf("Signal received: SIGINT\n");
            printf("Ending...\n");
        }
        close(sock);
        exit(0);
    }
    if (signum == SIGQUIT)
    {
        fprintf(logfile, "[%s] Signal received: SIGQUIT\n", getTime());
        fprintf(logfile, "[%s] Ending...\n", getTime());
        if (daemon_mode == 0)
        {
            printf("Signal received: SIGQUIT\n");
            printf("Ending...\n");
        }

        close(sock);
        exit(0);
    }
    if (signum == SIGTERM)
    {
        fprintf(logfile, "[%s] Signal received: SIGTERM\n", getTime());
        fprintf(logfile, "[%s] Ending...\n", getTime());
        if (daemon_mode == 0)
        {
            printf("Signal received: SIGTERM\n");
            printf("Ending...\n");
        }
        close(sock);
        exit(0);
    }
    if (signum == SIGUSR1)
    {
        fprintf(logfile, "[%s] Signal received: SIGUSR1\n", getTime());
        if (daemon_mode == 0)
        {
            printf("Signal received: SIGUSR1\n");
        }

        show_statistics(0);
    }
}

int main(int argc, char* argv[])
{
    struct sigaction sa = {0};
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGINT);
    sigaddset(&sa.sa_mask, SIGQUIT);
    sigaddset(&sa.sa_mask, SIGTERM);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sa.sa_sigaction = SIG_handler;
    sa.sa_flags |= (SA_SIGINFO | SA_RESTART); // mind SA_RESTART here!

    check(sigaction(SIGINT, &sa, NULL));
    check(sigaction(SIGQUIT, &sa, NULL));
    check(sigaction(SIGUSR1, &sa, NULL));
    check(sigaction(SIGTERM, &sa, NULL));

    int rez;
    int option_index = -1;
    while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1)
    {
        
        switch (rez)
        {
            case 'h':
            {
                show_help(0);
                exit(0);
            };
            case 'v':
            {
                show_version(Version);
                exit(0);
            };
            case 'w':
            {
                if (optarg)
                {
                    wait_mode = atoi(optarg);
                    if (wait_mode == 0)
                    {
                        printf("Error: wrong argument in -w\n");
                        exit(1);
                    }
                }
                else
                {
                    printf("Error: option -w required argument\n");
                    exit(1);
                }
                wait_mode_flag++;
                break;
            };
            case 'd':
            {
                daemon_mode++;
                break;
            };

            case 'l':
            {
                if (optarg)
                {
                    log_file_addr = optarg;
                }
                else
                {
                    printf("Error: option -l required argument\n");
                    exit(1);
                }
                log_file_flag++;
                break;
            };

            case 'a':
            {
                if (optarg)
                {
                    ipv4_addr_str = optarg;
                }
                else
                {
                    printf("Error: option -a required argument\n");
                    exit(1);
                }
                ip_flag++;
                break;
            };

            case 'p':
            {
                if (optarg)
                {
                    port_str = optarg;
                }
                else
                {
                    printf("Error: option -p required argument\n");
                    exit(1);
                }
                port_flag++;
                break;
            }
            case ':':
            {
                printf("Error: missing argument\n");
                exit(1);
            }
            case '?':
            {
                printf("Error: unknown option\n");
                exit(1);
            }
            default:
            {
                break;
            };
        };
    };

    if (log_file_flag == 0)
    {
        log_file_addr = getenv("L2LOGFILE");
        if (log_file_addr == NULL)
        {
            log_file_addr = "log.txt";
        }
    }
    logfile = fopen(log_file_addr, "w");
    fprintf(logfile, "[%s] Started\n", getTime());
    if (ip_flag == 0)
    {
        ipv4_addr_str = getenv("L2ADDR");
    }
    if (port_flag == 0)
    {
        port_str = getenv("L2PORT");
    }
    if (ipv4_addr_str == NULL)
    {
    	printf("IP address not found\n");
    	exit(1);
    }
    if (port_str == NULL)
    {
    	printf("Port not found\n");
    	exit(1);
    }

    if (wait_mode_flag == 0)
    {
        if (getenv("L2WAIT") == NULL)
        {
            wait_mode = 0;
        }
        else
        {
            wait_mode = atoi(getenv("L2WAIT"));
            if (wait_mode == 0)
            {
                printf("Error: wrong argument in L2WAIT\n");
                fprintf(logfile, "[%s] Error: wrong argument in L2WAIT\nExit...\n", getTime());
                exit(1);
            }
        }
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        printf("Error wile creating socket\n");
        fprintf(logfile, "[%s] Error wile creating socket\nExit...\n", getTime());
        exit(1);
    }

    int port = atoi(port_str);
    if (port == 0)
    {
        printf("Error: wrong format of port number\n");
        fprintf(logfile, "[%s] Error: wrong format of port number\nExit...\n", getTime());
        close(sock);
        exit(1);
    }

    server = gethostbyname(ipv4_addr_str);
    if (server == NULL)
    {
        printf("Error: no such host\n");
        fprintf(logfile, "[%s] Error: no such host\nExit...\n", getTime());
        close(sock);
        exit(1);
    }
    int res;

    res = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int));
    if (res != 0)
    {
        printf("Error: wrong sock options\n");
        fprintf(logfile, "[%s] Error: wrong sock options\nExit...\n", getTime());
        exit(1);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ipv4_addr_str);
    serv_addr.sin_port = htons(port);

    
    int x;
    x = bind(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (x != 0)
    {
        printf("Error: while binding\n");
        fprintf(logfile, "[%s] Error: while binding\nExit...\n", getTime());
        exit(1);
    }
    pid_t parpid;
    if (daemon_mode == 0)
    {
    	//printf("not daemon\n");
        daemon_func();
        fprintf(logfile, "[%s] Starting in console mode\n", getTime());
    }
    else
    {
        if ((parpid = fork()) < 0)
        {
            printf("Error: creating fork with daemon\n");
            fprintf(logfile, "[%s] Error: creating fork with daemon\nExit...\n", getTime());
            exit(1);
        }
        else
        {
            if (parpid != 0) {
                exit(0);
            }
            setsid();
            fprintf(logfile, "[%s] Starting in daemon mode\n", getTime());
            daemon_func();
            chdir("/");
            close(stdin);
            close(stdout);
            close(stderr);
        }
    }
}

void* threadFunc(void* thread_data)
{
    fprintf(logfile, "[%s] Thread started\n", getTime());
	int n;
    if (wait_mode != 0)
    {
        sleep(wait_mode);
        fprintf(logfile, "[%s] waiting for %d seconds\n", getTime(), wait_mode);

    }

    thread_dataS *data = (thread_dataS *) thread_data;
    char *error_str = malloc(sizeof(char) * 100);
    
    if (data->in_lang == NULL)
    {
    	fprintf(logfile, "Error: missed language selector pointer\n", getTime());
    	if (daemon_mode == 0)
    	{
        	
        	fprintf(stdout, "Error: missed language selector pointer\n", getTime());
    	}
    	strncat(error_str, "Error 01: missed language selector pointer\n", strlen("Error 01: missed language selector pointer\n"));
	n = write(data->out_socket, error_str, strlen(error_str));
	if (n == -1)
    	{
        	fprintf(logfile, "[%s] Error: writing to socket\n", getTime());
    	}
    	else
    	{
        	fprintf(logfile, "[%s] Writing to client: %s", getTime(), error_str);
    	}
    	close(data->out_socket);
    	pthread_detach(pthread_self());
    	pthread_exit(1);
    }
    
    if (data->in_lang == NULL)
    {
    	fprintf(logfile, "Error: missed digit pointer\n", getTime());
    	if (daemon_mode == 0)
    	{
        	
        	fprintf(stdout, "Error: missed digit pointer\n", getTime());
    	}
    	strncat(error_str, "Error 02: missed digit pointer\n", strlen("Error 02: missed digit pointer\n"));
	n = write(data->out_socket, error_str, strlen(error_str));
	if (n == -1)
    	{
        	fprintf(logfile, "[%s] Error: writing to socket\n", getTime());
    	}
    	else
    	{
        	fprintf(logfile, "[%s] Writing to client: %s", getTime(), error_str);
    	}
    	close(data->out_socket);
    	pthread_detach(pthread_self());
    	pthread_exit(1);
    }

    char *lang = malloc(sizeof(char) * strlen(data->in_lang));
    char *digit = malloc(sizeof(char) * 100);
    
    strncpy(lang, data->in_lang, 2);
    strncat(digit, data->in_digit, strlen(data->in_digit));
    
    if ((strcmp(lang, "RU") != 0) && (strcmp(lang, "EN") != 0))
    {
    	fprintf(logfile, "Error: invalid syntax of language selector\n", getTime());
    	if (daemon_mode == 0)
    	{
        	
        	fprintf(stdout, "Error: invalid syntax of language selector\n", getTime());
    	}
    	strncat(error_str, "Error 03: invalid syntax of language selector\n", strlen("Error 03: invalid syntax of language selector\n"));
	n = write(data->out_socket, error_str, strlen(error_str));
	if (n == -1)
    	{
        	fprintf(logfile, "[%s] Error: writing to socket\n", getTime());
    	}
    	else
    	{
        	fprintf(logfile, "[%s] Writing to client: %s", getTime(), error_str);
    	}
    	close(data->out_socket);
    	pthread_detach(pthread_self());
    	pthread_exit(1);
    }
    
    char *digits = "-01234567890";
    for (int i = 0; i < strlen(digit); i++)
    {
    	
    	if (strchr(digits, digit[i]) == NULL)
    	{
    		fprintf(logfile, "Error: invalid syntax of digit\n", getTime());
    		if (daemon_mode == 0)
    		{
        		fprintf(stdout, "Error: invalid syntax of digit\n", getTime());
    		}
    		strncat(error_str, "Error 04: invalid syntax of digit\n", strlen("Error 02: invalid syntax of digit\n"));
		n = write(data->out_socket, error_str, strlen(error_str));
		if (n == -1)
    		{
        		fprintf(logfile, "[%s] Error: writing to socket\n", getTime());
    		}
    		else
    		{
        		fprintf(logfile, "[%s] Writing to client: %s", getTime(), error_str);
    		}
    		
    		close(data->out_socket);
    		pthread_detach(pthread_self());
    		pthread_exit(1);
    	}
    }
    
    char *out_str;
    
    if (strcmp(lang, "RU") == 0)
    {
    	out_str = to_string_RU(digit);
    	
    }
    if (strcmp(lang, "EN") == 0)
    {
    	out_str = to_string_EN(digit);
    }
    
    int lenn = sizeof(data->client);
    n = sendto(sock, out_str, strlen(out_str), 0, (struct sockaddr_in*)&data->client, lenn);
    //printf("n = %d\n", n);
    if (n == -1)
    {
        fprintf(logfile, "[%s] Error: writing to socket\n", getTime());
        //exit(1);
    }
    else
    {
        fprintf(logfile, "[%s] Writing to client: %s\n", getTime(), out_str);

        success_calls++;
    }
    close(data->out_socket);
    free(thread_data);
    pthread_detach(pthread_self());
    pthread_exit(0);
}

int daemon_func(void)
{
    int connfd, n;
    char *in_lang = malloc(sizeof(char) * 5);
    char *in_digit = malloc(sizeof(char) * 100);
	struct sockaddr_in client = {0};

    while(1)
    {
        in_lang = malloc(sizeof(char) * 255);
        if (in_lang == NULL)
        {
            fprintf(logfile, "[%s] Error: NULL pointer str_in\n", getTime());
            exit(1);
        }
        int len = sizeof(client);
        n = recvfrom(sock, in_lang, 2, 0, (struct sockaddr_in*)&client, &len);
        //printf("in_lang = %s\n", in_lang);
        all_calls++;
        if (n == -1)
        {
            fprintf(logfile, "[%s] Error: reading from socket\n", getTime());
            continue;
        }
        int length = 0;
        n = recv(sock, in_digit, 255, 0);
        char *dg = "-1234567890";
        int dglen = 0;
        for (int i = 0; i < 255; i++)
        {
        	if (strchr(dg, in_digit[i]) != NULL)
        	{
        		dglen++;
        	}
        	else
        	{
        		break;
        	}
        	
        }
        if (n == -1)
        {
            fprintf(logfile, "[%s] Error: reading from socket\n", getTime());
            continue;
        }

        pthread_t *new_thread = malloc(sizeof(pthread_t));
        if (new_thread == NULL)
        {
            fprintf(logfile, "[%s] Error: NULL pointer new_thread\n", getTime());
            exit(1);
        }
        thread_dataS *td_in = malloc(sizeof(thread_dataS));
        if (td_in == NULL)
        {
            fprintf(logfile, "[%s] Error: NULL pointer td_in\n", getTime());
            exit(1);
        }
        td_in->in_lang = malloc(sizeof(char) * strlen(in_lang));
        td_in->in_digit = malloc(sizeof(char) * 100);
        td_in->client = client;
        if (td_in->in_lang == NULL)
        {
            fprintf(logfile, "[%s] Error: NULL pointer \n", getTime());
            exit(1);
        }
        td_in->out_socket = connfd;

	if ((in_lang[0] == 'R') && (in_lang[1] == 'U'))
	{
		strncpy(td_in->in_lang, "RU", 2);
	}
	else
	{
		if ((in_lang[0] == 'E') && (in_lang[1] == 'N'))
		{
			strncpy(td_in->in_lang, "EN", 2);
		}
		else
		{
			strncpy(td_in->in_lang, "EN", 2);
		}	
	}
	
        snprintf(td_in->in_digit, dglen + 1, "%s", in_digit);

        int rr;
        rr = pthread_create(&(new_thread), NULL, threadFunc, td_in);
        if (rr != 0)
        {
            fprintf(logfile, "[%s] Error: creating thread\n", getTime());
            exit(1);
        }
        
        sleep(1);
    }
    close(sock);

    return 0;
}
