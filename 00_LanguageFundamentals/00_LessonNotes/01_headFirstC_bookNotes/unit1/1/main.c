#include<stdio.h>
#include<string.h>

int main(void){
	char name[20];
	
	printf("What's your name?: ");
	scanf("%19s",name); 				// just takes 19 characters

	char message[23] = "Hi";
	strcat(message, " ");
	strcat(message, name);

	puts(message);

	return 0;
}