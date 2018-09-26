#include <stdio.h>

struct student {
	char name[50];
	int roll;
	float marks;
} s;

int main(){

	printf("Debugging\n\n");

	printf("Enter Information\n");

	printf("Name: ");
	scanf("%s",s.name);

	printf("\n");

	printf("Enter roll number: ");
	scanf("%d", &s.roll);

	printf("\n");

	printf("Enter marks: ");
	scanf("%f", &s.marks);

	printf("\n");

	printf("Displaying the Information:\n\n");

	printf("Name: ");
	puts(s.name);

	printf("Roll Number: %d\n", s.roll);
	printf("Marks: %.1f\n", s.marks);	

	return 0;
}