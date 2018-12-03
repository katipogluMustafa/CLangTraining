#include<stdio.h>


int main(){
  // __FILE__   --> Name of the source file from which call was made
  // __LINE__   --> Line number of the call
  
  #define msg(fmt, ...) printf("%s %d"#fmt, __FILE__, __LINE__, __VA_ARGS__);
 
  msg("%s %s %s","Error", "Happened", "Here");

return 0;
}


