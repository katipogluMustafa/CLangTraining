#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	void toLower(char str[]);
	void toUpper(char str[]);
	void toCamelCase(char str[]);
	char buffer[100];

	FILE* fp = fopen("main.txt","r");
	if(!fp){
		perror("Error!");
		exit(0);
	}

	fgets(buffer,99,fp);

	toLower(buffer);
	printf("%s\n",buffer);

	toUpper(buffer);
	printf("%s\n",buffer);

	fclose(fp);
	return 0;
}


void toLower(char str[]){
	int i;
	for(i = 0; str[i]; i++){
		str[i] = tolower(str[i]);
	}
}

void toUpper(char str[]){
	int i;
	for(i = 0; str[i]; i++){
		str[i] = toupper(str[i]);
	}
}
