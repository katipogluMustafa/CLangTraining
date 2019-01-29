#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFSIZE 4096
#define MAXLINE 4096            /* max line length */

/* ./a.out < infile > outfile */

void err_sys(const char *fmt, ...);
static void err_doit(int errnoflag, int error, const char *fmt, va_list ap);

int main(void){
  int n;
  char buf[BUFFSIZE];

  while( (n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0 )
    if( write(STDOUT_FILENO, buf, n) != n )
      err_sys("write error");
  
  if( n < 0)
    err_sys("read error");
  
  exit(0);
}

/*
 * Fatal error related to a system call.
 * Print a message and terminate.
 */
void err_sys(const char *fmt, ...){
    va_list     ap;
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}

/*
 * Print a message and return to caller.
 * Caller specifies "errnoflag".
 */
static void err_doit(int errnoflag, int error, const char *fmt, va_list ap){
    char buf[MAXLINE];

    vsnprintf(buf, MAXLINE-1, fmt, ap);
    if (errnoflag)
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1, ": %s",
          strerror(error));
    strcat(buf, "\n");
    fflush(stdout);     /* in case stdout and stderr are the same */
    fputs(buf, stderr);
    fflush(NULL);       /* flushes all stdio output streams */
}
