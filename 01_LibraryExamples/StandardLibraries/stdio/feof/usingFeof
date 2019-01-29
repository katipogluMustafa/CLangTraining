#include<stdio.h>


int main(){

char c;
FILE *fp=fopen("Asaf.txt","r");

if(!fp){
	perror("Chaos while opening file!");
	return -1;
}


while( 1 ) {

      	c = fgetc(fp);
        
	if( feof(fp) ){
		break;
	}
	 
	printf("%c", c);
	
   }


   fclose(fp);


return 0;
}
