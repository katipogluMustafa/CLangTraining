#include<stdio.h>
#include<unistd.h>

int main(void){

  if( lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
    printf("Cannot Seek stdin\n");
  else
    printf("seek OK\n");
  
  if( lseek(STDOUT_FILENO, 0, SEEK_CUR) == -1)
    printf("Cannot Seek stdout\n");
  else
    printf("seek OK\n");

  if( lseek(STDERR_FILENO, 0, SEEK_CUR) == -1)
    printf("Cannot Seek stderr\n");
  else
    printf("seek OK\n");

return 0;
}
