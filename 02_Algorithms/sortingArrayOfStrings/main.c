#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    if( strcmp(a,b) == 1 ){
        return 1;
    }
    
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    if( strcmp(a,b) == -1 ){
        return 1;
    }
    
    return 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int arrayA[255] = {0};
    int arrayB[255] = {0};
    
    char* tmpA = a, tmpB = b;
    int countA = 0, countB = 0;
    
    // Calculate number of diff chars of string a
    while(*tmpA){
        arrayA[*tmpA] = *tmpA;
        *tmpA++;
    }
    int i = 255;
    while(i){
        
        if(arrayA[i]){
            countA++;
        }
        
        i--;
    }
    // 
    while(*tmpB){
        arrayB[*tmpB] = *tmpB;
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

int sort_by_length(const char* a, const char* b) {
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

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i,j,tmp;
    for(i = 0; i < len-1; i++){
        for(j = i+1; j < len-1;j++){
            tmp = cmp_func(arr[j],arr[j+1]);
            if(tmp){
                // swap j and j+1
                int* pointer = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = pointer;
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
