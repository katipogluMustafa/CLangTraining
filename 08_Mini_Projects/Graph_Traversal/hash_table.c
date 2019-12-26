//
// Created by Yukawa on 2019-12-20.
//

#include "def.h"

bool isHashTableFull(HASH_TABLE* ht){
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
    long curr_word_key = 0;
    int i,j;

    j = strlen(str);
    while(j > 0){
        for(i = j; str[i] != '\0' && i < j+5; i++)
            curr_word_key += str[i] * pow(R,j%5);
        key += curr_word_key;
        j--;
    }


    if( key < 0 ){
        fprintf(stderr, "Overflow on Key Calculation!...\n");
        exit(1);
    }

    return key;
}

/**
 * inserts into hash table
 * @param ht is the hash table of strings
 * @param str is the string that we want to insert into hash table
 * @return TRUE if inserts successfully, if the str already inserted before returns FALSE
 */
bool insertHT(HASH_TABLE *ht, const char *str, bool is_movie) {
    if( isHashTableFull(ht) ){
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
            fprintf(stderr, "insertHT()::Traversed all the hash table still no NULL place....\n");
            exit(1);
        }
        index = new_index;
    }

    // if we are here this means we found NULL place to insert
    ht->arr[index] = (char*)malloc(sizeof(char) * (strlen(str) + 1) );
    strcpy(ht->arr[index], str);
    ht->curr_size += 1;

    ht->is_movie[index] = (bool*)malloc(sizeof(bool));
    *(ht->is_movie[index]) = is_movie;

    return TRUE;
}

HASH_TABLE* hashTableFactory(){
    HASH_TABLE* ht = (HASH_TABLE*)malloc(sizeof(HASH_TABLE));
    ht->curr_size = 0;

    ht->arr = (char**)calloc(HASH_TABLE_MAX_SIZE, sizeof(char*));
    ht->is_movie = (bool**)calloc(HASH_TABLE_MAX_SIZE, sizeof(bool*));

    return ht;
}

void showHT(HASH_TABLE* ht){
    int i;
    for(i = 0; i < HASH_TABLE_MAX_SIZE; i++)
        if( ht->arr[i] != NULL)
            if( *(ht->is_movie[i]) == TRUE)
                printf("%d - %s - Movie\n",i,ht->arr[i]);
            else
                printf("%d - %s - Actor\n",i,ht->arr[i]);
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

void insertArtistsIntoHT(HASH_TABLE* ht, char** artists, int size){
    int i;
    for(i = 0; i < size; i++)
        insertHT(ht,artists[i],FALSE);
}

void insertMoviesIntoHT(HASH_TABLE* ht, char** artists, int size){
    int i;
    for(i = 0; i < size; i++)
        insertHT(ht,artists[i],TRUE);
}