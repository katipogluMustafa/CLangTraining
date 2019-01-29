#include <stdio.h>

int main(){

	/* getc */
	// int getc(FILE *stream); 

	/* It reads a single character from a given input stream
	 * returns the corresponding integer value (typically ASCII value of read character) on success. 
	 * It returns EOF on failure. */
	
	printf("Character: ");
	char c = getc(stdin);

	printf("%c\n",c);
	return 0;
}