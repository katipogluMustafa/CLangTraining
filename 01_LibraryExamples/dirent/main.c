#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<errno.h>
#include<signal.h>
#include<dirent.h>

/* examples of ls implementation*/

void err_sys(char* fmt, ...);
void err_quit(char* msg);

int main(int argc, char* argv[]){
  DIR* dp;
  struct dirent *dirp;
 
  if( argc != 2 )
   err_quit("usage: ls directory_name");
  
  if( ( dp = opendir(argv[1]) ) == NULL)
    err_sys("can't open %s", argv[1]);
  
  while( (dirp = readdir(dp)) != NULL  )
    printf("%s\n", dirp->d_name);

  closedir(dp);
return 0;
}

void err_quit(char* msg){
  fprintf(stderr, "%s: %s", msg, strerror(errno));
  exit(1);
}

void err_sys(char* fmt, ...){
  va_list argList;
  va_start(argList, fmt);
  
  int d;
  char c;
  char* s;
  int flag = 0;
  while(*fmt){
    
    if(flag){
      switch(*fmt){
        case 's':
          	s = va_arg(argList, char*);
          	fprintf(stderr, "%s", s);
          	break;
       case 'd':
          	d = va_arg(argList, int);
          	fprintf(stderr, "%d", d);
          	break;
       case 'c':
          	c = (char)va_arg(argList,int);
          	fprintf(stderr, "%c", c);
          	break;
       case '\n':
          	fprintf(stderr, "\n");
          	break;
       case '\t':	
          	fprintf(stderr,"\t");
          	break;
       default:
          	break;
      }
    }else{
         
      if( *fmt == '%')
        flag = 1;
      else{
        flag = 0;
        fprintf(stderr, "%c", *fmt);
      }

    }

    fmt++;
  }
  va_end(argList);
  raise(SIGSYS);
}
