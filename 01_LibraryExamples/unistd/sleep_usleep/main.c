#include<stdio.h>
#include<unistd.h>

int main(){

  printf("First String\n");
  sleep(5); 			// sleep for 5 seconds
  printf("Second String\n");
  usleep(1000000); 		// sleep for 1 million microseconds which is equal to 1 seconds
  printf("Third String\n");

return 0;
}

/*
 * usleep function's arguman shouldn't be greater than 1 million.
 * If you have alarm, be careful sleep may broke your alarm.
 */
