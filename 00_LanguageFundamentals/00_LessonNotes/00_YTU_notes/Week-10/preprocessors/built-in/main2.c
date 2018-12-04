#include<stdio.h>
#define CHECK(a,b)  					\
	if( (a) != (b) )				\
		fail(a,b,__FILE__,__LINE__)						


void fail(int a, int b, char*p, int line){
	printf("Check failed in file %s at line %d\n",p, line);
}


int main(){

	CHECK(5,7);

	return 0;
}
