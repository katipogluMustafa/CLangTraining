#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	char *s1 = "1234560";
	char *s2 = "abcdeeee";
	char *s3 = malloc(strlen(s1) + strlen(s2) + 1);


	if(s3 != NULL) {
		strcpy(s3,s1);
		strcat(s3,s2);

		puts(s1);
		puts(s2);
		puts(s3);
	}

	free(s3);

	return 0;
}