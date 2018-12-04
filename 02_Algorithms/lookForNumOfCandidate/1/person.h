#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Person{
  	char* name;
	int age;
	int height;
	int weight;
};

struct Person* Person_create(char* name, int age, int height, int weight){
  
  struct Person* who = (struct Person*)malloc( sizeof(struct Person) );
  assert(who != NULL);
  
  who->name = strdup(name);	
  // strdup allocates space for the string's copy and return the pointer to first character
  // you need to free it at the end of the its usage scope.
  
  who->age = age;
  who->height = height;
  who->weight = weight;


  return who;
}

void Person_destroy(struct Person* Who){

  assert(Who != NULL);
  // if Who is equal to NULL, gives error.

  free(Who->name);
  free(Who);   
}

