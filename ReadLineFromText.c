#include<stdio.h>
#include<stdlib.h>

int main(){
FILE *fptr;
int i;
char line[150];
fptr=fopen("Asaf.txt","r");

if(fptr==NULL){
perror("Oh dear Sorry!");
return -1;
}


fscanf(fptr,"%[^\n]",line);
printf("Data comes from file: %s\n",line);
fclose(fptr);



return 0;

}
