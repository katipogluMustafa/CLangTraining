#include <stdio.h>

int main(int argc,char *argv[]){

	/* This is a shortcut in C. If you set just one element, it’ll fill in the rest with 0.*/
	int numbers[4] = { 0 };

	char name[4] = { 'a' };

	printf("Print - 1 \n");
	printf("%d%d%d%d\n",numbers[0],numbers[1],numbers[2],numbers[3]);
	printf("%c%c%c%c\n",name[0],name[1],name[2],name[3]);
	printf("%s\n",name);

	// Let's set up the numbers

	int i;
	for(i = 0; i < 4; i++){
		numbers[i] = i;
	}

	// Let's set up the name too
	
	name[0] = 'A';
	name[1] = 'l';
	name[2] = 'i';
	name[3] = '\0';

	printf("\nPrint - 2 \n");
	printf("%d%d%d%d\n",numbers[0],numbers[1],numbers[2],numbers[3]);
	printf("%c%c%c%c\n",name[0],name[1],name[2],name[3]);
	printf("%s\n",name);

	// Another way

	char *another = "Mustafa";

	printf("%s\n",another);
	printf("another each: %c%c%c%c%c%c%c%c\n",another[0],another[1],another[2],another[3],another[4],another[5],another[6],another[7]);

	return 0;
}
/*
 * When you make string literals you should typically use the char *another = "Literal" syntax. 
 * it’s more idiomatic and easier to write.
 */ 