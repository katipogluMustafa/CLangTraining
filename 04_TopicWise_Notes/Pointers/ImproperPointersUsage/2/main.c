#include<stdio.h>

int main( void ){
  /*
  #define PINT int*

  PINT ptr1, ptr2;	// Be careful, usage of macro makes ptr2 integer not pointer!
 			// int* ptr1, ptr2 is the same as PINT ptr1, ptr2
			// Since this is same is int *ptr1, ptr2...
  
  ptr1 = NULL;
  ptr2 = NULL;		// Can not assign NULL to an integer without a cast!
  */

  // Use typedef instead of macro to define types!
  
  typedef int* PINT;
  PINT ptr1, ptr2;
  
  ptr1 = NULL;
  ptr2 = NULL;


return 0;
}
