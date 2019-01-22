#include<stdio.h>
#include<stdlib.h>

void printArgs(int,char* []);

int main(int argc, char* argv[]){
 
  /* Args */	
  printArgs(argc,argv);
 	
  char* w = getenv("EXTRA");
  if(!w){
    w = getenv("FOOD");
  }

  if(!w){
    w = getenv(argv[argc - 1]);
  }
  char* c = getenv("EXTRA");
  if(!c){
    c = argv[argc - 1];
  }  
  printf("%s with %s\n",c,w);
return 0;
}

void printArgs(int argc ,char* argv[]){
 char**  x = argv; 
 printf("\nArgc: %d, Arguments: ", argc);
 while(*x){
    printf("%s ", *x++);
 }
 printf("\n");
}
