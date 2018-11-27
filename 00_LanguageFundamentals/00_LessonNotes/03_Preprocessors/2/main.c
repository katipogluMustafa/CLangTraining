#include<stdio.h>
#define max(a,b) (a > b ? a : b)

int main(){

	printf("%d\n", max(5,10));
	printf("%d\n", max(4+1, 10));			// to omit ambiguities use parentheses.
	
	#undef max
	#define max(a,b) ( (a) > (b) ? (a) : (b) )	// Here we've used parentheses.
	
	printf("%d\n", max(5,10));
	printf("%d\n", max(4 + 1, 10));	

return 0;
}
