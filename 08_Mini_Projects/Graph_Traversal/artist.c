//
// Created by Yukawa on 2019-12-20.
//
#include "def.h"

// Search a artist name in artists array
int search_artist_name(char** artists, int size, char* artist) {
    int i;
    for(i = 0; i < size; i++)
        if(strcmp(artists[i],artist) == 0)
            return 1;
    return 0;
}

char** add_artist(char** artists, int* size, int* capacity, char* artist) {
    if( artists == NULL  )
        return NULL;

    char** ptr_to_artists = artists;            // backup pointer to artists array in case realloc returns NULL
    int i;                                      // iterator

    if( *size >= *capacity ){
        *capacity *= 2;
        artists = (char**)realloc(artists, sizeof(char*) * *capacity);
        if(artists == NULL){
            fprintf(stderr, "add_artist():: NULL returned from realloc\n");
            for(i = 0; i < *size; i++)                      // Deallocate each actor inside of the artists array
                free(ptr_to_artists[i]);
            exit(1);
        }
    }

    if( artist != NULL ) {
        artists[*size] = (char *) malloc(sizeof(char) * (strlen(artist) + 1));
        strcpy(artists[*size], artist);
    }else
        artists[*size] = NULL;

    *size += 1;
    return artists;
}

// Returns NULL terminated array of unique artists names
char** getAllArtists(MOVIES* movies) {
    int a_size = 0;                                         // Number of artists inside 'artists' array
    int a_capacity = 2;                                     // capacity of 'artists' array
    char** artists = (char**)malloc(sizeof(char*) * 2 );    // Allocate artists
    int i,j;
    MOVIE* temp;                                            // Temporary pointer to a MOVIE that is each slot inside of the 'MOVIES'

    for(i = 0; i < MAX_NO_OF_MOVIES; i++){
        temp = movies->arr[i];
        for(j = 0; j < temp->size; j++)
            if( search_artist_name(artists,a_size, temp->actors[j]) == 0)   // if the artist not added to the array
                artists = add_artist(artists,&a_size, &a_capacity, temp->actors[j]);
    }

    artists = add_artist(artists,&a_size,&a_capacity,NULL);
    return artists;
}

int count_artists(char** artists) {
    int i;
    for( i = 0; artists[i] != NULL; i++ );
    return i;
}