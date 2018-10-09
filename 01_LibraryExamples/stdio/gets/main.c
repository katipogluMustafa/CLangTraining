#include <stdio.h>
	
	/* 
	char *gets(char *str)
	*/
	
int main(){

	char str[50];
	printf("Input:");
	// Reads a line from stdin abd stores it into the string pointed by str
	gets(str);

	printf("Input: %s\n",str);

	return 0;
}