#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
typedef int bool;


#define HASH_TABLE_MAX_SIZE 300000
#define PRIME 299993
#define R 7

typedef struct hash_table{
    char** arr;            // Array of strings
    int curr_size;         // Curr No of Elements inside hash table
}HASH_TABLE;

bool isFull(HASH_TABLE* ht){
    return ht->curr_size == HASH_TABLE_MAX_SIZE;
}

long hash1(long key){
    return key % HASH_TABLE_MAX_SIZE;
}

long hash2(long key){
    return PRIME - (key % PRIME);
}

long getKey(const char* str){
    long key = 0;
    int i,j;
    for(i = 0, j = strlen(str); j > 0; j--, i++)
        key += str[i] * pow(R,j);

    if( key < 0 ){
        fprintf(stderr, "Overflow on Key Calculation!...\n");
        exit(1);
    }

    return key;
}

HASH_TABLE* hashTableFactory(){
    HASH_TABLE* ht = (HASH_TABLE*)malloc(sizeof(HASH_TABLE));
    ht->curr_size = 0;
    ht->arr = (char**)calloc(HASH_TABLE_MAX_SIZE, sizeof(char*));
    return ht;
}


/**
 * inserts into hash table
 * @param ht is the hash table of strings
 * @param str is the string that we want to insert into hash table
 * @return TRUE if inserts successfully, if the str already inserted before returns FALSE
 */
bool insertHT(HASH_TABLE* ht, const char* str){
    if( isFull(ht) ){
        fprintf(stderr,"Hash Table is Full:: Can not insert another item...\n");
        exit(1);
    }
    long key = getKey(str);
    long index = hash1(key);
    long index2,new_index = index, i = 0;

    if( ht->arr[index] != NULL){           // On Collision
        if(strcmp(ht->arr[index], str) == 0)
            return FALSE;                 // if the place is the same as the str then no need to insert anything
        index2 = hash2(key);
        while(i < HASH_TABLE_MAX_SIZE && ht->arr[new_index] != NULL)
            new_index = (index + i++ * index2) % HASH_TABLE_MAX_SIZE;
        if( i >= HASH_TABLE_MAX_SIZE ) {       // this means we couldnt found NULL place
            fprintf(stderr, "Traversed all the hash table still no NULL place....\n");
            exit(1);
        }
        index = new_index;
    }

    // if we are here this means we found NULL place to insert
    ht->arr[index] = (char*)malloc(sizeof(char) * (strlen(str) + 1) );
    strcpy(ht->arr[index], str);
    ht->curr_size += 1;

    return TRUE;
}

void showHT(HASH_TABLE* ht){
    int i;
    for(i = 0; i < HASH_TABLE_MAX_SIZE; i++)
        if( ht->arr[i] != NULL)
            printf("%d - %s\n",i,ht->arr[i]);
}

long getHash(HASH_TABLE* ht, char* str){
    long key = getKey(str);
    long index = hash1(key);

    if( ht->arr[index] == NULL )
        return -1;          // hash1 has no collision and that point is empty so str can not be possibly added before

    long index2 = hash2(key);
    long i = 0;
    long new_index = index;

    while( ht->arr[new_index] != NULL){
        if(strcmp(ht->arr[new_index],str) == 0)
            return new_index;
        new_index = (index + i++ * index2) % HASH_TABLE_MAX_SIZE;

        if( i >= HASH_TABLE_MAX_SIZE ){
            return -1;
        }
    }
    return -1;
}

int main() {
    HASH_TABLE* ht = hashTableFactory();
    insertHT(ht,"Mustafa Katipoglu");
    insertHT(ht,"Ahmet Koca");
    insertHT(ht,"Yusuf Sertan Gunes");
    showHT(ht);

    printf("Hash of %s is %lu\n", "Mustafa Katipoglu", getHash(ht, "Mustafa Katipoglu"));
    printf("Hash of %s is %lu\n", "Ahmet Koca", getHash(ht, "Ahmet Koca"));
    printf("Hash of %s is %lu\n", "Yusuf Sertan Gunes", getHash(ht, "Yusuf Sertan Gunes"));
    if( getHash(ht, "Mert Oz") == -1)
        printf("Mert Oz is not found...\n");
    else
        printf("Hash of %s is %lu\n", "Mert Oz", getHash(ht, "Mert Oz"));
    exit(0);
}