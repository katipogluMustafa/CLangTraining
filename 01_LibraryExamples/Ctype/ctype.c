#include <ctype.h>
#include <stdio.h>
#define size 6
int main(){
	int a='3';
	char b='b';
	char c='\n';
	int z;
	char str[3]="abc";
	char str2[3]="cba";
	if(isdigit(a)) printf("%c is digit\n",a);
	if(!isdigit(b)) printf("%c is not digit\n",b);
	if(iscntrl(c)) printf("%c is control\n",c);
	if(islower('c')) printf("c is lowercase\n");
	if(isupper('C')) printf("C is uppercase\n");

}
