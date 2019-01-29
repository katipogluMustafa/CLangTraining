#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
char data[25]="Asaf Ali";
int length=strlen(data);
int i;

FILE *filep=fopen("Asaf.txt","w");

if (filep==NULL){
printf("File can not created");
}
else {
for (i=0;i<length;i++){
fputc(data[i],filep);
printf("Char that written: %c\n",data[i]);

}
printf("File is successfully written");
fclose(filep);
}



return 0;
}
