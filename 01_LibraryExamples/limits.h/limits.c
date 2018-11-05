#include <limits.h>
#include <stdio.h>

int main(){
	printf("unsigned long int'in araligi: 0-%1u\n",ULONG_MAX);
	printf("long int araligi: %ld-%lld\n",LONG_MIN,LONG_MAX);
	printf("unsigned int araligi: 0-%d\n",UINT_MAX);
	printf("int araligi: %d-%d\n",INT_MIN,INT_MAX);
	printf("short int araligi: %d-%d\n",SHRT_MIN,SHRT_MAX);
	printf("Char araligi: %d-%d\n",CHAR_MIN,CHAR_MAX);
	printf("unsigned char araligi: 0-%d\n",UCHAR_MAX);
}
