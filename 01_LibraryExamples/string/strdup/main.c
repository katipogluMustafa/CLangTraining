#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void fillArray(char* arr[], char x[], char y[]);
void printArray(char** arr);

int main()
{
	char x[] =  "Mustafa";
	char y[] =  "Katipoglu";

	char* arr[2];
	fillArray(arr, x, y);
	printArray(arr);
	strcpy(x,"Mert");
	strcpy(y,"Öz");
	printArray(arr);
return 0;
}

void fillArray(char* arr[], char x[], char y[]){
  arr[0] = strdup(x);
  arr[1] = strdup(y);
}

void printArray(char** arr){
  printf("%s %s\n", arr[0], arr[1]);
}
