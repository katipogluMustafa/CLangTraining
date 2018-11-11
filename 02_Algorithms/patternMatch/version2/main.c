#include <stdio.h>
#include <string.h>

int pattern_match(char* str1, char* str2);



int main(){
	char str[100];
	char pattern[99];

	printf("String: ");
	gets(str);

	printf("Pattern: ");
	gets(pattern);

	int output = pattern_match(str,pattern);

	if(output >= 0){
		printf("%d\n",output);
	}else{
		printf("We couldn't find exact pattern...");
	}
}

int pattern_match(char* str1, char* str2){

	char *p, *q, *substr;

	// Iterate for each character position in str1

	for(substr = str1; *substr;substr++){
		p = substr;
		q = str2;
		int i = 0;
		/* see if it match */
		while(*q){
			if(*q++ != *p++){
				break;
			}
			i++;
		}

		if(strlen(str2) == i){
			return substr - str1;
		}
	}

	return -1;
}
