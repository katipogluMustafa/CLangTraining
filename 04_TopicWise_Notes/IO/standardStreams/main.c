#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(){
	int n,input,i;

	char* buffer;
	int bufferSize;
	int bufferPointer = 0;	// Points to the first empty spot

	fprintf(stdout, "Number Of Sentence You want to write:");
	
	/* scanf("%d", &n); */
	n  = 0;
	while( ( input = fgetc(stdin) ) != '\n'){
		input = input - '0';
		n *= 10;
		n += input;
	}
	
	/* printf("%d",n); */	
	fprintf( stdout,"n: %d\n", n );

	/* Dynamically Take n different Sentences */
	for(i = 0; i < n; i++){
		// read string character by character
		// if the given string has more length than buffer
		// expand buffer
		buffer = (char*)malloc( sizeof(char) * 2 );
		bufferSize = 2;

		while( ( input = fgetc(stdin) ) != '\n'  ){
		  if(bufferSize == bufferPointer){
		    buffer = (char*)realloc(buffer, sizeof(char) * 2 * bufferSize );
		    bufferSize *= 2;
		    assert(buffer != NULL);
		  }
   		  buffer[bufferPointer] = input;	
		  bufferPointer++;
		}
		buffer[bufferPointer] = '\0';

		printf("%s\n", buffer);

		// Make the buffer pointer points to 
		// the first element of buffer
		bufferPointer = 0;
	}

	free(buffer);
	bufferSize = 0;


return 0;
}
