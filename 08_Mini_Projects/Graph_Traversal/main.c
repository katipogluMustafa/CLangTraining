#include "def.h"

#define DYNAMIC_INPUT  0            // 1 for dynamic, 0 for static input

void printMenu();
int check_user_menu_choice(char buffer[256], MOVIES *movies, HASH_TABLE *ht, GRAPH *graph);

void menu_choice_one(MOVIES*, HASH_TABLE *ht, GRAPH *graph);
void menu_choice_two(MOVIES*, HASH_TABLE *ht, GRAPH *graph);
void menu_choice_three(MOVIES*, HASH_TABLE *ht, GRAPH *graph);
void menu_choice_four(MOVIES*, HASH_TABLE *ht, GRAPH *graph);
void menu_choice_five(MOVIES*, HASH_TABLE *ht, GRAPH *graph);

int main() {
    FILE* input_file;                       // input fle pointer
    bool is_accepted = FALSE;               // validity of dynamic user file input
    int choice = -1;                        // action number chosen by user

    char buffer[256];                       // temp buffer used when taking choice and input from user

    if( DYNAMIC_INPUT == 0 ) {
        input_file = fopen("in.txt", "r");
        exit_on_null(input_file, "input_file can not be opened...");
    }else{
        do{
            printf("File Name: ");
            scanf("%255s", buffer);
            input_file = fopen(buffer, "r");
            if( input_file != NULL ) {
                is_accepted = TRUE;
                printf("File successfully opened...\n");
            }
            else
                fprintf(stderr, "File %s cannot be opened...\n", buffer);
        }while( is_accepted == FALSE);
    }
    MOVIES* movies = ReadInput(input_file);                     // Parse the input file and return a pointer to MOVIES
    HASH_TABLE* ht = hashTableFactory();
    GRAPH* G = PrepareGraph(movies,ht);
    fclose(input_file);                                         // deallocate the input file

    printMenu();                                                // show user menu
    do{
        printf("\nchoice: ");
        scanf("%s",buffer);                                     // Take user choice for action to be taken
        choice = check_user_menu_choice(buffer, movies, ht, G);        // Execute user choice
    }while(choice != 0);                                        // Loop until user presses '0' to quit

    free_movies(movies);                                        // deallocate all inputs
    return 0;
}

int check_user_menu_choice(char buffer[256], MOVIES *movies, HASH_TABLE *ht, GRAPH *graph) {
    int choice = -1;
    void (*f)() = printMenu;                // By default call print menu

    switch(*buffer){        // switch on first char
        case '0':
            choice = 0;
            return choice;
        case '1':
            choice = 1;
            f = menu_choice_one;
            break;
        case '2':
            choice = 2;
            f = menu_choice_two;
            break;
        case '3':
            choice = 3;
            f = menu_choice_three;
            break;
        case '4':
            choice = 4;
            f = menu_choice_four;
            break;
        case '5':
            choice = 5;
            f = menu_choice_five;
            break;
    }

    f(movies,ht,graph);

    return choice;
}

void menu_choice_five(MOVIES* movies, HASH_TABLE *ht, GRAPH *graph) {
    printf("Choice 5 is executing....\nCurrently Takes Static Input\n");
    long srcVertex;
    long destVertex;
    char* src = malloc(sizeof(char) * 256);
    char* dest = malloc(sizeof(char) * 256);

    strcpy(src, "Tocantins, Nicole");
    strcpy(dest, "Ruccolo, Richard");

    srcVertex = getHash(ht,src);
    destVertex = getHash(ht,dest);

    if( srcVertex == -1 || destVertex == -1 ){
        printf("Cant find the name in the graph...\n");
        return;
    }

    BFS(graph,ht,srcVertex,destVertex);
}

void menu_choice_four(MOVIES* movies, HASH_TABLE *ht, GRAPH *graph) {
    printf("Choice 4 is executing.... ");
    printGraphConnections(graph,ht);
}

void menu_choice_three(MOVIES* movies, HASH_TABLE *ht, GRAPH *graph) {

}

void menu_choice_two(MOVIES* movies, HASH_TABLE *ht, GRAPH *graph) {
    printf("Choice 2 is executing....");

    char** titles = getAllMovies(movies);
    printStringArray(titles, MAX_NO_OF_MOVIES);
}

void menu_choice_one(MOVIES* movies, HASH_TABLE *ht, GRAPH *graph){
    printf("Choice 1 is executing....");
    char** artists = getAllArtists(movies);
    printStringArray(artists,-1);
}

void printMenu() {
    printf("0 ~ Quit\n");
    printf("1 ~ Show All Actors\n");
    printf("2 ~ Show All Movie Titles\n");
    printf("3 ~ Print Movie Details\n");
    printf("4 ~ Print Graph Connections\n");
    printf("5 ~ Search\n");
}

