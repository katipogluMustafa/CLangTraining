#include<stdio.h>
#include<string.h>

#define N 100

int main(){
	int isQuote(char);
	void removeChar(char*, int);
	void removeString(char* src, char* str);
	void removeChars(char* src, char c);
	void removeQuotes(char* src);
	
	FILE* in = fopen("in.txt","r");
	FILE* out = fopen("out.txt","w+");
	char tmp;
	char buffer[N];
	int i = 0;

	/* PRINT_LINE */

	fgets(buffer,100,in);

	printf("%s\n",buffer);

	char* ptr;
	if( ( ptr = strstr(buffer, "GET_VAL" ) ) != NULL  ){
		
		removeString(buffer, "GET_VAL");
		removeChars(buffer, ' ');
		removeString(buffer, "_i");
		removeQuotes(buffer);

		if( ptr = strstr(buffer, "$") ){
			removeChar(buffer, ptr - buffer);
		}

	}

	printf("%s",buffer);
	

	return 0;
}

int isQuote(char x){
	int ret = 0;

	if( x == '"' ){
		ret = 1;
	}

	return ret;
}
void removeQuotes(char* src){
	char* first = src;
	char* last  = src + strlen(src) - 1;  

	while( isQuote(*first++) );
	while( isQuote(*last--) );

	if(last != first){

		strcpy(first, first + 1 );
		strcpy(last - 1, last);

	}else{
		printf("Odd number of quotes!");
	}

}

void removeChars(char* src, char c){
	void removeChar(char*, int);

	char* temp = src;

	while( *temp ){

		if(*temp == c){
			removeChar(src, temp-src);
		}

		temp++;
	}

}

void removeChar(char* src, int index){

	strcpy(src+index, src+index+1);

}

void removeString(char* src, char* str){
	char* ptr;
	if( ( ptr = strstr(src,str) ) != NULL ){
		strcpy(ptr, ptr + strlen(str) );
	}

}