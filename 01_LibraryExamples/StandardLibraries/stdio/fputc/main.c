#include<stdio.h>

int main(){


int i;
char ch;
FILE *fptr;

fptr=fopen("Asaf.txt","w+");

for(i = 0; i < 15 ; i++){
  printf("%d.th character:\n", i + 1 );
  scanf("%c",&ch);
  
  printf("Putting into the file...\n:");
  fputc(ch,fptr);

}

fclose(fptr);

/* Print the File */

fptr = fopen("Asaf.txt","r");

if( !fptr ){
	
  perror("IO Exception\n");
  return -1;
}


while( ( ch = fgetc( fptr ) ) != EOF ){

  printf("%c",ch);

}


fclose(fptr);


return 0;
}
