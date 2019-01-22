#include<stdio.h>
#include<unistd.h>  // for exec() functions
#include<string.h>  // strerror() function
#include<errno.h>   // for errno variable

int main(){
  if( execl( "/sbin/ifconfig", "/sbin/ifconfig",NULL )  == -1 ){
  	if(execlp("ipconfig","ipconfig",NULL) == -1 ){
		fprintf(stderr, "Cannot run ifconfig: %s", strerror(errno));
	}
  }

return 0;
}
