#include<stdio.h>
#include<stdlib.h>

/**
 * Merges given two sorted arrays and returns the newly created merged array
 */
int* merge(int A[], int n, int B[], int m){
  int i,j,k;
  i = j = k = 0;
  int* C = (int*)malloc(sizeof(int) * (m+n));
  
  while( i < m && j < n){
    if(A[i] < B[j])
      C[k++] = A[i++];
    else
      C[k++] = B[j++];
  }

  while(i < m)
    C[k++] = A[i++];
 
  while(j < n)
    C[k++] = B[j++];


return C;
}




int main(){
  int i;
  int A[] = {1,3,5,7,9};
  int B[] = {0,2,4,6,8};
  int* C = merge(A,5,B,5);
  for(i = 0; i < 10; i++)
    printf("%d ", C[i]);
  
return 0;
}
