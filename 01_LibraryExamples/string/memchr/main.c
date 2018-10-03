#include <stdio.h>
#include <string.h>

int main(){

	/* In the C Programming Language, 
		the memchr function searches within the first n characters 
		of the object pointed to by s for the character c. 
		It returns a pointer to it.
	*/
	
	/* Syntax: void *memchr(const void *str, int c, size_t n) */

	const char str[] = "http:www.example.com";
	const char ch = '.';
	char *ret;

	ret = memchr(str, ch, strlen(str) );

	printf("String after |%c| is - |%s|\n",ch,ret);

	printf("Length of the ret: %lu\n",strlen(ret) );

	int i;
	for(i = 0; i < strlen(ret); i++){
		printf("%c\n",ret[i]);
	}

	return 0;

}
