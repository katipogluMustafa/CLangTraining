//
// Created by Yukawa on 2019-12-20.
//
#include "def.h"

// Create a MOVIE object with given capacity for the actors array
MOVIES* moviesFactory(int movieCapacity){
    if(movieCapacity < 0 )
        movieCapacity = 1;               // initial capacity can not be less than 1

    MOVIES* movies = (MOVIES*)malloc(sizeof(MOVIES));
    exit_on_null(movies, "moviesFactory():: Malloc Returned NULL when allocating MOVIES");

    movies->size = 0;
    movies->capacity = movieCapacity;
    movies->arr = (MOVIE**)malloc(sizeof(MOVIE*) * movieCapacity);
    exit_on_null(movies->arr, "moviesFactory():: Malloc Returned NULL when allocating MOVIE for MOVIES");

    return movies;
}

// Movies Destructor
void free_movies(MOVIES* movies){
    int i;
    for(i = 0; i < movies->size;i++)
        free_movie(movies->arr[i]);
}

char** getAllMovies(MOVIES* movies){
    int i;
    char** movie_names = (char**)malloc(sizeof(char*) * MAX_NO_OF_MOVIES);
    for(i = 0; i < MAX_NO_OF_MOVIES; i++){
        movie_names[i] = (char*)malloc(sizeof(char) * (strlen(movies->arr[i]->title) + 1) );
        strcpy(movie_names[i], movies->arr[i]->title);
    }
    return movie_names;
}

void printMovies(MOVIES* movies){
    int i;
    for(i = 0; i < MAX_NO_OF_MOVIES; i++)
        printMovie(movies->arr[i]);
}