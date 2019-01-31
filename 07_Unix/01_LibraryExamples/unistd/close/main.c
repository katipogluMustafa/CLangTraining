#include<fcntl.h>   // open
#include<unistd.h>  // close
#include<stdio.h>   

int main(){
   int fd = open("textfile.txt", O_WRONLY | O_CREAT);
   if( fd == -1)
        return 1;
   if( close(fd) == -1 )    
        return 1;

return 0;
}
