#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 2048

int searchPattern(char* in, char* patern);


int main(){
  
  char read_el[SIZE];
  FILE *fp=fopen("input.txt", "r");

  if(fp == NULL){
      printf("File Opening Error!!");

  }
  /* Print the input string 
  while (fgets(read_el, SIZE, fp) != NULL)
      printf(" %s ", read_el);
  */
  fclose(fp);
  
  char stxt[] = "ethics";
  int position = searchPattern(read_el, stxt );
  
  if(position != -1){
	
	printf("Found at %d\n", position);

  }else{

	printf("%s : Not Found!\n", stxt);

  }

  return 0;
}

int searchPattern(char* in, char* pattern){
   
  char *p, *q, *sub;

  for(sub = in; *sub; sub++){
    p = sub;
    q = pattern;

    int i = 0;

    while(*q){
    	if(*q++ != *p++){
   		break;
	}
	i++;
    }
    if( !(strlen(pattern) - i) ){
    	
	return sub - in;

    }
  } 
   
	return -1;
}
