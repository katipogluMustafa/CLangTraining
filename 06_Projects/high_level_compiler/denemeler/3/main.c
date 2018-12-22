#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define N 100
#define BEGIN "{"
#define END "}"
#define BEGIN_PARAMETER "("
#define END_PARAMETER ")"
#define PRINT_LINE "printf(\"%s\","
#define GET_VAL "scanf("


int main(){

	FILE* in = fopen("in.txt","r");
	FILE* out = fopen("out.txt","w+");
	char tmp;
	char buffer[N];
	int i = 0;

	/* GET_VAL */

	fgets(buffer,100,in);

	printf("%s\n",buffer);
	char* ptr;
	if( ( ptr = strstr(buffer, "GET_VAL") ) != NULL  ){
		fprintf(out,"%s", GET_VAL);
		fprintf(out,"%s", ptr + strlen("GET_VAL") );
		fprintf(out,"%s", END_PARAMETER );
			
	}




	return 0;
}

char* deleteQuotes(char* src){
	char* tmp = (char*)malloc( strlen(src) * sizeof(char) );
}