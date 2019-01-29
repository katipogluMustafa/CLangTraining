#include <limits.h>
#include <stdio.h>

int main(){
	printf("unsigned long int'in araligi: 0-%lu\n",ULONG_MAX);
	printf("long int araligi: %li-%li\n",LONG_MIN,LONG_MAX);

	printf("unsigned int araligi: 0-%u\n",UINT_MAX);
	printf("int araligi: %d-%d\n",INT_MIN,INT_MAX);

	printf("Unsigned short araligi: 0-%hu\n",USHRT_MAX);		
	printf("short int araligi: %hi-%hi\n",SHRT_MIN,SHRT_MAX);
	
	printf("unsigned char araligi: 0-%u\n",UCHAR_MAX);
	printf("Char araligi: %d - %d\n",CHAR_MIN,CHAR_MAX);	
}
