#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define N 100
#define BEGIN "{"
#define END "}"
#define BEGIN_PARAMETER "("
#define END_PARAMETER ")"
#define PRINT_LINE "printf(\"%s\","

int main(){

	FILE* in = fopen("in.txt","r");
	FILE* out = fopen("out.txt","w+");
	char tmp;
	char buffer[N];
	int i = 0;

	/* PRINT_LINE */

	fgets(buffer,100,in);

	printf("%s\n",buffer);
	char* ptr;
	if( ( ptr = strstr(buffer, "PRINT_LINE") ) != NULL  ){
		fprintf(out,"%s", PRINT_LINE);
		fprintf(out,"%s", ptr + strlen("PRINT_LINE") );
		fprintf(out,"%s", END_PARAMETER );
			
	}




	return 0;
}