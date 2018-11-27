#include<stdio.h>

union u{

	struct{
		char f1,f2;
		short f3;
	}s;
	unsignedd char f4[6];

}

int main(){

	union u test = {1,2,3,4,5,6};

	printf("%d %d %d \n", test.s.f1, test.s.f2, test.s.f3);		// 1 2 3

	printf("%d %d %d %d %d %d", test.f4[0],test.f4[1],test.f4[2],test.f4[3],test.f4[4],test.f4[5]);		// 1 2 3 0 0 0


	union u test1 = { .f4{1,2,3,4,5,6} };

	printf("%d %d %d \n", test1.s.f1, test1.s.f2, test1.s.f3);		// 1 2 3

	printf("%d %d %d %d %d %d", test1.f4[0],test1.f4[1],test1.f4[2],test1.f4[3],test1.f4[4],test1.f4[5]);		// 1 2 3 0 0 0


	return 0;
}

