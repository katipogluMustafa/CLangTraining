#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define RATE 2


struct word {
	char* data;
	int size;
};

typedef struct {
	struct word* words;
	int wordCapacity;	
	int currWordIndex;
} Sentence;

int addWordToWords(struct word *words, int* sizeofTheWords, int* currIndexOfTheWords,const char* in);
int addWordToSentence(Sentence* , struct word );
/*
struct paragraph {
	struct sentence* data;
	int paragraph_count;
};
*/

int main(void){

	void printWordArr(const struct word *, int );

	struct word *words;	// Declare Array of words	
	int numOfWordInWords = 4;
	words = (struct word*) malloc( sizeof(struct word) * numOfWordInWords );
	int currIndexOfTheWords = 0;

	addWordToWords(words, &numOfWordInWords, &currIndexOfTheWords ,"MustafaK");
	addWordToWords(words, &numOfWordInWords, &currIndexOfTheWords ,"Mustafa");
	addWordToWords(words, &numOfWordInWords, &currIndexOfTheWords ,"Ahmet");
	addWordToWords(words, &numOfWordInWords, &currIndexOfTheWords ,"Mehmet");
	addWordToWords(words, &numOfWordInWords, &currIndexOfTheWords ,"Yusuf");
	addWordToWords(words, &numOfWordInWords, &currIndexOfTheWords ,"Kerem");


	Sentence sentence;
	sentence.wordCapacity = 2;
	sentence.words = (struct word*) malloc( sizeof( struct word ) * sentence.wordCapacity );
	sentence.currWordIndex = 0;

	addWordToSentence(&sentence, words[1]);
	addWordToSentence(&sentence, words[2]);
	addWordToSentence(&sentence, words[3]);
	addWordToSentence(&sentence, words[4]);
	addWordToSentence(&sentence, words[5]);

	printf("%s", sentence.words[2].data);
	printf("%s", sentence.words[3].data);
	printf("%s", sentence.words[4].data);
	printf("%s", sentence.words[5].data);

	char buffer[1000];
/*
	printf("Type The Sentence: \n\n");

	scanf("%[^\n]%*c",buffer);
	
	// Debug the input
	printf("\n\n%s\n\n",buffer);
*/	int numOfSentences = 2;


}

int addWordToSentence(Sentence* sentence, struct word wrd ){
	// Copy Deep copy of wrd into temp
	struct word* temp = (struct word*)malloc( sizeof(struct word) );
	temp->data = (char*)malloc( wrd.size * sizeof(char) );
	strcpy(temp->data, wrd.data);
	temp->size = wrd.size;

	// If Full
	if(sentence->wordCapacity == sentence->currWordIndex){
		// Expand the sentence
		sentence->words = (struct word*)realloc(sentence->words, RATE * sizeof(struct word) * sentence->wordCapacity);
		if(!sentence->words){
			return 1;
		}
		sentence->wordCapacity = sentence->wordCapacity * 2;
	}

	sentence->words[ sentence->currWordIndex ] = &temp;

	sentence->currWordIndex = sentence->currWordIndex + 1;
	return 0;
}

int addWordToWords(struct word *words, int* sizeofTheWords, int* currIndexOfTheWords,const char* in){

	int expandWordsArray(struct word*, int*);

	if(*sizeofTheWords == *currIndexOfTheWords){
		expandWordsArray(words, sizeofTheWords);
	}

	// Add string 'in' into words array as a word's data.
	words[*currIndexOfTheWords].data = (char*)malloc( sizeof(char) * ( strlen(in) + 1 ) );
	strcpy( words[*currIndexOfTheWords].data, in );

	words[*currIndexOfTheWords].size = strlen(in);
	*currIndexOfTheWords = *currIndexOfTheWords + 1;

	return 0;
}


int expandWordsArray(struct word *words, int* currSize){

	words = (struct word*)realloc(words, *currSize * RATE * sizeof(struct word) );

	// If dummy == NULL
	if(!words){
		return 1;
	}

	*currSize *= 2;

	return 0;
}

void printWordArr(const struct word *words, int size){
	printf("\n\n****Printing\n\n");
	int i;
	for(i = 0; i < size; i++){
		printf("\nWord: %s - Size: %d\n", words[i].data, words[i].size);
	}
}
