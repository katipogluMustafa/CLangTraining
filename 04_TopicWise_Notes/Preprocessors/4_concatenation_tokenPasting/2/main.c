#include<stdio.h>

#define tokenDeclarer(n) int token##n
#define tokenAssigner(n) token##n = n
#define tokenpaster(n) printf ("token%d = %d\n",n, token##n)


int main(){
	int i;

	for(i = 1; i < 15; i++){
		tokenDeclarer(i);
		tokenAssigner(i);
		tokenpaster(i);
	
	}
	return 0;
}