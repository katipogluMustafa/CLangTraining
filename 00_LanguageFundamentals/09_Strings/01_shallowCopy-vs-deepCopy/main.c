#include <stdio.h>
#include <string.h>

typedef struct {
	char *name;
	int value;
} Node;

int main(int argc, char *argv[]){


	Node n1,n2,n3;

	char name[] = "This is the name";

	n1 = (Node){name, 1453};

	n2 = n1; // Shallow copy, n2.name points to the same string as n1.name

	printf("\nShallow Copy\n");
	printf("%p\n",n1.name);
	printf("%p\n",n2.name);

	n3.value = n1.value;
	memcpy(n3.name, n1.name, sizeof(name) / sizeof(char));
	
	// Fix the segmentation İssue
	printf("\nDeep Copy\n");
	printf("%p\n",n1.name);
	printf("%p\n",n3.name);
}

/*
 * A shallow copy in this particular context means that you copy "references" (pointers, whatever) to objects, 
 * and the backing store of these references or pointers is identical, 
 * it's the very same object at the same memory location.
 */

/*
 * A deep copy, in contrast, means that you copy an entire object (struct). 
 * If it has members that can be copied shallow or deep, you also make a deep copy of them.
 */