#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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

/**
 * @return if p is null returns minimum int value, else max element
 */
int findMax(NODE* p){
  int max = INT_MIN;
  while(p){
    if(p->data > max)
        max = p->data;
    p = p->next;
  }
  
  return max;
}

int findMaxRecursive(NODE* p){
  int x;
  if(p){
    x = findMaxRecursive(p->next);
    if(x <  p->data)
        return p->data;
    else
        return x;
  }

return INT_MIN;  
}

int findMaxRecursiveV2(NODE* p){
  int x;
  if(!p)
    return INT_MIN;
  
  x = findMaxRecursiveV2(p->next);
  return (x > p->data) ? x : p->data;
}


// Unit Test
int main(){

  NODE* head = 0;
  int A[] = {1,5,7,8,9,3,2,54,};
  head = createLinkedList(A, 8 );
  printf("%d\n", findMax(head));
  printf("%d\n", findMaxRecursive(head));
  printf("%d\n", findMaxRecursiveV2(head));

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


