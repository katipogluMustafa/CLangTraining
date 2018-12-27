#include<stdio.h>
#include<stdarg.h>

int sum(int num1, ...){
  int total = num1;
  int arg;
  va_list v1; 		// variadic list variable
  va_start(v1, num1); 	// initialize and use variable list
 
  while( ( arg = va_arg(v1,int) ) != 0  ){
	total += arg;
  }

  va_end(v1);		// free up any resources used in the process
 
  
return total;
}

int main(){
 
  printf("sum1: %d\n", sum(3,5,7,8,9,11,0));
  printf("sum2: %d\n", sum(1,2,4,8,16,32,64,128,256,0));

return 0;
}
