#include<stdio.h>

void printArr(int* A, int n){
  int i;
        for(i = 0; i < n; i++)
                printf("%d ", A[i]);
}

void swap(int* x, int* y){

  int temp = *x;
  *x = *y;
  *y = temp;

}

void SelectionSort(int* A, int n){
  int i,j,k;
  for(i = 0; i < n-1; i++){
  k = i;
    for(j = i+1; j < n; j++){
        if( A[j] < A[k])
          k = j;
    }
  swap(&A[i], &A[k]);
  }

}

int main(int argc, char* argv[]){

  int arr[5] = {8,1,5,2,4};
  int n = 5;

  SelectionSort(arr,n);
  printArr(arr,n);

return 0;
}
