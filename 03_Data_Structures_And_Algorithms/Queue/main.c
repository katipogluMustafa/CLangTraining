#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct queue{
  int front,rear,size;
  unsigned int capacity;
  int* arr;
}Queue;

int isFull(Queue* q){
  if(q == NULL)
    return INT_MIN;
  return q->capacity == q->size;
}

int isEmpty(Queue* q){
  if( q == NULL )
    return INT_MIN;
  return q->size == 0;
}

void enqueue(Queue* q, int item){
  if( isFull(q) )
    return;
  
  q->rear = (q->rear+1)%(q->capacity);
  q->arr[q->rear] = item;
  q->size += 1;
}

int dequeue(Queue* q){
  if( isEmpty(q) ) 
    return INT_MIN;
  int item = q->arr[q->front]; 
  q->front = (q->front + 1) % q->capacity;
  --q->size;

  return item;
}

Queue* queueFactory(unsigned int capacity){
  Queue* q = (Queue*)malloc(sizeof(Queue));
  q->capacity = capacity;
  q->front = q->size = 0;
  q->rear = capacity - 1;
  q->arr = (int*)malloc(sizeof(int) * capacity);
}

int main(){
  Queue* q = queueFactory(2);
  enqueue(q,2);
  enqueue(q,5);
  
  printf("%d \n", isFull(q) );
  printf("%d ", dequeue(q)); 
  printf("%d ", dequeue(q)); 
 
return 0;
}
