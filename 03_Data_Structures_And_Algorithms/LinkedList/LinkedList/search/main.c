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
 * @return if found returns the NODE, else returns NULL
 */
NODE* search(NODE* p,int key){
  
  while( p && p->data != key)
        p = p->next;

  if(p)
    return p;

return NULL;
}

NODE* searchRecursive(NODE* p, int key){
 
  if(p == NULL)
        return NULL;

  if(p->data == key)
        return p;
  return searchRecursive(p->next,key);
}

/**
 * If the item foundi we'll put the item at the head of the list 
 * so that when we search again same key, it will be easy to find it.
 * !! You need to update head as the return value of this function if it is not null in the main
 * or else you need to make head global so that we can update it in the function
 * or else you need to send NODE** head to update inside function.
 */
NODE* searchImproved(NODE* head, int key){
  NODE* curr = head, *prev;
  
  while(curr && curr->data != key){
    prev = curr;
    curr = curr->next;
  } 

  if(curr){
    prev->next = curr->next;
    curr->next = head;
   
   return curr;
  }

return NULL;
}

// Unit Test
int main(){

  NODE* head = 0;
  int A[] = {1,5,7,8,9,3,2,54,};
  head = createLinkedList(A, 8 );
  
  NODE* item = search(head, 9);
  if(item)
    printf("Fist Item %d found... at address %p \n",item->data,item);
  else
    printf("First Item not found\n");
 
  item = search(head, 56);
  if(item)
    printf("Second Item %d found... at address %p \n",item->data,item);
  else
    printf("Second Item not found\n");

   item = searchRecursive(head, 5);
  if(item)
    printf("Third Item %d found... at address %p \n",item->data,item);
  else
    printf("Third Item not found\n");
   
    item = searchImproved(head, 8);
  if(item){
    printf("Fourth Item %d found... at address %p \n",item->data,item);
    head = item;
  }
  else
    printf("Fourth  Item not found\n");
  
    display(head);

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


