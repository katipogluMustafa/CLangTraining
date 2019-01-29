#include <stdio.h>

size_t strlen(char*);

int main(){

	printf("strlen: %lu\n",strlen("mustafa"));

}


size_t strlen(char* str){
	char* temp = str;
	size_t sayac = 0;

	while(*temp++)
		sayac++;

	return sayac;
}