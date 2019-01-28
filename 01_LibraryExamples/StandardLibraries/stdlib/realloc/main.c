#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	int *ptr, i, n1, n2;

	printf("Size of the array: ");
	scanf("%d",&n1);


	ptr = (int*) malloc(n1 * sizeof(int));

	printf("Address of previously allocated memory: ");
	for(i = 0; i < n1; i++){
		printf("%p\t", ptr + i);
	}

	printf("\nNew Array Size: ");
	scanf("%d", &n2);

	/* Change allocated memory size using realloc() */
	ptr = realloc(ptr, n2 * sizeof(int));
	printf("\t\t\t\t");
	for(i = 0; i < n2; i++){
		printf("%p\t",ptr + i);
	}

	printf("\n");
	return 0;
}