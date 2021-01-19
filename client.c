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

int getopt_long(int argc,
                char * const argv[],
                const char *optstring,
                const struct option *longopts,
                int *longindex);

char *Version = "0.65";
struct option *long_options;

int main(int argc, char* argv[])
{
    struct sockaddr_in serv_addr;
    struct hostent *server;

    const char* short_options = "-:a:p:vh";
    char *ipv4_addr_str;
    char *port_str;
    int ip_flag = 0;
    int port_flag = 0;
    char buffer[256];

    int rez;
    int option_index = -1;
    while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1)
    {
        //printf("%c\n", rez);
        switch (rez)
        {
            case 'h':
            {
                show_help(0);
                exit(0);
            };
            case 'v':
            {
                show_version(0);
                exit(0);
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
    //printf("after opts\n");

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
    
    //printf("after getenv\n");

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        printf("Error wile creating socket\n");
        exit(1);
    }
    //printf("after sock\n");

    int port = atoi(port_str);
    //printf("after port\n");
    if (port == 0)
    {
        printf("Error: wrong format of port number\n");
        exit(1);
    }
	//printf("after port\n");
    server = gethostbyname(ipv4_addr_str);
    
    if (server == NULL)
    {
        printf("Error: no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    //bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_addr.s_addr = inet_addr(ipv4_addr_str);
    serv_addr.sin_port = htons(port);

    //printf("%s\n", ipv4_addr_str);
    //printf("%s\n", (char *)&serv_addr.sin_addr.s_addr);
    printf("--\n");
    printf("--\n");
    
    //printf("Please enter digit: ");
    char *str;
    str = malloc(sizeof(char) * 255);
    bzero(buffer, 256);
    //scanf("%s", str);
    
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error while connecting\n");
        close(sock);
        exit(1);
    }
    //printf("-- %s", str);
    //printf("--\n");
    int n;
    
    char *str2;
    str2 = malloc(sizeof(char) * 255);
    printf("Please enter language selector: \n");
    
  
    fgets(str, 255, stdin);
    //puts(str);
    //n = write(sock, str, strlen(str));
    n = send(sock, str, strlen(str), 0);
    printf("lang = %s\n", str);
    printf("Please enter digit: \n");
    fgets(str2, 255, stdin);
    //puts(str2);
    printf("digit = %s\n", str2);
    
    //n = write(sock, str2, strlen(str2));
    //int lenn = sizeof(data->client);
    n = send(sock, str2, strlen(str2), 0);
    

    if (n < 0)
    {
        printf("Error: writing to socket\n");
        close(sock);
        exit(1);
    }

    bzero(buffer, 256);

    char *string_out = malloc(sizeof(char) * 1000);

    n = recv(sock, string_out, 1000, 0);
    printf("n = %d\n", n);
    //n = read(sock, string_out, 255);

    if (n < 0)
    {
        printf("Error: writing to socket\n");
        close(sock);
        exit(1);
    }
    printf("out = %s\n", string_out);
    bzero(buffer, 256);
    close(sock);





    return 0;
}
