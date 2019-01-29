#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include"apue.h" 	// for error functions

int main(void){

/* od -c file.hole to see content of the file */

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int fd;

if( ( fd = creat("file.hole", FILE_MODE) ) < 0 )
  err_sys("creat error");

if( write(fd, buf1, 10 ) != 10  )
  err_sys("buf1 write error");
/* offset is now 10 */

if( lseek(fd, 16384, SEEK_SET ) == -1)
  err_sys("lseek error");
/* offset is now 16384 */

if( write(fd, buf2, 10) != 10 )
  err_sys("buf2 write error");
/* off set is now 16394*/

exit(0);

}
