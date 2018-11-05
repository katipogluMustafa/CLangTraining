#include<stdio.h>

int main(){


int x,y;

	printf("Value of x: ");
 	x = getchar();

	printf("\nNow, x is equal to ");
	putchar( x );
	
	printf("\nSize of x:%d is %lu\n", x ,sizeof(x) ); // you get different number here because we try to print all the number but we just assign the last byte of it


	printf("\n\n");
	

	printf("Value of y: ");
	scanf("%d",&y);

	printf("\nNow, y is equal to ");
	putchar(y);					// trying to print out the last byte of the y so it is errenous
	
	

	printf("\nSize of y:%d is %lu\n", y , sizeof(y) );	

return 0;
}

/*

 * Note, getchar just gets the first digit in this case
    and  putchar just puts the first digit of the number even if it is greater than just one digit

 */
