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