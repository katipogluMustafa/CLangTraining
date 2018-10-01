#include <stdio.h>

int main(int argc, char *argv[]){

	int areas[] = { 10, 12, 14, 20};

	char name[] = "Zed";

	char full_name[] = {

		'M', 'u', 's', 't', 'a', 'f', 'a',
		'K', 'a', 't', 'i', 'p', 'o', 'ğ', 'l', 'u', '\0'
	};

	printf("Size of an int: %ld", sizeof(int));
	printf("Size of The Areas: (int[]): %ld\n", sizeof(areas));
	printf("Number of ints in areas: %ld \n", sizeof(areas)/ sizeof(int) );
}