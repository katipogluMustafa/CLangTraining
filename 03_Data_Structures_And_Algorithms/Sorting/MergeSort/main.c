#include<stdio.h>
#include<stdlib.h>


void merge(int A[], int l, int mid, int h){
   
  int i,j,k;

  int* B = (int*) malloc(sizeof(int) * (h-l+1) );

  if( B == NULL)
    return;
 
  i = l;
  j = mid + 1;
  k = 0;
  
  while(i <= mid && j <= h){
    if( A[i] < A[j] )
      B[k++] = A[i++];
    else
      B[k++] = A[j++]; 
  }

  while( i <= mid )
    B[k++] = A[i++];

  while( j <= h )
    B[k++] = A[j++];

  for(i = l,k=0; i <= h; i++,k++)
    A[i] = B[k];
  
  free(B);
}

void mergeSort(int A[], int l, int h){
  
  if( l < h){

    int mid = (l + h)/2;
    mergeSort(A, l, mid);
    mergeSort(A, mid+1, h);
    merge(A, l, mid, h);

  }

}

int main(){
  
  int A[] = {1,3,5,7,9,0,2,4,6,8};

  merge(A,0,4,9);
  
  for(int i = 0; i < 10; i++)
    printf( "%d ", A[i] );

  int B[] = {0,3,2,4,1,5,6,8,7,9,10};
  mergeSort(B, 0, 10);

  printf("\n");

  for(int i = 0; i < 11; i++)
    printf( "%d ", B[i] );


 
return 0;
}
