#include <stdio.h>

int main(){
	/* Copies n characters from memory area str2 to memory area str1. */
	/* Syntax: void *memcpy(void *str1, const void *str2, size_t n) */

	const char src[50] = "http://www.example.com";
	char dest[50];
	strcpy(dest, "Helloooooooo!!");
	printf("Before memcpy dest = %s \n", dest);
	memcpy(dest, src, strlen(src) + 1 );
	printf("After memcpy dest = %s \n", dest);

	return 0;
}