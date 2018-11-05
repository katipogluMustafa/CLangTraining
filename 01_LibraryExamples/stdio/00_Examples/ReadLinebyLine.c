#include<stdio.h>
#include<stdlib.h>

int main(){
FILE *fptr;
char line[50];
char str;

fptr=fopen("Asaf.txt","r");
str=fgetc(fptr);

while(str!=EOF){
	printf("%c",str);
	str=fgetc(fptr);

}
printf("\n");
fclose(fptr);



return 0;
}
