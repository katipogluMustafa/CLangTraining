#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	int num, i, *ptr, sum = 0;

	printf("Number of elements: ");
	scanf("%d",&num);

	ptr = (int*) malloc(num * sizeof(int)); // memory allocated using malloc

	if(ptr == NULL){
		printf("Error!, memory not allocated.");
		exit(0);
	}

	printf("Enter Elements of the Array: \n");

	for(i = 0; i < num; i++){
		printf("%d: ",i);
		scanf("%d", (ptr + i) );
		sum += *(ptr + i);
	}

	printf("Sum: %d\n",sum);
	free(ptr);
	return 0;
}
