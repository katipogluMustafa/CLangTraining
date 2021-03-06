#include<stdio.h>
#include<stdlib.h>

#define true  (1)
#define false (0)

typedef int boolean;
typedef struct node{
    int data;
    struct node* next;
}NODE;

void display(NODE* p);
NODE* createLinkedList(int A[], int n);
void freeLinkedList(NODE* head);


int count(NODE* p){
  int count = 0;
  while(p){
    count++;
    p = p->next;
  }
  return count;
}

int countRecursive(NODE* p){
  if(p){
    return 1 + countRecursive(p->next);    
  } 

  return 0;
}

// Unit Test
int main(){

  NODE* head = 0;
  int A[] = {1,5,7,8,9,3,2,};
  head = createLinkedList(A, 7 );
  printf("%d\n", count(head));
  printf("%d\n", countRecursive(head));

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


