#include<stdlib.h>
#include<stdio.h>
int main(){

//FILE *filep=fopen("file_name","Mode");
int c;
FILE *fp=fopen("Asaf.txt","r");

while(1) {
      c = fgetc(fp);
      if( feof(fp) ) { 
         break ;
      }
      printf("%c", c);
   }
   fclose(fp);


return 0;
}
