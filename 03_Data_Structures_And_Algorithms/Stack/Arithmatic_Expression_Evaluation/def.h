#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int boolean;
#define true  (1)
#define false (0)

#define MAX 250

typedef struct{
  int item[MAX];
  int top;
}STACK;

#include"stack.h"
