#include<stdio.h>

int main(){

  #define concat(a,b) a ## b
  int x = concat(3,5);
  printf("x: %d\n", x);
  
  int y = concat(5,3);
  printf("y: %d\n", y);
	
  printf("x + y : %d\n", x + y);
return 0;
}

/*
 * Remember !
 * 
 * The result of concatenation must be a valid token. 
 * 
 * Examples:
 * 
 * concat(x, ++) // Error, you can not concatenate with ++ operator since there is no valid single token as a result.
 * concat(/, *)	 // You can not concatenate to create comment since comments are processed before macros.
 */ 

