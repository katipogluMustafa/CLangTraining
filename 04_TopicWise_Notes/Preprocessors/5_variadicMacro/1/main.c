#include<stdio.h>

int main(){
  int errno = 101;
  int newErrno = 102;
 
  // More Portable Way -->

  #define err(...) fprintf(stderr, __VA_ARGS__)
  err("%s %d\n", "Error: ",errno);
  
  // Less Portable Way -->
  
  #define newErr(myArg...) fprintf(stderr, myArg)
  newErr("%s %d \n","New Error: ", newErrno);

  // By Using Format String
  #define ferr(fmt,arg...) fprintf(stderr, fmt, arg)  // This way requeires at least one argument after format string.
  ferr("%s %d\n", "Ferror: ", 25);
  // ferr("merhaba");  // does not work since we hate to have at least one argument
  
return 0;
}
