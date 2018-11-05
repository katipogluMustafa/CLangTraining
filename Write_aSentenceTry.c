#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
char sentence[50];
FILE *fptr;

fptr=fopen("Asaf.txt","a+");

if(fptr==NULL){
printf("Error!!");
exit(1);
}

printf("Enter a sentence.");
scanf("%[^\n]s",sentence); 

fprintf(fptr,"%s",sentence);

fclose(fptr);





return 0; 
}
