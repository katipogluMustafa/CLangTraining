#include<stdio.h>

#define MIN(a,b) ( (a) < (b) ? (a) : (b) )

int main(){
	int b=MIN(MIN(3,4),2);

	printf("%d", b);

	return 0;
}