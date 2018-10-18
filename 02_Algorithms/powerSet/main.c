#include<stdio.h>  // only IO
#include<stdlib.h> // atoi()
#include<string.h> // strlen()

#define MAX_NUM_OF_DIGITS 64 


// Prototypes
void convertToBinary(char *str, int i);
void Binary(char *str, int i);
void printTheSet(int n, int arr[],char *str);
void Reverse(char *str);
int power(int,int);

int main(){
	int i,n;	

	/* Take Input Set */
		

	int set[MAX_NUM_OF_DIGITS];
	
	printf("Please give the elements of the set\n");
	
	while
	
	for(i = 0; i < n; i++){
		printf("%d.Element: ",i+1);
		scanf("%d",&set[i]);
	}
	char str[MAX_NUM_OF_DIGITS];

	int upperLimit = power(2,n);
	for(i = 0; i < upperLimit-1; i++){
		char str[MAX_NUM_OF_DIGITS];
		convertToBinary(str,i); // Convert i to binary format
		printTheSet(n,set,str);  // Print the set
		printf("\n");
	}

	return 0;
}

void convertToBinary(char *str, int i){
	int j;
	
	// Make Each Item Zero First
	for(j = 0; j < MAX_NUM_OF_DIGITS; j++){
		*str = 0;
		str++;
	}
	

	// Convert to binary
	Binary(str,i); // but the output is reverse

	// Reverse the string

	Reverse(str);
}

void Binary(char *str, int i){

	// Break The Loop
	if(i / 2 == 0){
		*str = i;
		return;
	}

	Binary( str++, (i / 2) );
		
	*str = i % 2;
	return;
}

void Reverse(char *str){
	int i;
	for(i = 0; i < ( MAX_NUM_OF_DIGITS / 2 ); i++ ){
			
			char tmp = *str;
			    *str = *(str + MAX_NUM_OF_DIGITS - i - 1);
	        *(str + MAX_NUM_OF_DIGITS - i - 1) = tmp;
	
	}
}


void printTheSet(int n,int* set,char *str){
	
	// Break the loop
	if(*set == '\0'){
		return;
	}
	
	
	
	printf( "%d ", atoi(&str[0]) * (*set) );	

	str++;
	set++;
	printTheSet( (n-1), set, str );
}

int power(int x, int y){
	int i = x;
	for(i = 1; i <= y; i++){
		i *= x;
	}
	return x;
}
