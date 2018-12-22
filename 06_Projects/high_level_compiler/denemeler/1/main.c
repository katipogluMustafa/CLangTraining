#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define N 100
#define BEGIN "{"
#define END "}"
#define BEGIN_PARAMETER "("
#define END_PARAMETER ")"

int main(){

	FILE* in = fopen("in.txt","r");
	FILE* out = fopen("out.txt","w+");
	char tmp;
	char buffer[N];
	int i = 0;

	/* BEGIN */

	fgets(buffer,100,in);

	printf("%s",buffer);
	
	if( strcmp(buffer, "BEGIN") ){
		fprintf(out,"%s",BEGIN);
	}

	/* END */

	fgets(buffer,100,in);

	printf("%s",buffer);
	
	if( strcmp(buffer, "END") ){
		fprintf(out,"%s",END);
	}

	/* PROCEDURE MAIN */

	fgets(buffer,100,in);
	printf("%s",buffer);

	char* ptr;
	char name[20];
	if( ( ptr = strstr(buffer, "PROCEDURE") ) != NULL ){
		strcpy( name , ptr + strlen("PROCEDURE")  );	
		fprintf(out,"\n%s",name);
	}


	return 0;
}