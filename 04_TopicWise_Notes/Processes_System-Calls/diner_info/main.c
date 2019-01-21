#include<stdio.h>
#include<unistd.h>

int main(){
  char* my_env[] = {"JUICE=peach and apple",NULL};
  /*
   * execle() will set the command-line arguments and environment variables
   * then replace the current process with diner_info
   */
  execle("diner_info","diner_info","4",NULL,my_env);
return 0;	
}
