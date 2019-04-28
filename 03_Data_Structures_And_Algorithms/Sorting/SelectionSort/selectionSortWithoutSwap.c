#include<stdio.h>

void printArr(int* A, int n){
  int i;
  for(i = 0; i < n; i++)
    printf("%d ", A[i]);
}

void SelectionSort(int* A, int n){
  int i,j;
  int min, minYer; 

  for(i = 0; i < n-1; i++){
    min = A[i];
    minYer = i;

    for(j = i+1; j < n; j++)
      if( min > A[j] ){
        min = A[j];
        minYer = j;
      }
     
    A[minYer] = A[i];
    A[i] = min; 
  }
 
}

int main(int argc, char* argv[]){

  int arr[5] = {8,1,5,2,4};
  int n = 5;

  SelectionSort(arr,n);
  printArr(arr,n);

return 0;
}
