#include "__HEADER__.h"

int main(int argc, char* argv[]){

	if( !strcmp(argv[1],"TRUE" ) ){
		printf("True");
	}else if( !strcmp(argv[1], "FALSE") ){
		printf("False\n");
	}else{
		printf("Nope\n");
	}

	return 0;
}

/* 
 * Run by sending parameter.
*/