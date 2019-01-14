#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Type Declerations

typedef struct{
	char* field;
} XYZ;

// Prototypes

char* StringDonenFonksiyon();
char* stringUydur(int n);
XYZ* XYZFactory(char*);

// Test Code

int main(){

	printf("%s\t", "Mustafa");
	printf("%lu\n", strlen("Mustafa") );

	printf("%s\t", StringDonenFonksiyon() );
	printf("%lu\n", strlen( StringDonenFonksiyon() ) );

	char* myStr = stringUydur(25);
	printf("%s\t", myStr );
	printf("%lu\n", strlen( stringUydur(25) ) );

	XYZ mySample;
	mySample.field = "Mustafa";

	printf("%s\t", mySample.field );
	printf("%lu\n", strlen( mySample.field ) );

	XYZ* otherSample = XYZFactory("Mustafa");
	printf("%s\t", otherSample->field);
	printf("%lu\n", strlen( otherSample->field ) );

	// Using in declaration
	char str1[] = "let the sentece begin...", str2[] = "let the sentence end...";
	char str3[strlen(str1) + strlen(str2) - 1];


	return 0;
}

// Functions

char* StringDonenFonksiyon(){
	char* str = (char*)malloc( 8 * sizeof(char) );
	strcpy(str, "mustafa");

	return str;
}


char* stringUydur(int n){
	char* str = (char*)malloc( (n+1) * sizeof(char) );
	
	if( n == 0){
		return NULL;
	}

	strcpy(str, "a");
	n--;

	while(n--){
		strcat(str, "b");
	}

	return str;
}

XYZ* XYZFactory(char* str){
	XYZ* sample = (XYZ*)malloc( sizeof(XYZ) );
	sample->field = (char*)malloc( ( strlen(str) + 1 ) * sizeof(char) );
	strcpy(sample->field, str);

	return sample;
}
