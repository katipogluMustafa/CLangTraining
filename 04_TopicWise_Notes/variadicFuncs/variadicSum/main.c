#include<stdio.h>
#include<stdarg.h>

int sum(int count, ...){
  int total = 0, i;

  va_list v1; 		// variadic list variable
  va_start(v1, count); 	// initialize and use variable list

  for(i = 0; i < count; i++)
	total += va_arg(v1,int);
  va_end(v1);		// free up any resources used in the process

  
return total;
}

int main(){
 
  printf("sum1: %d\n", sum(6,   3,5,7,8,9,11));
  printf("sum2: %d\n", sum(9,   1,2,4,8,16,32,64,128,256));

return 0;
}
