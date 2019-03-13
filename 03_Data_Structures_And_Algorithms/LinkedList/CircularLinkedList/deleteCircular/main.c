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

// Linear Functions
void display(NODE* p);
NODE* createLinkedList(int A[], int n);
void freeLinkedList();

// Circular Functions
void displayCircular(NODE* first);
void RCircularDisplay(NODE* t);
NODE* createCircular(int A[], int n);
boolean insertCircular(int index, int value);
int length(NODE* p);

/**
 * Deletes elements from globlly defined circular linkedlist
 * @param int index you want to delete, assuming elements in linkedlist starts from 0   
 * @return int -1 in case of error, if successfull return the item you want to delete
 */
int deleteCircular(int index){
  if( index < 0 )
    return -1;
  int len = length(head);
  if( index > len )
    index = index % len;

  NODE* t = head;
  NODE* prev = head;
  int i,retValue;
  
  if( index == 0 ){

    while(t->next != head)
      t = t->next;
    retValue = head->data;
    if( t == head){  	// this means there is only one node in circular linkedlist which is itself,head
      free(head);
      head = NULL;
    }else{ 		// There exists more than one node inside circular linkedlist
      t->next = head->next;
      free(head);
      head = t->next;
    }

  }else{
    for(i = 0; i < index -2; i++)
      prev = prev->next; 		// prev, previous node of the node we want to delete
    t = prev->next; 			// t, the node we want to delete
    prev->next = t->next;
    retValue = t->data;
    free(t); 
  }
    return retValue;
}

// Unit Test
int main(){
  int A[] = {3,6,4,5,2,1,4};  
  head = createCircular(A, 7);
  int len = length(head);
  printf("\nLength of the Circular LinkedList: %d \n", len);
  displayCircular(head);
  printf("\n");
  insertCircular(3,555);
  len = length(head); 
  printf("\nLength of the Circular LinkedList: %d \n", len);
  displayCircular(head);
  printf("\n");
 
  deleteCircular(0);
  len = length(head); 
  printf("\nLength of the Circular LinkedList: %d \n", len);
  displayCircular(head);
  printf("\n\n");
  
  displayCircular(head);
  printf("\n");
  len = length(head); 
  deleteCircular(len);
  displayCircular(head);
  printf("\n");
    
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

/**
 * Returns number of elements inside circular linkedlist
 */
int length(NODE* p){
  if(p == NULL)
    return 0;

  int counter = 0;

  do{
    counter++;
    p = p->next;
  }while(p != head);

return counter;
}

/**
 * Inserts into globally defined linkedList, head
 * @param int index where you want to insert
 * @param int value you want to insert
 * @return if successfull true, otherwise false
 */
boolean insertCircular(int index, int value){
  NODE* temp, *iterator = head;
  int i;

  if( index < 0)
    return false;

  temp = (NODE*)malloc( sizeof(NODE) );
  temp->data = value;
  
  // Insert into head
  if( index == 0 ){
     if(head == NULL){
       head = temp;
       head->next = head;
     }else{ 
       while(iterator->next != head)
 	iterator = iterator->next;
       iterator->next = temp;
       temp->next = head;
       head = temp;
    }
  }else{
    for(i = 0; i < index -1; i++)
      iterator = iterator->next;
    temp->next = iterator->next;
    iterator->next = temp;
  }

}


