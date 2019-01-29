#include<stdio.h>
#include<stdlib.h>

int main(){
int num;
char str[20];
FILE *fptr;
fptr=fopen("Asaf.txt","w+");

if(fptr==NULL){
printf("Error!");
exit(1);
}
/*
printf("Enter a number");
scanf("%d",&num);		//if ı want to enter integer.
*/
printf("Enter a name:");
scanf("%s",str);		//if i want to enter char or string.


//fprintf(fptr,"%d",num);	//integer prints
fprintf(fptr,"%s",str);		//Char prints.
fclose(fptr);

return 0;


}
