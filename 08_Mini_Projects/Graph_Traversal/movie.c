//
// Created by Yukawa on 2019-12-20.
//

#include "def.h"

// Create a MOVIE object with given capacity for the actors array
MOVIE* movieFactory(int actorCapacity){
    if(actorCapacity < 0 )
        actorCapacity = 1;               // initial capacity can not be less than 1

    MOVIE* movie = (MOVIE*)malloc(sizeof(MOVIE));
    exit_on_null(movie, "movieFactory():: Malloc Returned NULL when allocating MOVIE");

    movie->size = 0;
    movie->capacity = actorCapacity;
    movie->actors = (char**)malloc(sizeof(char*) * actorCapacity);
    exit_on_null(movie->actors, "movieFactory():: Malloc Returned NULL when allocating actors for current MOVIE");

    return movie;
}

// Movie Destructor
void free_movie(MOVIE* movie){
    int i;
    for(i = 0; i < movie->size; i++)                      // Deallocate each actor inside of the actors array
        free(movie->actors[i]);
    free(movie->title);
    free(movie->actors);                                  // Deallocate actors array itself
}

// Dynamically insert a MOVIE into MOVIES
MOVIES* insertMovie(MOVIES* movies, MOVIE* movie){
    if(movies == NULL )
        movies = moviesFactory(2);

    MOVIE** ptr_to_movie_arr;
    if(movies->size >= movies->capacity ){
        movies->capacity *= 2;
        ptr_to_movie_arr = movies->arr;                                  // in case realloc returns NULL, secure the pointer to the movies' arr
        movies->arr = (MOVIE**)realloc(movies->arr, sizeof(MOVIE*) * movies->capacity);
        if(movies->arr == NULL ){                                        // If reallac returns NULL then Deallocate everything u allocated so far
            fprintf(stderr, "insertMovie():: NULL returned from realloc\n");
            int i;
            for(i = 0; i < movies->size; i++)                            // Deallocate each actor inside of the actors array
                free_movie(ptr_to_movie_arr[i]);
            free(movies);                                      // Deallocate actors array itself
            exit(1);
        }
    }

    movies->arr[movies->size] =  movie;
    movies->size += 1;
    return movies;
}

// Dynamically insert a actor into movie
MOVIE* insertActor(MOVIE* movie, const char* actor){

    if(movie == NULL )
        movie = movieFactory(2);

    char** ptr_to_actors;
    if(movie->size >= movie->capacity ){
        movie->capacity *= 2;
        ptr_to_actors = movie->actors;                              // in case realloc returns NULL, secure the pointer to the actors
        movie->actors = (char**)realloc(movie->actors, sizeof(char*) * movie->capacity);
        if(movie->actors == NULL ){                               // If reallac returns NULL then Deallocate everything u allocated so far
            fprintf(stderr, "insertActor():: NULL returned from realloc\n");
            int i;
            for(i = 0; i < movie->size; i++)                      // Deallocate each actor inside of the actors array
                free(ptr_to_actors[i]);
            free(ptr_to_actors);                                  // Deallocate actors array itself
            exit(1);
        }
    }

    // movie->curr_size points to last empty place
    movie->actors[movie->size] = (char*)malloc(sizeof(char) * (strlen(actor)+1) );        // Allocate enough space to store the 'actor' into the actors array
    exit_on_null(movie->actors[movie->size], "insertSample():: NULL returned from actor slot allocation\n");

    strcpy(movie->actors[movie->size], actor);
    movie->size += 1;
    return movie;
}

void printMovieActors(MOVIE* movie){
    int i;
    for(i = 0; i < movie->size; i++)
        printf("%s\n",movie->actors[i]);
    printf("\n");
}


void printMovie(MOVIE* movie){
    int i;
    printf("Title: %s\n", movie->title);
    printf("Actors-->\n");
    for(i = 0; i < movie->size; i++)
        printf("%s\n",movie->actors[i]);
    printf("\n");
}