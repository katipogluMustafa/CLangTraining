#include <stdio.h>

int strlen1(char str[]);
int strlen2(char str[]);
int strlen3(char* str);

int main(){
	printf("strlen1: %d\n",strlen1("mustafa"));
	printf("strlen2: %d\n",strlen2("mustafa"));
	printf("strlen3: %d\n",strlen3("mustafa"));
}

int strlen1(char str[]){
	int i = 0;
	while(str[i])
		i++;

	return i;
}


int strlen2(char str[]){
	int i;
	for(i = 0; str[i]; i++);

	return i;	
}

int strlen3(char* str){
	int i;
	for(i = 0; *str++ ; i++);

	return i;
}

/*
 * The expression *str++ illustrates a common idiom in C. 

 * Since the ++ operator has the same precedence as the * operator, associativity rules take effect. Both operators
bind from right to left, so the expression causes the compiler to:

1. Evaluate the post-increment (++) operator. Because ++ is a
post-increment operator, the compiler passes str to the next operator
but makes a note to increment str after the entire expression is
complete.
2. Evaluate the indirection (*) operator, applied to str.
3. Complete the expression by incrementing str.
 */