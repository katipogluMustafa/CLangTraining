#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int bool;
#define TRUE  (1)
#define FALSE (0)

typedef struct{
	char* w_data;
} WORD;

typedef struct{
	WORD* s_data;
	int numOfWords;
} Sentence;

void fillTheFileAsText(FILE* fp);

Sentence splitStrinAsSentence(char* str);

int main(void){

	FILE* fp = fopen("text.txt", "a+");

	fillTheFileAsText(fp);

	fclose(fp);

	return 0;
}

void fillTheFileAsText(FILE* fp){
	int n,input,i,j,k;

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

	Sentence* paragraph = (Sentence*)malloc( sizeof(Sentence) * n ); 


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

		/* We got the sentece we need to get each word
		 * and save it into the sentence. */

		paragraph[i] = splitStrinAsSentence(buffer);



		// Make the buffer pointer points to 
		// the first element of buffer
		bufferPointer = 0;
	}


	fwrite(paragraph, sizeof(Sentence), n,fp);


	free(buffer);
	bufferSize = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < paragraph[i].numOfWords; j++){
			free(paragraph[i].s_data[j].w_data);
		}
		free(paragraph[i].s_data);
	}
	free(paragraph);
}

/* Take string and number of character not included NUL*/
Sentence splitStrinAsSentence(char* str){
	WORD* sentence_data = (WORD*)malloc( sizeof(WORD) * 1);
	int numofWords = 1;
	int wordPointer = 0;
	int characterPointer = 0;
	int i = 0;
	char tmp;

	while( str[i] != '\0' ){
		sentence_data[wordPointer].w_data = (char*)malloc( sizeof(char) * 1 );

	    while( ( sentence_data[wordPointer].w_data[characterPointer++] = str[i++] ) != ' ' ){
	      sentence_data[wordPointer].w_data = (char*)realloc(sentence_data[wordPointer].w_data, sizeof(char) * ( characterPointer + 1 ) );
		  assert(sentence_data != NULL);
		}

		wordPointer++;
		characterPointer = 0;

		sentence_data = (WORD*)realloc(sentence_data, (numofWords + 1) * sizeof(WORD)  );
		assert(sentence_data != NULL);
	}
	Sentence sentence;
	sentence.s_data = sentence_data;
	sentence.numOfWords = wordPointer;

  return sentence;
}