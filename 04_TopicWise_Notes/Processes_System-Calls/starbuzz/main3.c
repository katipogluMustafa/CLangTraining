#include<string.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>

int main(int argc, char* argv[]){

  if( execl("./coffee",   "./coffee", NULL ) == -1 ) 
    fprintf(stderr, "Can't run process 0: %s \n", strerror(errno)); 

  return 1;
}
