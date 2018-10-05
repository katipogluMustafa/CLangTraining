#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

	int num, i ,*ptr, sum = 0;

	printf("Number of elements inside of the array: ");
	scanf("%d", &num);

	ptr = (int*) calloc(num, sizeof(int));
	if (ptr == NULL){
		printf("Error!, memory not allocated.");
		exit(0);
	}	

	printf("Enter elements of the array: \n");

	for(i = 0; i < num; i++){
		printf("Element number %d: ", i);
		scanf("%d", (ptr + i));
		sum += *(ptr + i);
	}

	printf("Sum: %d\n", sum);

	free(ptr);
	return 0;
}