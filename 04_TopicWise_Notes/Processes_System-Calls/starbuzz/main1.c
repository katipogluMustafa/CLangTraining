#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>

int main(int argc, char* argv[]){

  char* my_env[] = {"FOOD=coffee", NULL};
  if( execle("./coffee",   "./coffee",  "donuts", NULL, my_env ) == -1 ){
    fprintf(stderr, "Can't run process 0: %s \n", strerror(errno)); 
  }

  return 1;
}
