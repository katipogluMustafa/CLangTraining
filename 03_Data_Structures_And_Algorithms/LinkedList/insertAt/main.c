#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
  
  int data;
  struct node* next;

}NODE;


NODE* head; 

/* Prototypes*/
void display(NODE* p);
NODE* createLinkedList(int A[], int n);
void freeLinkedList(NODE* head);

NODE* LinearSearch(NODE* head, int key);
NODE* RecursiveSearch(NODE* head, int key);
NODE* search(int key);

int findMin(NODE* p);
int findMax(NODE* p);
int findMaxRecursive(NODE* p);

int sum(NODE* head);
int sumRecursive(NODE* p);

int count(NODE* p);
int countRecursive(NODE* p);

void insertAt(int index, int x){
  int i;
  NODE* t, *p;
  if(index < 0 || index > count(head))
    return;

   t = (NODE*)malloc(sizeof(NODE));
   t->data = x;
 
  if(index == 0){
    t->next = head;
    head = t;
  }
  else if( index > 0){
  
    p = head;
    // go to the pos-1 to insert at pos index    
    for(i = 0; (i < index - 1) && p; i++)
      p = p->next;
     // if the position exist
     // (for ex there exit 5 element but we may  want to inert at position 25 etc.)
     
    if(p){
      t->next = p->next;
      p->next = t;
    }  
  
  }

}

int main(){

  int arr[] = {22,5,1,2,3,6};
  head = createLinkedList( arr, 6 );

  display(head);
  printf("\n");
  insertAt(0, 25); // insert 25 at index 3 
  insertAt(0, 25); // insert 25 at index 3 
  insertAt(0, 25); // insert 25 at index 3 
  
  display(head);
  printf("\n");

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

NODE* LinearSearch(NODE* head, int key){
  NODE* temp = head;
  
  while(temp){
    if( key == temp->data )
      return temp;
    temp = temp->next;
  }

  return NULL;
}

NODE* RecursiveSearch(NODE* t, int key){

  if( t == NULL )
    return NULL;

  if( t->data == key)
    return t;
  
  return RecursiveSearch(t->next, key);
}

NODE* search(int key){
  NODE* curr = head, *prev = head;
  
  while(curr){
    // if found
    if( key == curr->data ){
     // make the found element head so that next time we'll find it quickly. 
     if(curr != head){
        prev->next = curr->next;
        curr->next = head;
        head = curr;    
      }
      return curr;  
    }
    prev = curr;
    curr = curr->next;
  }
 
return NULL;
}

/**
 * @return if p is null returns INT_MAX value, else max element
 */
int findMin(NODE* p){
  int min = INT_MAX;
  while(p){
    if(p->data < min)
        min = p->data;
    p = p->next;
  }
  
  return min;
}

/**
 * @return if p is null returns INT_MIN value, else max element
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

int sum(NODE* head){
  int sum = 0;
  while( head ){
    sum += head->data;
    head = head->next;
  }
  return sum;
}

int sumRecursive(NODE* p){
  if(p)
    return p->data + sum(p->next);

  return 0;
}

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


