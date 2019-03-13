#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef int boolean;
#define true  (1)
#define false (0)


typedef struct node{
  struct node* prev;
  int data;
  struct node* next;
}NODE;

NODE *head = NULL;

/* Prototypes */

NODE* create(int A[], int n);
void display(NODE* first);
int length(NODE* first);
void freeLinkedList(NODE* first);

// Unit Test
int main(){

  int A[] = {3,1,2,6,0,1,5,2,3};
  head = create(A, 9);
  printf("Length: %d\n", length(head) );
  display(head);
  free(head);

return 0;
}

/**
 * Creates a doubly linkedlist with given array of elements
 */
NODE* create(int A[], int n){
  NODE* first, *t, *last;
  int i;
 
  first = (NODE*)malloc(sizeof(NODE));
  first->data = A[0];
  first->prev = first->next = NULL;
  last = first;

  for(i = 1; i < n; i++){

    t = (NODE*)malloc(sizeof(NODE));
    t->data = A[i];
    t->next = last->next;
    t->prev = last;
    last->next = t;
    last = t; 
  }

return first;
}

void display(NODE* first){

  while(first){
    printf("%d ", first->data);
    first = first->next;
  }
  printf("\n");
}

int length(NODE* first){
  int i = 0;
  while(first){
    first = first->next;
    i++;
  }
return i;
}

void freeLinkedList(NODE* first){
  NODE* temp;
  while(first){
    temp = first->next;
    free(first);
    first = temp;
  }
}

