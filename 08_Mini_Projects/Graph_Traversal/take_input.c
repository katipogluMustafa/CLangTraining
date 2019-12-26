//
// Created by Yukawa on 2019-12-20.
//

#include "def.h"

MOVIES* ReadInput(FILE* file){
    char buffer[BUFFER_SIZE+1];
    char* temp;
    char* actor;
    char* movie;
    unsigned long len;
    MOVIE* currMovie;
    MOVIES* movies = moviesFactory(16);

    while( fgets(buffer, BUFFER_SIZE, file) != NULL ){
        currMovie = movieFactory(4);
        len = strlen(buffer);
        buffer[len - 1] = DELIMITER;                    // Make sure last char in the buffer is the DELIMETER

        // For Windows
        if (len > 1 && buffer[len-2] == '\r')
        {
            buffer[len-2] = DELIMITER;
            buffer[len-1] = '\0';
        }

        // extract movie title
        temp = movie = buffer;
        temp = strchr(temp, DELIMITER);
        *temp++ = '\0';
        currMovie->title = malloc(sizeof(char) * (strlen(movie)+1));
        strcpy(currMovie->title, movie);

        // extract actors
        actor = temp;
        while((temp = strchr(temp, DELIMITER)) != NULL) {
            *temp++ = '\0';
            currMovie = insertActor(currMovie, actor);
            actor = temp;
        }
        movies = insertMovie(movies, currMovie);
    }

    return movies;
}
