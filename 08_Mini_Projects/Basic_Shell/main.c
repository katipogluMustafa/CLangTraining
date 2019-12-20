#ifndef MKSHELL_SH_INTERPRETER_H
#define MKSHELL_SH_INTERPRETER_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


/****************************************************************************************/
/***************************** Type Declarations and MACROs**************************/
/****************************************************************************************/
typedef int bool;
#define TRUE 1
#define FALSE 0

#define STR_VALUE(x) STR(x)
#define STR(x) #x

#define MAX_PATH_LENGTH 255
#define BUFFER_LENGTH 255

/****************************************************************************************/
/***************************** History Functions *****************************************/
/****************************************************************************************/
typedef struct history{
    char** data;
    int size;
    int capacity;
}HISTORY;

HISTORY* historyFactory(int initial_capacity);
HISTORY* insertCommandIntoHistory(HISTORY* history, char* command);
void printHistory(HISTORY* history);
/****************************************************************************************/
/***************************** SHELL Command Interpreting ******************************/
/****************************************************************************************/
void sh_interpret(char *buffer, HISTORY *history);

char** parseArguments(char* str);
bool is_cmd(char *str, HISTORY *history);
bool execute_pipe_cmd(char **args, char *ptr_to_pipe);
bool execute_pipe_child(char** args, char* ptr_to_pipe);
bool execute_cmd(char **args, HISTORY *history, bool should_wait);
/****************************************************************************************/
/***************************** Helper Functions *****************************************/
/****************************************************************************************/
char* sh_get_working_directory();
char* clear_string(char* str);
void exit_on_null(void* ptr, const char* msg);

int main() {
    char buffer[BUFFER_LENGTH];                                             // Buffer for user input
    HISTORY* history = historyFactory(16);
    int flag = 1;
    char* cwd = sh_get_working_directory();
    printf("[%s@%s %s]\n","Yukawa", "Home", cwd);
    do{
        printf("$");                                                      // Configure shell prompt
        fgets(buffer, BUFFER_LENGTH - 1, stdin);                            // Read user input until next line character
        if(strcmp(buffer, "q!") == 0)
            flag = 0;
        else {
            history = insertCommandIntoHistory(history, buffer);
            sh_interpret(buffer, history);                                               // execute the command
        }
    }while( flag );

    fprintf(stdout,"\nExiting...");
    free(cwd);
    exit(0);
}

void sh_interpret(char *buffer, HISTORY *history) {
    if( buffer == NULL || strlen(clear_string(buffer)) == 0 )
        return;

    char* ptr = strstr(buffer, ";");
    bool is_multi_command = FALSE;
    if( ptr != NULL ) {   // if matches ptr would be pointing to semicolon but now to the char after semicolon
        *ptr = '\0';
        is_multi_command = TRUE;
    }

    char* copy_buffer = malloc(sizeof(char) * strlen(buffer));
    strcpy(copy_buffer, buffer);                                                // take deep copy, to not to change original buffer
    char* str = clear_string(copy_buffer);                                      // clear preceding whitespace and trailing \n \r

    if(is_cmd(str, history) == FALSE)                                   // Try to execute command with is_cmd
        printf("%s: command not found\n", str);

    if( is_multi_command )
        sh_interpret(++ptr, history);                               // recursively handle the command

    free(copy_buffer);
    free(str);

}

char** insert_argument(char** args,int* size, int* capacity, char* str){         // size points to last empty space
    if( str == NULL )
        return args;                    // assuming array is full of NULL, if input is NULL no need to insert

    if( *size == *capacity ){
        *capacity *= 2;
        args = realloc(args, sizeof(char*) * *capacity);
        if( args == NULL ){
            fprintf(stderr, "insert_argument()::Realloc returned NULL\n");
            exit(1);
        }
        for(int i = *size; i < *capacity; i++)
            args[i] = NULL;                                     // make sure new allocated init to NULL
    }

    args[*size] = malloc(sizeof(char) * strlen(str));
    strcpy(args[*size], str);
    *size += 1;
    return args;
}

bool execute_cmd(char **args, HISTORY *history, bool should_wait) {
    char* cmd = args[0];
    bool exit_flag = FALSE;                             // Exit the execute_cmd function

    if(strcmp(cmd, "clear") == 0) {
        printf("\033[H\033[J");                 // clear the screen
        exit_flag = TRUE;
    }else if( strcmp(cmd, "cd") == 0){
        if( args[1] == NULL  || strcmp(args[1], "~") == 0)
            chdir(getenv("HOME"));
        chdir(args[1]);
        exit_flag = TRUE;
    }else if( strcmp(cmd, "history") == 0 ) {
        printHistory(history);
        exit_flag = TRUE;
    }

    if( exit_flag == TRUE )
        return exit_flag;


    int ret = fork();
    if( ret < 0  ){
        fprintf(stderr, "execute_cmd()::Error while forking\n");
        exit(1);
    }
    int status;
    if( ret == 0  && execvp(cmd, args) == -1)            // inside child execute execvp
        return FALSE;
    else if( should_wait == TRUE )                      // inside parent wait if should_wait
        wait(&status);
    else
        return TRUE;                                // Assuming the command we've started will execute

    if( WEXITSTATUS(status) == 0)
        return TRUE;

    return FALSE;
}

// Takes command and returns cmd at args[0], params at each slot of args array
char** parseArguments(char* str){
    char* token = strtok(str, " ");
    int capacity = 2;
    int size = 0;                                                   // args wll store each command argument
    char** args = (char**)calloc(capacity,sizeof(char*));           // Allocate and init each slot to NULL

    while( token != NULL ){
        args = insert_argument(args, &size, &capacity, token);
        token = strtok(NULL, " ");
    }
    args[size] = NULL;                                              // Make sure last space is NULL
    return args;
}

// Try to execute command, if we can execute than it is a command
bool is_cmd(char *str, HISTORY *history) {
    bool rv;
    bool is_pipe = FALSE;
    if( str == NULL )
        return FALSE;

    char* ptr_to_pipe;
    if( (ptr_to_pipe = strstr(str, "|")) != NULL ) {      // if not null this means cmd contains pipe
        is_pipe = TRUE;
        *ptr_to_pipe = '\0';
        ptr_to_pipe += 1;                                       // ptr_to_pipe points to first char after pipe
    }

    char** args = parseArguments(str);

    // Handle background task '&'
    bool should_wait = TRUE;
    int i;
    for(i = 0; args[i] != NULL;i++);
    // now i is the index of the null inside of args array
    char* ptr;
    if( (ptr = strstr(args[i-1], "&")) != NULL){
        should_wait = FALSE;
        *ptr = '\0';
    }

    if(is_pipe == TRUE )
        rv = execute_pipe_cmd(args,ptr_to_pipe);
    else
        rv = execute_cmd(args, history,TRUE);                              // send cmd and null terminated array of arguments;

    for(int i = 0; args[i] != NULL; i++)
        free(args[i]);
    free(args);
    return rv;
}

bool execute_pipe_child(char** args, char* ptr_to_pipe){
    int rv;
    int pipe_fd[2];
    pipe(pipe_fd);              // Create pipe
    int status;
    rv = fork();
    if(rv < 0) {
        fprintf(stderr, "execute_pipe_child()::Error while forking\n");
        exit(1);
    }else if( rv == 0 ){      // inside child, Executes left of the pipe
        close(pipe_fd[0]);                      // Close the read end of the pipe
        dup2(pipe_fd[1], stdout);               // redirect pipe write end to the stdout
        // so this process gives its output to the pipes write end
        if( execvp(args[0], args) == -1)       // try to exec, if not and returns -1  then return FALSE as saying this cmd not working
            return FALSE;
    }else{                  // inside parent, Executes right of the pipe
        close(pipe_fd[1]);                      // Close the write end of the pipe
        dup2(pipe_fd[0], stdin);                // redirect pipe read end to stdin
        // so this process takes its input from the pipes read end

        char** pipe_right_cmd_args = parseArguments(ptr_to_pipe);  // assuming only one pipe
        if( execvp(pipe_right_cmd_args[0],pipe_right_cmd_args) == -1)
            return FALSE;
    }

    return TRUE;
}

bool execute_pipe_cmd(char **args, char *ptr_to_pipe) {
    int rv = fork();
    int status;

    if( rv < 0 ) {
        fprintf(stderr, "execute_pipe_cmd()::Error while forking\n");
        exit(1);
    }else if( rv == 0 )         // inside child
        return execute_pipe_child(args,ptr_to_pipe);                       // child will execute cmd and pipe commands
    else                       // inside parent {Shell Process}
        wait(&status);          // wait pipe commands to execute as the shell process

    if( WEXITSTATUS(status) == 0)               // Does child exited properly ? if yes
        return TRUE;                            // return TRUE to show cmd successfully has been executed

    return FALSE;
}

/****************************************************************************************/
/***************************** History Functions *****************************************/
/****************************************************************************************/

// Create a MOVIE object with given capacity for the actors array
HISTORY* historyFactory(int initial_capacity){
    if(initial_capacity < 0 )
        initial_capacity = 1;               // initial capacity can not be less than 1

    HISTORY* history = (HISTORY*)malloc(sizeof(HISTORY));
    exit_on_null(history, "historyFactory():: Malloc Returned NULL when allocating HISTORY");

    history->size = 0;
    history->capacity = initial_capacity;
    history->data = (char**)malloc(sizeof(char*) * initial_capacity);
    exit_on_null(history->data, "historyFactory():: Malloc Returned NULL when allocating MOVIE for HISTORY");

    return history;
}

// Dynamically insert a MOVIE into HISTORY
HISTORY* insertCommandIntoHistory(HISTORY* history, char* command){
    if(history == NULL )
        history = historyFactory(16);

    char** ptr_to_history_data;
    if(history->size >= history->capacity ){
        history->capacity *= 2;
        ptr_to_history_data = history->data;                                  // in case realloc returns NULL, secure the pointer to the history data
        history->data = (char**)realloc(history->data, sizeof(char *) * history->capacity);
        if(history->data == NULL ){                                       // If reallac returns NULL then Deallocate everything u allocated so far
            fprintf(stderr, "insertCommandIntoHistory():: NULL returned from realloc\n");
            int i;
            for(i = 0; i < history->size; i++)                            // Deallocate each history command
                free(ptr_to_history_data[i]);
            free(history);                                               // Deallocate history itself
            exit(1);
        }
    }

    history->data[history->size] = (char*)malloc(sizeof(char) * (strlen(command)+1));
    strcpy(history->data[history->size],command);
    history->size += 1;
    return history;
}

/****************************************************************************************/
/***************************** Helper Functions *****************************************/
/****************************************************************************************/


void printHistory(HISTORY* history){
    int i;
    for(i = 0; i < history->size; i++)
        printf("%d - %s",i,history->data[i]);
}

void exit_on_null(void* ptr, const char* msg){
    if( ptr != NULL )
        return;
    fprintf(stderr,"Crash!\tExiting The Program: %s!\n",msg);
    exit(1);
}

char* sh_get_working_directory() {
    char* buffer = malloc(sizeof(char) * MAX_PATH_LENGTH);

    if( getcwd(buffer, MAX_PATH_LENGTH)  == NULL )
        strcmp(buffer, "--__--");

    return buffer;
}

char* clear_string(char* str){
    int size = strlen(str);
    int i = 0;
    while(*str == ' ' && i < size ) {
        str++;                                                          // No Preceding White Space
        i++;
    }
    char* ptr = str;
    while(i < size && *str != '\0' && *str != '\n' && *str != '\r')
        str++;

    if( *str != '\0' && i >= size-1)
        return NULL;

    *str = '\0';                                                        // No Trailing \n \r

    char* string = (char*)malloc(sizeof(char) * strlen(ptr));
    strcpy(string, ptr);

    return string;
}