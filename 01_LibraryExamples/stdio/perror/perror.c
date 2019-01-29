#include<stdio.h>

int main(){
FILE *fp;
rename("Asaf.txt","Asaf2.txt");//rename the file if it is exist.

fp=fopen("Asaf.txt","r");

if(fp==NULL){
perror("It is a mistake dont do that again!!:");
return -1;
}
fclose(fp);





return 0;
}
