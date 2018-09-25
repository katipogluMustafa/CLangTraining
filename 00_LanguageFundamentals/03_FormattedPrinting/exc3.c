#include <stdio.h>


void example1(){

	int a,b;

	a = 15;
	b = a / 2;

	printf("%d\n",b);
	printf("%3d\n",b);
	printf("%03d\n",b);

 }

 void example2(){
 	float a,b;

 	a = 15.3;
 	b = a / 3;

 	printf("%f\n",b);
 	printf("%.f\n",b);
 	printf("%.3f\n",b);
 	printf("%09.3f\n",b);

 }

 void example3(){
 	printf("The color is %s\n	", "green");
 	printf("Hexadecimal %x\n",245);
 	printf("unsigned value %u\n",150);
 	printf("This one reads percentage sign %%\n ");
 }


void example4(){
	printf(":%s:\n", "Hello, world!");
	printf(":%15s:\n","Hello, world!");
	printf(":%.10s:\n","Hello, world!");
	printf(":%-10s:\n","Hello, world!");
	printf(":%-15s:\n","Hello, world!");
	printf(":%.15s:\n","Hello, world!");
	printf(":%15.10s:\n","Hello, world!");
	printf(":%-15.10s:\n","Hello, world!");	
}

int main(){

	example1();
	printf("\n");

	example2();
	printf("\n");

	example3();
	printf("\n");

	example4();
	printf("\n");

	return 0;
}
