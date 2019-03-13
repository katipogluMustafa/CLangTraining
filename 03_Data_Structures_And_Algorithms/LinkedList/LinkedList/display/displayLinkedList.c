#include<stdio.h>
#include<stdlib.h>

#define true  (1)
#define false (0)

typedef int boolean;

typedef struct node{
    int data;
    struct node* next;
}NODE;


void display(NODE* p){
  while(p){
        printf("%d ", p->data);
        p = p->next;
  }
}

void displayRecursive(NODE* p){
     if(p){
        printf("%d ", p->data);
        displayRecursive(p->next);
     }
}

void displayReverse(NODE* p){
     if(p){
        displayReverse(p->next);
        printf("%d ", p->data);
     }
}



NODE* createLinkedList(int A[], int n){
  NODE *head = NULL,*p, *last;
  int i;
  
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

void freeLinkedList(NODE* head){
  
  NODE* temp;

  while(head){
    temp = head->next;
    free(head); 
    head = temp;
  }

}

// Unit Test
int main(){

  NODE* head = 0;
  display(head);

  head = (NODE*)malloc(sizeof(NODE));
  head->data = 5;
  head->next = 0;
  display(head);

  printf("\n");

  head->next = (NODE*)malloc(sizeof(NODE));
  head->next->data = 10;
  head->next->next = 0;
  display(head);
  printf("\n");
  
  freeLinkedList(head);

  int A[] = {1,5,7,8,9,3,2,};
  head = createLinkedList(A, 7 );
  display(head);
  printf("\n");
  displayRecursive(head);
  printf("\n");
  displayReverse(head);
  printf("\n");
  
  freeLinkedList(head);

return 0;
}

