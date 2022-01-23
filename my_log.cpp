#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdarg.h>

#define LOG_MAX_LEN 1024

#define logDebug 0 
#define logWarning 1 
#define logError 2


#define mylogger(level, ...) do {\
        _mylogger(level, __VA_ARGS__); \
    }while(0)

void myLogger(int level, const char *msg);

void _mylogger(int level, const char* fmt, ...)
{
    va_list ap;
    char msg[LOG_MAX_LEN];

    va_start(ap, fmt);
    vsnprintf(msg, sizeof(msg), fmt, ap);
    va_end(ap);

    myLogger(level, msg);
}

void myLogger(int level, const char* msg)
{
    switch (level)
    {
    
    case logDebug:
        /* code */
        fprintf(stderr, "\033[34m[DEB][%s]\n", msg);
        break;
    case logWarning:
        /* code */
        fprintf(stderr, "\033[35m[WAE][%s]\n", msg);
        break;
    case logError:
        /* code */
        fprintf(stderr, "\033[31m[ERR][%s]\n", msg);
        break;
    default:
        break;
    }

    fprintf(stderr, "\033[37m");
}

int main(int argc, char *argv[])
{
    mylogger(0, "hello %s %s -- %s:%d", "world", "!", __FILE__, __LINE__);
    mylogger(1, "world -- %s:%d", __FILE__, __LINE__);
    mylogger(2, "! -- %s:%d", __FILE__, __LINE__);

    return 0;
}