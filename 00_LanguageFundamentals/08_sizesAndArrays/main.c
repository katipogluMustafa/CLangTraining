#include <stdio.h>

int main(int argc, char *argv[]){

	int areas[] = { 10, 12, 14, 20};

	char name[] = "Zed";

	char full_name[] = {

		'M', 'u', 's', 't', 'a', 'f', 'a',
		'K', 'a', 't', 'i', 'p', 'o', 'g', 'l', 'u','\0'
	};

	printf("Size of an int: %ld\n", sizeof(int));
	printf("Size of The Areas: (int[]): %ld\n", sizeof(areas));
	printf("Number of ints in areas: %ld \n", sizeof(areas)/ sizeof(int) );
	printf("Size of a char %ld\n", sizeof(char));
	printf("Size of the name(char[]): %ld\n",sizeof(name));
	printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));
	printf("Size of full_name(char[]): %ld\n", sizeof(full_name));
	printf("The Number of chars: %ld\n", sizeof(full_name) / sizeof(char) );

	return 0;
}