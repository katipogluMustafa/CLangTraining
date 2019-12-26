//
// Created by Yukawa on 2019-12-26.
//

#include "def.h"

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

void enqueue(Queue* q, long item){
    if( isFull(q) )
        return;

    q->rear = (q->rear+1)%(q->capacity);
    q->arr[q->rear] = item;
    q->size += 1;
}

long dequeue(Queue* q){
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
    q->arr = (int*)malloc(sizeof(long) * capacity);
}

void QueueDestructor(Queue* queue){
    free(queue->arr);
    free(queue);
}