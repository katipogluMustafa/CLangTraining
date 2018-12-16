#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int main( int argc, char* argv[] ){

  printf("argc: %d\n\n", argc);

  // if there is no argument, give error, otherwise continue
  assert(argc >= 2);
  
  int i = 0;
  while(i < argc){
  	printf("argv[%d] = %s\n",i , argv[i]);
  	i++;
  }
  

return 0;
}
