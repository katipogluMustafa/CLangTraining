#include<stdio.h>
#include<string.h>
#include<assert.h>

int main(){
	FILE* fp = fopen("main.dat","r");
	assert( fp != NULL );

	char buffer[500];
	char subString[50] = "lorem";
	char* pointer;

	while( !feof(fp) ){
		fread(buffer, sizeof(char), 498, fp);
		buffer[499] = '\0';
		pointer = strstr(buffer, subString);
		if( pointer != NULL ){
			FILE* out = fopen("out.dat", "a+b");
			assert( out != NULL);
			fwrite(pointer, sizeof(char), strlen(pointer), out);
			fclose(out);
		}
	}

	fclose(fp);
	return 0;
}