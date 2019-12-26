//
// Created by Yukawa on 2019-12-14.
//

#ifndef BACON_DEF_H
#define BACON_DEF_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
typedef int bool;

#define BUFFER_SIZE 2048                                 // buffer size when taking input
#define DELIMITER '/'                                    // Delimeter found in the input file

#define MAX_NO_OF_MOVIES  4096    //14152                // max no of movies that will be included inside of the graph
// This macros exists otherwise input data has more than 16000 movies and analyzing takes sames time.
// When time is not a problem replace any place this macro exists with in_movies->curr_size

typedef struct movie{
    char* title;                // Title of the Movie
    char** actors;              // Array of actor actors
    int size;                   // No.of elements inside actors array
    int capacity;               // Capacity of Actors Array
}MOVIE;

typedef struct movies{
    MOVIE** arr;
    int size;
    int capacity;
}MOVIES;

typedef struct node{
    long vertex;
    struct node* next;
    struct node* last_parent;           // Used when searching, for backtraking purposes
}NODE;

typedef struct graph{
    int no_of_vertices;
    NODE** adj_list;                // Array of Linkedlists
}GRAPH;

typedef struct queue{
    int front,rear,size;
    unsigned int capacity;
    int* arr;
}Queue;

int isFull(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, long item);
long dequeue(Queue* q);
Queue* queueFactory(unsigned int capacity);
void QueueDestructor(Queue* queue);

/* Hash Table */
#define HASH_TABLE_MAX_SIZE 100000      // 15000 300000 100000
#define PRIME 99991                    // 14875 299993 99991
#define R 3

typedef struct hash_table{
    char** arr;            // Array of strings
    bool** is_movie;       // Array of booleans which corresponds to each spot in 'arr' and shows whether it is movie or no
    int curr_size;         // Curr No of Elements inside hash table
}HASH_TABLE;

bool isHashTableFull(HASH_TABLE* ht);
bool insertHT(HASH_TABLE *ht, const char *str, bool is_movie);
HASH_TABLE* hashTableFactory();
long getKey(const char* str);
long hash2(long key);
long hash1(long key);
void showHT(HASH_TABLE* ht);
long getHash(HASH_TABLE* ht, char* str);

void insertArtistsIntoHT(HASH_TABLE* ht, char** artists, int size);
void insertMoviesIntoHT(HASH_TABLE* ht, char** artists, int size);

/* Raw Data For Graph */

char** getAllArtists(MOVIES *movies);
int search_artist_name(char **artists,int size, char *artist);
char** add_artist(char **artists, int* size, int* capacity, char *artist);
char** getAllMovies(MOVIES* movies);
int count_artists(char** artists);

void exit_on_null(void* ptr, const char* msg);
void printStringArray(char** str_arr, int size);
char* clear_string(char* str);


/* Input Taking */
MOVIES* ReadInput(FILE* file);

MOVIES* insertMovie(MOVIES* movies, MOVIE* movie);
void free_movies(MOVIES* movies);
void free_movie(MOVIE* movie);
MOVIES* moviesFactory(int movieCapacity);
MOVIE* insertActor(MOVIE* movie, const char* actor);
MOVIE* movieFactory(int actorCapacity);
void printMovies(MOVIES* movies);
void printMovie(MOVIE* movie);
void printMovieActors(MOVIE* movie);



/* Graph */
GRAPH* GraphFactory(int no_of_vertices);
GRAPH* PrepareGraph(MOVIES* in_movies, HASH_TABLE* ht);
void AddEdge(GRAPH* graph, long srcVertex, long destVertex);
void LinkMoviesAndArtists(GRAPH* graph, MOVIES* in_movies, HASH_TABLE* ht);
void printGraphConnections(GRAPH* graph, HASH_TABLE* ht);

void BFS(GRAPH* G, HASH_TABLE* ht, long srcVertex, long destVertex );

#endif //BACON_DEF_H
