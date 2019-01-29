#include <stdio.h>

int main(int argc, char *argv[]){

	/* Using getchar() function. */

	char c;

	printf("Enter a character: ");
	c = getchar();

	printf("Character entered: ");
	putchar(c);
	printf("\n");
	return 0;

}

/* The difference between getc() and getchar() is getc() can read from any input stream, but getchar() reads from standard input. So getchar() is equivalent to getc(stdin).*/
