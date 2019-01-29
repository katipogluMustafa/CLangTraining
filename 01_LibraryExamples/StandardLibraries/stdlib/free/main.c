#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

	char* str1 = "begin-";
	char* str2 = "end";
	char* str3 = malloc(strlen(str1) + strlen(str2) );

	if(str3 != NULL){
		str3 = strcpy(str3,str1);
		str3 = strcat(str3,str2);
	}

	printf("str1: %s\n",str1);
	printf("str2: %s\n",str2);
	printf("str3: %s\n",str3);

	// deallocate the memory previously allocated by malloc.
	free(str3);

	return 0;
}

/* 
 * void free(void *ptr) 
 * deallocates the memory previously allocated by a call to calloc, malloc, or realloc.
 */