#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef int boolean;

#define true  (1)
#define false (0)

enum order{ DEFAULT, INCREASING, DECREASING};

typedef struct node{
  
  int data;
  struct node* next;

}NODE;


NODE *head, *tail; 

/* Prototypes*/
void display(NODE* p);
NODE* createLinkedList(int A[], int n);
void freeLinkedList();

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

void insertAt(int index, int x);
void insertLast(int x);
void sortedInsert(int x);

int deleteAt(int index);
int delete(int key);

boolean isSorted(NODE* first, enum order sortOrder);
void removeDuplicates(NODE* first);

void reverse();
void reverseRecursive();

/**
 * Concatenates two linkedlists, First becomes the result linkedlist
 * @param first Head of the first linkedlist
 * @param second Head of the second linkedlist
 */
void concat(NODE* first, NODE* second){

  NODE* temp = first;
  while( temp->next != NULL){
        temp = temp->next;
  }

  temp->next = second;

}

// Unit Test
int main(){
  
  int A[] = {10,10,10,10,20,30,30,30,40,50,90,600,600,0,600,600};
  head = createLinkedList(A, 16);
  NODE* second = createLinkedList(A, 16);
  removeDuplicates(head);
  removeDuplicates(second);
  concat(head, second);
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

void insertLast(int x){

  NODE* t = (NODE*)malloc(sizeof(NODE));
  t->data = x;
  t->next = NULL;

  if(head == NULL)
    head = tail = t;
  else{
    tail->next = t;
    tail = t;  
  }
  
}

// for Increasing Order
// head globally defined.
void sortedInsert(int x){
  NODE* t = (NODE*)malloc(sizeof(NODE));
  t->data = x;
  t->next = NULL;

  if(head == NULL){             // No NODE Exists
    head = t;
  }else if( x < head->data ){    // NODE needs to be head.
    t->next = head;
    head = t;
  }else{
    NODE* prev = head;
    NODE* curr = head->next;
    while( curr && curr->data < x ){
      prev = curr;
      curr = curr->next;
    }

    prev->next = t;
    t->next = curr;

  }

}

/**
 * @return -1 if fails otherwise the value of the node
 */
int deleteAt(int index){
  NODE* prev, *curr;
  int x = -1,i;

  if(index < 1 && index > count(head))
    return x;

  // if index == 1, delete head
  if(index == 1){
    prev = head;
    head = head->next;
    x = prev->data;
    free(prev);
  }else{

    curr = head;
    prev = NULL;
    for(i = 0; (i < index - 1) && curr; i++){
      prev = curr;
      curr = curr->next;
    }
    // if index exists 
    if(curr){
      prev->next = curr->next;
      x = curr->data;
      free(curr);  
    }

  }

  return x;
}

// Deletes and returns the key if deletes otherwrise -1
int delete(int key){
  NODE* curr, *prev;
  curr = head; 
  prev = NULL;
  int x = -1;

  while(curr){
    // if foun  
    if( curr->data == key){
      
      if( curr == head ){
        head = head->next;
      }else{
        prev->next = curr->next;
      }
        x = curr->data;
        free(curr);
        curr = NULL;
 
    }else{
      prev = curr;
      curr = curr->next;    
    }

  }        

  return x;
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

boolean isSorted(NODE* first, enum order sortOrder){
  int sign;
  NODE* prev;

  if(first == NULL)
    return false;
  else if(first && first->next == NULL)
    return true;
  else {
    prev = first;
    first = first->next;
    // take sign of the first two elements difference
    sign = prev->data - first->data;

    if( sortOrder == INCREASING && sign > 0)
        return false;
    else if( sortOrder == DECREASING && sign < 0)
        return false;
    

    while(first){
      // sign * new sign we get must be positive always if sorted
      if( sign * (prev->data - first->data) < 0 )
        return false;

      prev = first;
      first = first->next;
    }
  }

 return true;
}

void removeDuplicates(NODE* first){
  NODE* prev = NULL;
  NODE* temp;
  while(first){
    prev = first;
    first = first->next;
    if(first && first->data == prev->data){
      prev->next = first->next;
      free(first);
      first = prev; 
    }
  } 

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

void reverse(){
  NODE* prev = NULL, *curr = NULL, *following = head;
  
  while( following){

    prev = curr;
    curr = following;
    following = following->next;
    curr->next = prev;

  }
    
  head = curr;

}

void reverseRecursive(){
  void reverseRecursiveCall(NODE* q, NODE* p);
  reverseRecursiveCall(NULL, head);
}

void reverseRecursiveCall(NODE* q, NODE* p){
  // if p not NULL
  if( p ){
    reverseRecursiveCall(p, p->next);
    p->next = q;
  }else
    head = q;

}


