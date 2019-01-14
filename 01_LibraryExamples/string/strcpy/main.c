#include <stdio.h>
#include <string.h>

int main(){
	char src[40];
	char dest[50];

	memset(dest, '.', sizeof(dest));
	printf("\nBefore Copy %s\n", dest);

	strcpy(src, "This is tutorialspoint.com");
   	strcpy(dest, src);

  
   	printf("Final copied string : %s\n\n", dest);
   	
  
	return(0);
}
