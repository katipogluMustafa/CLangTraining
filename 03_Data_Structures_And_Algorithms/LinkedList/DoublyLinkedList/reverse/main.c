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
boolean insert(int index, int element);
int delete(int index);

/**
 * Reverses given linkedlist returns the new head
 * @param NODE* first element of linkedlist
 * @return NODE* The new Head of the linkedlist
 */
NODE* reverse(NODE* p){ 		
  NODE* temp = p;
  while( p ){
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;
    if(temp == NULL)
      return p;
    p = temp;
  }

}

// Unit Test
int main(){

  int A[] = {3,1,2,6,0,1,5,2,3};
  head = create(A, 9);
  printf("Length: %d\n", length(head) );
  display(head);
  head = reverse(head); 
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

/**
 * Inserts into globally defined doubly linkedList
 * @param int index you want to insert
 * @param int element you want to insert
 * @return boolean true if added successfully, otherwise false
 */
boolean insert(int index, int element){
  if( index < 0 || index > length(head) )
    return false;
  int i;  
  
  NODE* iterator;
  NODE* temp = (NODE*)malloc(sizeof(NODE*));
  temp->data = element;
 
  if( index == 0){
    temp->prev = NULL;
    temp->next = head;
    head->prev= temp;
    head = temp;
  }else{
    iterator = head;
    for(i = 1; i < index; i++)
      iterator = iterator->next; 	
    temp->prev = iterator;
    temp->next = iterator->next;
    if(iterator->next) 				// Be carefull, it may not exists if it is last node
      iterator->next->prev = temp;
    iterator->next = temp;
  }

return true;
}

/**
 * Deletes element from globally defined doubly linkedlist
 * @param int index starting from 0 
 * @return value you deleted, on error INT_MIN 
 */
int delete(int index){
  if( index < 0 || index >= length(head) )
    return INT_MIN;
  NODE* temp = head;
  int i,ret = INT_MIN;

  if( index == 0){
    head = head->next;
    if(head)
      head->prev = NULL;
    ret = temp->data; 		
    free(temp);
  }else{
    for(i = 0; i < index;i++)
      temp = temp->next;

    temp->prev->next = temp->next;
    if(temp->next)
      temp->next->prev = temp->prev;
    ret = temp->data;
    free(temp);  
  }

return ret;
}


