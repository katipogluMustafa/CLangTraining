#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* This is comment */

int main(int argc, char *argv[]){

    // This is also comment

    int distance;
    time_t t;

    /* Initialize random number generator */
    srand((unsigned) time(&t));

    /* Get random distance */

    distance = rand() % 5;


    if(distance == 0) {
    	printf("Hello World!\n");
    }else {
   	    printf("You are %d miles away From Earth.\n", distance);

    }

    return 0;
}

// Use $ make exc1 to run it