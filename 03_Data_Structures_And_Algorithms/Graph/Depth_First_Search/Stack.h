#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef int boolean;
#define true  (1)
#define false (0)

typedef struct{
  int item[MAX];
  int top;
}STACK;


/**
 * Factory Function for Stack
 * @return STACK* Newly Allocated STACK Address
 */
STACK* stackFactory(){
  STACK* stack = (STACK*)malloc( sizeof(STACK) );
  stack->top = 0;
 
  return stack;
}

/**
 * Check is the given stack empty or not
 * @param STACK* Stack to check
 * @return boolean true for empty, false otherwise
 */
boolean isEmpty(STACK* stack){
  if( stack == NULL )
    return true;

  if( stack->top != 0)
    return false;
 
  return true;
}

/**
 * Check is the given stack full or not
 * @param STACK* Stack to check
 * @return boolean true for full, false otherwise
 * @constant MAX defined as macro
 */
boolean isFull(STACK* stack){

  if( stack == NULL)
    return false;

  if( stack->top == MAX)
    return true;
 
  return false;
}

/**
 * Peek the value at the top of the stack
 * @param STACK* Stack to peek
 * @param int* the value you get after peeking
 * @return boolean true if the peeking process is successfull, false otherwise
 */
boolean peek(STACK* stack, int* out){ 
  if( isEmpty(stack) )
    return false;
 
  int index = stack->top - 1;
  *out = stack->item[index];

  return true;
}

/**
 * Push the value given as parameter to the given stack
 * @param STACK* Stack to push element
 * @param int* the value you want to push to stack
 * @return boolean true if the pushing process is successfull, false otherwise
 */
boolean push(STACK* stack, int in){
  if( isFull(stack) )
    return false;
  
  stack->item[stack->top] = in;
  stack->top++;

  return true;
}

/**
 * Pop element from the top of the given stack
 * @param STACK* Stack to pop element
 * @param int* the element you popped from the given stackstack
 * @return boolean true if the popping process is successfull, false otherwise
 */
boolean pop(STACK* stack, int* out){
  if( isEmpty(stack) )
    return false;
  
  stack->top--;
  *out = stack->item[stack->top];
  
  return true;
}
