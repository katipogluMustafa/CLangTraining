#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef int boolean;
#define true  (1)
#define false (0)


typedef struct node{
  int data;
  struct node* next;
}NODE;

NODE *head, *tail; 

/* Prototypes*/
void display(NODE* p);
NODE* createLinkedList(int A[], int n);
void freeLinkedList();
NODE* createLinkedList(int A[], int n);


/**
 * Prints circular linkedList and since if it is circular linkedList then it cannot be NULL, we don't check it.
 * @param NODE* Circular linkedList to print with one or more NODE
 */
void displayCircular(NODE* first){
  NODE* temp = first;
  
  do{
  
    printf("%d ", first->data);
    first = first->next;
  
  }while( temp != first );
  
}

/**
 * Display Circular Linkedlist Recursively, head is globally defined
 * @param NODE* head of the circular linkedlist
 */

void RCircularDisplay(NODE* t){
  static int flag = 0;
  if( head != t || flag == 0){
    flag = 1;
    printf("%d ", t->data);
    RCircularDisplay(t->next);
  }
  flag = 0; 	
}

/**
 * With An array if ints creates a circular linkedList
 * @param int[] array of integers
 * @param int number of integers
 * @return Circular linkedlist with given array of elements
 */
NODE* createCircular(int A[], int n){
  NODE *temp, *last, *first;
  int i;
  first = (NODE*)malloc( sizeof(NODE) );
  first->data = A[0];
  first->next = first;
  last = first;
  
  for( i = 1 ; i < n; i++){
    temp = (NODE*) malloc( sizeof(NODE) );  
    temp->data = A[i];
    temp->next = last->next;
    last->next = temp;
    last = temp;
  }
  
return first;
}

// Unit Test
int main(){
  
 
  int A[] = {3,5,6,1,2,7,6};
  head = createCircular(A, 7);  
  RCircularDisplay(head);  
  printf("\n");
  displayCircular(head);

   

return 0;
}

/**
 * Finds out if there exists any loop inside linkedList, if not it is linear
 * @param NODE* The head of the linkedList
 * @return boolean If has loop returns true, if linear returns false
 */
boolean hasLoop(NODE* first){
  // If has loop, fast and slow pointers will eventually meet again on some node
  NODE* slow = first;
  NODE* fast = first;
  
  do{
    slow = slow->next;
    fast = fast->next;

    if( fast != NULL)
      fast = fast->next; 		// fast goes 2 step at a time, slow goes one step a time

  }while(slow && fast && slow != fast);
  
  if( slow == NULL || fast == NULL)
    return false; 			// if any of them become NULL, then linkedList is linear  
  else if( slow == fast )
    return true;  

}




void display(NODE* p){
  while(p){
        printf("%d ", p->data);
        p = p->next;
  }
}

NODE* createLinkedList(int A[], int n){
  NODE *head = NULL,*p, *last;
  int i; 
  
  if( n == 0)
    return NULL;  
  
  head = (NODE*)malloc(sizeof(NODE));
  head->data = A[0];
  head->next = NULL;
  last = head;

  for(i = 1; i < n; i++){
        p = (NODE*)malloc(sizeof(NODE));
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;
  }
   

return head;
}

void freeLinkedList(){
  
  NODE* temp;

  while(head){
    temp = head->next;
    free(head); 
    head = temp;
  }
  
  head = NULL;
}

