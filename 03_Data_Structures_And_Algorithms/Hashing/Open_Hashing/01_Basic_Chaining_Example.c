#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} NODE;

void SortedInsert(NODE** head, int x){
    NODE *newNode, *prev = NULL, *curr = *head;

    newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->next = NULL;

    if(*head == NULL )
        *head = newNode;
    else{
        while(curr != NULL && curr->data < x ){
            prev = curr;
            curr = curr->next;
        }
        // if we branch into if, then it means we never executed while loop
        if(curr == *head) {                // do we need to insert at the head of the linkedlist ?
            newNode->next= *head;              // next element of newNode is the old head
            *head = newNode;                   // new head is the newNode
        }else{          // if we executed while loop at least once so head's place is not the location we look for
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }
}

// node starts its first value as HEAD then iterates over all the linked list until found or NULL reached
NODE* Search(NODE* node, int key){
    while(node != NULL ){
        if(key == node->data )
            return node;
        node = node->next;
    }
    return NULL;
}

int hash(int key){
    return key % 10;                // basic hash function
}

void hash_table_insert(NODE* hash_table[], int key){
    int index = hash(key);
    SortedInsert(&hash_table[index], key);
}

int main() {
    NODE* hash_table[10];
    NODE* temp;
    int i;
    for(i = 0; i < 10; i++)
        hash_table[i] = NULL;               // init hash table's each entry as NULL

    hash_table_insert(hash_table,12);
    hash_table_insert(hash_table,22);
    hash_table_insert(hash_table,42);
    hash_table_insert(hash_table,21);

    temp = Search(hash_table[hash(21)],21);
    if( temp != NULL )
        printf("%d \n", temp->data);
    else
        printf("Not Found\n");

    temp = Search(hash_table[hash(25)],25);
    if( temp != NULL )
        printf("%d \n", temp->data);
    else
        printf("Not Found\n");

    return 0;
}