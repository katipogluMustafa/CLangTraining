#include<stdio.h>

int main( void ){
  union{
    long long_element;
    float float_element;
  } u;
  long long_var;
  float float_var;

  long_var = u.long_element = 10;
  printf( "The value of lng_var cast to a float is: %f\n", (float)long_var );
  printf( "The value of float element after\n"
	  "assignment to long_element is: %f\n\n", u.float_element );

  float_var = u.float_element = 3.555;
  printf( "The value of flt_var cast to a long is: %ld\n",(long)float_var );
  printf( "The value of long_element after an \n"
	  "assignment to float_element is: %ld\n", u.long_element ); 
return 0;
}

/*
 * In a cast, 
 * the compiler makes every attempt to preserve the true value.
 * 
 * So when casting a long to a float, the compiler simply adds a fractional
part equal to zero.
 * 
 * And when casting a float to a long, the compiler truncates the fractional part.

 * In a union, on the other hand,
 * The compiler ignores the true value -- it is interested only in the bit sequence.
 * The values we receive from the program are machine dependent because they depend
on the way our system stores longs and floats. 

 */
