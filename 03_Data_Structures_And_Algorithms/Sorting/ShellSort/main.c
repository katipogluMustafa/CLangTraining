#include<stdio.h>

void printArray(int A[], int n){
  int i;
  for(i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");
}

/*

void insertionSort(int A[],int n){
  int i,j, temp;
  for(i = 1; i <= n-1; i++){
    j = i-1;
    temp = A[i];
    while( j >= 0 && temp < A[j] ){
      A[j+1] = A[j];
      j -= 1;
    }
    A[j+1] = temp;
  }

}

*/

// TRICK: write insertion sort then change the every '1' inside insertionSort into 'k' then that's the shell sort
void shellSort(int A[], int n){
  int i,j,k,temp;
 
  for( k = n/4; k >= 1; k /= 2 )
    for( i = k; i <= n-k; i += k){
      temp = A[i];
      j = i-k;
      while( j >= 0 && temp < A[j] ){
        A[j+k] = A[j]; 
        j -= k; 
      } 
      A[j+k] = temp;
    }

}

int main(){
  
   
  int A[] = {45, 25, 46, 48, 28, 6, 13, 5, 36, 44, 7, 4, 11, 30, 24, 34, 15, 31, 38, 49};
  
  printf("Shell Sort: \t");
  shellSort(A, 20);
  printArray(A, 20);

return 0;
}
