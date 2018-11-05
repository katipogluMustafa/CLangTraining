#include <stdio.h>

int main(){
	FILE* dosya;
	char text[140];
	dosya=fopen("a.txt","a+");
	scanf("%s",text);
	fprintf(dosya,text);
	fclose(dosya);
	return 0;
}
