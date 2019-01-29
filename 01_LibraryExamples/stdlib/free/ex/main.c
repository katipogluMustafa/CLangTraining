#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	char* str;

	// Initial memory allocation.

	str = (char*)malloc(15);
	strcpy(str, "example.com");
	printf("String: %s, Address: %p\n",str, str);

	// Reallocating memory
	str = (char*)realloc(str,25);
	strcat(str, "/main/stdlib/");
	printf("String: %s, Address: %p\n",str, str);

	// Deallocating allocated memory
	free(str);
		
	printf("String: %s, Address: %p\n",str, str);
	

}