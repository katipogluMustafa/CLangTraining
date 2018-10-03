#include <stdio.h>

int main(){

	char name[30];
	printf("Enter a name: ");
	gets(name); // function to read string from user
	printf("Name: ");
	puts(name); // function to display string

	return 0;
}