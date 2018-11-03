#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// review
int lexicographic_sort(char* a, char* b) {
    if( strcmp(a,b) == 1 ){
        return 1;
    }
    
    return 0;
}
// review
int lexicographic_sort_reverse(char* a, char* b) {
    if( strcmp(a,b) == -1 ){
        return 1;
    }
    
    return 0;
}

int sort_by_number_of_distinct_characters(char* a, char* b) {
    int arrayA[255] = {0};
    int arrayB[255] = {0};
    
    char* tmpA = a;
    char* tmpB = b;
    
    int countA = 0, countB = 0;
    
    // Calculate number of diff chars of string a
    while(*tmpA){
        char tmp = *tmpA;
        arrayA[tmp] = tmp;
        *tmpA++;
    }
    int i = 255;
    while(i){
        
        if(arrayA[i]){
            countA++;
        }
        
        i--;
    }
 
    while(*tmpB){
        char tmp = *tmpB;
        arrayB[tmp] = tmp;
        *tmpB++;
    }
    i = 255;
    while(i){
        
        if(arrayB[i]){
            countB++;
        }
        
        i--;
    }
    
    if(countA > countB){
        return 1;
    }
    
    return 0;
}

int sort_by_length(char* a, char* b) {
    char* tmpA = a;
    char* tmpB = b;
    
    while(*tmpA++);
    while(*tmpB++);
    
    int lenA = tmpA - a;
    int lenB = tmpB - b;
    
    if(lenA > lenB){
        return 1;
    }else{
        return 0;
    }
    
}

void string_sort(char** arr,const int len,int (*cmp_func)(char* a, char* b)){
    int i,j,tmp;
    for(i = 0; i < len-1; i++){
        for(j = 0; j < len-1-i;j++){
            tmp = cmp_func(arr[j],arr[j+1]);
            if(tmp){
                // swap j and j+1
                int* pointer = (int*)arr[j];
                arr[j] = (int*)arr[j+1];
                arr[j+1] = (int*)pointer;
            }
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
