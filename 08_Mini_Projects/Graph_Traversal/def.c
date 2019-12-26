//
// Created by Yukawa on 2019-12-14.
//
#include "def.h"

void exit_on_null(void* ptr, const char* msg){
    if( ptr != NULL )
        return;
    fprintf(stderr,"Crash!\tExiting The Program: %s!\n",msg);
    exit(1);
}

void printStringArray(char** str_arr, int size){
    int i;
    printf("\n");
    if( size != -1 )                       // print with curr_size
        for(i = 0; i < size; i++)
            printf("%s\n",str_arr[i]);
    else                                  // print NULL terminated string array
        for(i = 0; str_arr[i] != NULL;i++)
            printf("%s\n", str_arr[i]);
}
