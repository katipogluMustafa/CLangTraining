#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 2048

int searchPattern(char* in, char* patern);
int search(char* start, char* pattern);

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
  
  char stxt[] = "up";
  int position = searchPattern(read_el, stxt );
  
  if(position != -1){
	
	printf("Found at %d\n", position);

  }else{

	printf("%s : Not Found!\n", stxt);

  }

  return 0;
}

int searchPattern(char* in, char* pattern){
  
  int count = 0;
  while(*in){
  
  // if the first char of the pattern is found 
  if(*in == *pattern){
	// then search pattern
	int x = search(in,pattern);
 	if(x == 1){
		return count;	
	}
  }
  count++;
  in++;
  } 

return -1;
}

int search(char* start, char* pattern){

// if we see exact pattern
  char* copy = start;
  char* patrn = pattern;

  while(*patrn == *copy){
    patrn++;
    copy++;
  }
  
  if( !*patrn ){
	return 1;
  }


return 0;
}
