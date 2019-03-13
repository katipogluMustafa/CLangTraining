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


// Unit Test
int main(){
  
  int A[] = {3,5,7,1,3,6,24};
  head = createLinkedList(A, 7);
  
  NODE* x = head->next->next->next;
  NODE* temp = head;
  while( temp->next )
    temp = temp->next;
  temp->next = x;
  
  if( hasLoop(head) == false )
    display(head);
  else
    printf("Can't display it is circular\n");
 
  int B[] = {3,5,4,6,2,1};
  NODE* second = createLinkedList(B, 6);
  
  if( hasLoop(second) )
    printf("Second LinkedList is circular\n");
  else 
    printf("Second LinkedList is Linear\n"); 

  free(head);
return 0;
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

