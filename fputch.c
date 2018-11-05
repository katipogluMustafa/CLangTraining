#include<stdio.h>
#include<string.h>

int main(){
int i;
char a[100];
char ch;
FILE *fptr;

fptr=fopen("Asaf.txt","w+");

//fgetc(15);
for(i=0;i<15;i++){
scanf("%c",&ch);

fputc(ch,fptr);
}
fclose(fptr);





return 0;
}
