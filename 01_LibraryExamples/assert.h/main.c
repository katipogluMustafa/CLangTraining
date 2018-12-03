#include<stdio.h>
#include<assert.h>

int main( void ){
  int *p = NULL;
  
  assert(p != NULL); // if condition true just continue
		     // if condition false, exit the program
  printf("%d", *p);

return 0;
}
