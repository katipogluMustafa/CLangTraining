#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


int isQuote(char x);
int isAddress(char x);
char* removeChar(char* src, char* pointer);
char* removeAfterwards(char* src, char* pointer);

int isQuote(char x){
	int ret = 0;

	if( x == '"' ){
		ret = 1;
	}

	return ret;
}

int isAddress(char x){
	int ret = 0;

	if( x == '$'){
		ret = 1;
	}

	return ret;
}

char* removeChar(char* src, char* pointer){

	int x = strlen(src) - strlen(pointer);
	char* temp = (char*)malloc( strlen(src) * sizeof(char) );
	
	memcpy(temp, src, x );
	memcpy(temp + x, pointer+1, strlen(pointer) );
	temp[strlen(src) - 1 ] = '\0';

	return temp;
}
void removeCharV2(char* src, char* pointer){

	int x = strlen(src) - strlen(pointer);
	char* temp = (char*)malloc( strlen(src) * sizeof(char) );
	
	memcpy(temp, src, x );
	memcpy(temp + x, pointer+1, strlen(pointer) );
	temp[strlen(src) - 1 ] = '\0';

	free(src);
	src = temp;
}

void removeCharV3(char* src, int index){

	strcpy(src+index, src+index+1);

}

char* removeAfterwards(char* src, char* pointer){

	int x = strlen(src) - strlen(pointer);
	char* temp = (char*)malloc( strlen(src) * sizeof(char) );
	
	memcpy(temp, src, x );
	temp[ x+1 ] = '\0';

	return temp;
}
