#include <stdio.h>

int main(int argc, char *argv[]){

	/* Illustrates taking a line of string as input. */

	char name[30], ch;
	int i = 0;
	
	printf("Enter a name: ");
	while(ch != '\n'){ // Terminate if the user hit enter

		ch = getchar();
		name[i] = ch;	
		i++;
	}
	name[i] = '\0';
	printf("Name: %s", name);

}
