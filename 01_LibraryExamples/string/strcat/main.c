#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){


	/* Syntax: char *strcat(char *dest, const char *src) */
	char str1[] = "let the sentece begin...", str2[] = "let the sentence end...";
	char str3[strlen(str1) + strlen(str2) - 1];


	// Concatenate str1 and str2 and store the result indiside str3.
	strcpy(str3, str1);
	strcat(str3, str2);

	printf("str1: %s\n",str1);
	printf("str2: %s\n",str2);
	printf("str3: %s\n",str3);
	return 0;
}

/*
 * In C the function strcat does not create a new character array containing concatenated strings.
 * It appends characters from the second string to the first string of the first character array provided that it has enough elements to store the new characters. 
 * Otherwise the function will try to overwrite the memory beyond the character array that results in undefined behavior.
 */