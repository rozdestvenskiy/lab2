int show_version(char *vers)
{
    printf("Version %s\n", vers);
    return 0;
}

int show_help(int x)
{
    printf("=-------------------DESCRIPTION------------------=\n");
    printf("= This is UDP client and server. Client makes    =\n");
    printf("= message from language selector and digit,      =\n");
    printf("= send it to the server. Server makes text       =\n");
    printf("= from client's digit.                           =\n");
    printf("=----------------------USAGE---------------------=\n");
    printf("=             ./lab2client [options]             =\n");
    printf("=             ./lab2server [options]             =\n");
    printf("=---------------------OPTIONS--------------------=\n");
    printf("= -h\t shows this page (client and server)       =\n");
    printf("= -v\t show version of program (C&S)             =\n");
    printf("= -l\t add path to log file (server only)        =\n");
    printf("= -a\t choose IP address (client and server)     =\n");
    printf("= -p\t choose port (client and server)           =\n");
    printf("= -l\t add path to log file (server only)        =\n");
    printf("= -w\t simulation of waiting in threads (S only) =\n");
    printf("= -d\t daemon mode (server only)                 =\n");
    printf("=------------------------------------------------=\n");
    exit(0);
}

void check(int ret)
{
    if (ret < 0) 
    {
        exit(EXIT_FAILURE);
    }
}

struct tm *ptr;
char tbuf[80];
time_t now;
char * getTime()
{
    char *ret;
    ret=(char*)malloc(100);
    bzero(ret,100);
    time(&now);
    ptr = localtime(&now);
    strftime(tbuf,80,"%e-%B-%Y %H:%M:%S",ptr);
    ret = tbuf;
    return (ret);
}
