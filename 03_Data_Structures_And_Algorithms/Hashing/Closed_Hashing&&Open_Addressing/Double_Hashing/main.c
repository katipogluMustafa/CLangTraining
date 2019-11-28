#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IS_UNIX 1                                   // !!!!!!!!!!!! 0 for windows, 1 for POSIX Complient Systems

#if IS_UNIX == 0
    #include<unistd.h>
#endif

#define MAX_SAMPLE_FILE_NAME_LENGTH 512             // For sample.doc
#define HT_SIZE 5                                  // !!!!!!!!!!!!!! M for Hash Table, table_size / 0.6
#define M HT_SIZE
#define MAX_WORD_LENGTH 256                          // For words in the documents
//#define R 31                                        // The Prime Number used when Hashing
#define R 1                                        // For Reporting


typedef struct sample_struct{
    char** names;
    int size;                               // Current size     // size points to last empty place in names array
    int capacity;                           // Max Capacity
} SAMPLES;

/* Sample Type Specific Functions */
SAMPLES* LoadSamples();
void insertSamplesIntoHT(SAMPLES* samples, char* hash_table[]);

/* Helper Functions Prototypes*/
void exit_on_null(void* ptr, const char* msg);
void printHashTable(char* hash_table[]);
void change_current_working_directory(const char* path, const char* callerFuncName, const char* msg);
void printSamples(SAMPLES samples);

/* Hash Functions Prototypes*/
unsigned long find_file_key(FILE* file);
int hash(unsigned long file_key, int i);
int hash1(unsigned long file_key);
int hash2(unsigned long file_key);

void CreateTheHashTable(char* hash_table[]){
    SAMPLES* samples =  LoadSamples();                      // Get Existing Files in the Database as array
    int i;
    for(i = 0; i < HT_SIZE; i++)
        hash_table[i] = NULL;                               // init Hash Table with NULLs

    insertSamplesIntoHT(samples, hash_table);               // Hash each sample and insert into hash_table
}

int compare_files(FILE* document, int doc_hash, char* hash_table[]){
    long initial_position = ftell(document);                            // Secure the file pointers initial position
    fseek(document,0,SEEK_SET);                                         // Set the file pointer to first byte

    change_current_working_directory("Documents","compare_files","");
    FILE* doc_at_table = fopen(hash_table[doc_hash], "r");  // Open the file at the 'hash' location
    exit_on_null(doc_at_table, "compare_files()::Can not open the file in the hash table");
    change_current_working_directory("..","compare_files","");

    int flag = 1;                                                       // boolean flag to show whether both files point to the same char value
    int ret_value = 0;                                                  // 0 means files are different
    while( !feof(document) && !feof(doc_at_table) && ( flag = (fgetc(document)==fgetc(doc_at_table)) ) );
    // if both of them at their EOF then while loop exited because files have different contents
    if( ( feof(document) == feof(doc_at_table) ) && flag == 1)
        ret_value = 1;

    fseek(document, initial_position, SEEK_SET);
    return ret_value;
}

void copyFile(FILE* dest, FILE* src){
    printf("Starting to Copy...\n");
    long curr_position = ftell(src);
    fseek(src,0,SEEK_SET);

    char tmp;
    while( (tmp = fgetc(src)) != EOF)
        fputc(tmp,dest);

    fseek(src, curr_position, SEEK_SET);
}

void insertFileIntoDocuments(FILE* document, const char* doc_name){
    FILE *doc, *samples;
    // Open and Write The File Name into samples.doc
    samples = fopen("Index.txt","a");
    exit_on_null(samples,"insertFileIntoDocuments()::samples.doc can not be opened...");
    fprintf(samples,"\n%s",doc_name);
    fclose(samples);

    // Copy the File Content Into a file created in Documents with the same name as input document
    change_current_working_directory("Documents","insertFileIntoDocuments","gate 1");
    doc = fopen(doc_name,"a+");
    exit_on_null(doc,"insertFileIntoDocuments()::doc is NULL...");
    change_current_working_directory("..","insertFileIntoDocuments","gate 2");
    copyFile(doc, document);
    fclose(doc);
}


void insertIntoHT(FILE* document, char* doc_name, char* hash_table[]){
    long key = find_file_key(document);
    int i = 0, flag = 1;
    int is_same = 0;
    int doc_hash = hash(key,0);
    printf("\nDocument_Hash = %d\n", doc_hash);

    while( i < M && flag ){
        if( hash_table[doc_hash] == NULL ){
            printf("Slot is empty, inserting...");
            printf("Hash:%d\n", doc_hash);
            insertFileIntoDocuments(document,doc_name);
            hash_table[doc_hash] = malloc(sizeof(char) * strlen(doc_name));
            strcpy(hash_table[doc_hash], doc_name);
            flag = 0;                                               // leave the loop
        }else{
            is_same = compare_files(document,doc_hash,hash_table);
            if( is_same ) {
                printf("Files are the same... No action is needed...\n");
                flag = 0;                                           // leave the loop
            }else{
                doc_hash = hash(key, ++i);
                printf("Slot is full,Files are diffent, calculate new hash: %d\n", doc_hash);
            }
        }
    }
}

int main() {
    char* hash_table[HT_SIZE];
    int flag = 1;                                       // keep track of whether input file name is properly taken or not
    int again = 1;
    char file_name[MAX_SAMPLE_FILE_NAME_LENGTH];        // Buffer for input file name
    FILE *document;                                     // Pointer to the input file

    printf("Hash Table State:\n");
    CreateTheHashTable(hash_table);                     // Init hash table and insert samples in it
    printHashTable(hash_table);
    printf("Press q -> quit\n");
    do{
        do {
            printf("\nFile Name:");
            scanf("%s", file_name);
            if( strcmp(file_name,"q") == 0) {             // "q" input for quiting...
                printf("Leaving...\n");
                flag = 0;                                 // leave inner loop
                again = 0;                                // leave outer loop
            }else{
                document = fopen(file_name, "r");
                if (document != NULL){
                    printf("File Successfully opened, starting the Process...\n");
                    flag = 0;                                                                   // succesfully opened ,leave inner loop
                }else{
                    printf("File could not be opened, please try another file!\n");
                }
            }
        }while(flag == 1);                              // Loop until user gives a file name that can be opened successfully
        if( again == 1 )
            insertIntoHT(document,file_name,hash_table);
    }while(again == 1);



    return 0;
}

/****************************************************************************/
/***************************** SAMPLE Functions *****************************/
/****************************************************************************/

SAMPLES* LoadSamples(){
    SAMPLES* sampleFactory(int capacity);
    char* extract_name_from_buffer(char* buffer);
    SAMPLES* insertSample(SAMPLES* samples, const char* str);

    FILE* samples_file = fopen("Index.txt", "r");
    exit_on_null(samples_file, "index.txt can not be opened");

    char buffer[MAX_SAMPLE_FILE_NAME_LENGTH];
    char* curr_name;

    SAMPLES* samples = sampleFactory(2);

    while( fgets(buffer, MAX_SAMPLE_FILE_NAME_LENGTH, samples_file) != NULL ) {
        curr_name = extract_name_from_buffer(buffer);
        samples = insertSample(samples, curr_name);
    }

    fclose(samples_file);
    return samples;
}

// Insert Samples Into Hash Table
// sample.doc only contains those that has unique hashes
void insertSamplesIntoHT(SAMPLES* samples, char* hash_table[]){
    int i,j,flag, curr_hash;
    FILE* curr_file;
    char* curr_file_name;
    change_current_working_directory("Documents", "insertSamplesIntoHT()","");

    for(i = 0;i < samples->size; i++){          // For each file name inside of the samples
        curr_file_name = samples->names[i];
        curr_file = fopen(curr_file_name, "r");
        exit_on_null(curr_file,"insertSamplesIntoHT():: The File with given name can not be opened!");
        flag = 1;                               // Keep track of whether we get the hash or not
        j = 0;                                  // iterator for double hashing
        unsigned long key = find_file_key(curr_file);
        // j = 0 means no double hashing just hashing
        while( flag && j < M ){
            curr_hash = hash(key,j);
            if( curr_hash < M && hash_table[curr_hash] == NULL ){           // Make sure hash does not point to out of range
                // We found the hash the we place the item in, just insert name of the file into its place
                hash_table[curr_hash] = (char*)malloc(sizeof(char) * strlen(curr_file_name));
                strcpy(hash_table[curr_hash], curr_file_name);
                flag = 0;                                                   // Leave the loop we got the hash
            }else{
                ++j;                                                        // Increase the 'j' for double hashing
            }
        }
        fclose(curr_file);
        if( j >= M ) {                          // table is full
            fprintf(stderr, "TABLE IS FULL: Can't find any empty slot in hash table when inserting Sample!!");
            exit(1);
        }
    }

    change_current_working_directory("..", "insertSamplesIntoHT()","");
}

// Dynamically insert a string into samples
SAMPLES* insertSample(SAMPLES* samples, const char* str){
    SAMPLES* sampleFactory(int capacity);

    if( samples == NULL )
        samples = sampleFactory(2);

    char** ptr_to_names;
    if( samples->size >= samples->capacity ){
        samples->capacity *= 2;
        ptr_to_names = samples->names;                              // in case realloc returns NULL, secure the pointer to the names
        samples->names = (char**)realloc(samples->names, sizeof(char*) * samples->capacity);
        if( samples->names == NULL ){                               // If reallac returns NULL then Deallocate everything u allocated so far
            fprintf(stderr, "insertSample():: NULL returned from realloc\n");
            int i;
            for(i = 0; i < samples->size; i++)                      // Deallocate each string inside of the names array
                free( ptr_to_names[i]);
            free(ptr_to_names);                                     // Deallocate names array itself
            exit(1);
        }
    }

    // samples->size points to last empty place
    samples->names[samples->size] = (char*)malloc( sizeof(char) * strlen(str) );        // Allocate enough space to store the 'str' into the names array
    exit_on_null(samples->names[samples->size], "insertSample():: NULL returned from string slot allocation\n");

    strcpy(samples->names[samples->size], str);
    samples->size += 1;
    return samples;
}

// Create a SAMPLES object with given capacity
SAMPLES* sampleFactory(int capacity){
    if( capacity < 0 )
        capacity = 1;               // initial capacity can not be less than 1

    SAMPLES* samples = (SAMPLES*)malloc(sizeof(SAMPLES));
    exit_on_null(samples, "sampleFactory():: Malloc Returned NULL when allocating SAMPLE");

    samples->size = 0;
    samples->capacity = capacity;
    samples->names = (char**)malloc(sizeof(char*) * capacity);

    return samples;
}

void printSamples(SAMPLES samples){
    int i;
    printf("\n\nPrinting Samples:\n");
    for(i = 0; i < samples.size; i++)
        printf("\t --- %s\n", samples.names[i]);
    printf("\n");
}

char* extract_name_from_buffer(char* buffer){
    if( buffer == NULL )
        return NULL;

    int len = strlen(buffer);
    char* name = buffer;
    while( *buffer != '\0' && *buffer != '\r' && *buffer != '\n'){
        buffer++;
    }
    *buffer = '\0';

    return name;
}

/****************************************************************************/
/***************************** Helper Functions *****************************/
/****************************************************************************/

void change_current_working_directory(const char* path, const char* callerFuncName, const char* msg){
#if IS_UNIX == 1
    if( chdir(path) != 0 ){
        fprintf(stderr, "%s::Can not change the current directory::%s\n", callerFuncName, msg);
        exit(1);
    }
#else
    char command[MAX_SAMPLE_FILE_NAME_LENGTH +  3];
    strcpy(command, "cd ");
    strcat(command, path);
    strcat(command, "\0");
    if( system(command) != 1 ){
        fprintf(stderr, "Exiting... %s::%s::system(path) function does not change current directry!!!%s\n", callerFuncName,"change_current_working_directory()", msg);
        exit(1);
    }
#endif
}

void exit_on_null(void* ptr, const char* msg){
    if( ptr != NULL )
        return;
    fprintf(stderr,"Crash!\tExiting The Program: %s!\n",msg);
    exit(1);
}

void printHashTable(char* hash_table[]){
    int i;
    for(i = 0; i < M; i++)
        if( hash_table[i] != NULL )
            printf("%d::%s\n", i,hash_table[i]);
}

/****************************************************************************/
/***************************** Hash Functions *****************************/
/****************************************************************************/
unsigned long find_file_key(FILE* file){
    char buffer[MAX_WORD_LENGTH];
    int i,j,k;
    char ch;
    unsigned long file_key = 1, curr_word_key;

    ch = getc(file);
    while( ch != EOF ){
        i = 0;
        while( ch != EOF && ch != ' ' && ch != '\n' && ch != '\r'){             // Read a Word From The File
            buffer[i++] = ch;
            ch = getc(file);
        }
        buffer[i] = '\0';                                                      // put \0 at the end of the word

        //while(ch != EOF && (ch == ' ' || ch == '\n' || ch == '\r') )          // UNCOMMENT TO Bypass these escape characters
            ch = getc(file);

        if(strlen(buffer) == 0)
            continue;                       // if buffer is empty skip calculating key part

        // Calculate its key
        curr_word_key = 0;                   // Currently buffer has 0..i chars
        for( j =  i-1, k = 0; j > 0; j--, k++)
            curr_word_key += buffer[k] * pow(R, j);

        file_key ^= curr_word_key;
    }

    return file_key;
}


int hash1(unsigned long file_key){
    return file_key % M;
}

int hash2(unsigned long file_key){
    return 1 + ((file_key) % (M - 1));
}

int hash(unsigned long file_key, int i){
    return (hash1(file_key) + i * hash2(file_key)) % M;         // i > 0 --> Double Hashing
}