#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int boolean;
#define true  (1)
#define false (0)

// Same value as in stack.c
#define MAX 100

typedef struct{
  int item[MAX];
  int top;
}STACK;

#include"stack.h"
