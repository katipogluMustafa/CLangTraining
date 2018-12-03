#include<stdio.h>

int main(){
  /*
  int p = 5;

  int* x,y;	// This declares int* x, int y -- Be careful !

  x = &p;
  y = &p;

  printf("%d %d", *x, *y); 
  */

  int p = 5;
  int* x,y;
  x = &p;
  y = p;

  printf("%d %d", *x, y);

  // If you wanna declare both of them as pointers
  int *z, *k;
  z = NULL;
  k = NULL;
return 0;
}
