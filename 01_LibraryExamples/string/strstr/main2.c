#include<stdio.h>

int main(){
	
	char x[20] = "Mustafa";
	char y[20] = "afa";
	
	if( strstr(y,x) != NULL ){
		printf("Başarıyla Bulundu!!!\n");
	}
	
	
	return 0;
}