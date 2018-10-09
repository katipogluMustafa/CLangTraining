#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

	char str[4] = "mark";
	int i;

	// strlen() shows length of the string without trailing null.

	for(i = 0; i < strlen(str); i++){
			printf("%c\n", str[i]);
			if(str[i] == '\0'){
				printf("null");
			}else if(str[i] == ' '){
				printf("space");
			}
	}

	printf("***********\n");

	char myStr[5] = "mark";

	for(i = 0; i < strlen(str); i++){
			printf("%c\n", str[i]);
			if(str[i] == '\0'){
				printf("null");
			}else if(str[i] == ' '){
				printf("space");
			}
	}

	printf("***********\n");


	printf("%s\n",str);
	printf("%s\n",myStr);


}