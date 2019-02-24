#include<stdio.h>

void printArr(int* Arr, int n){
        int i;
        for( i = 0; i < n;i++ ){
                printf("%d ", Arr[i]);
        }
}

void InsertionSort(int* A, int n){
        int i,j,x;
        for(i = 1; i < n; i++){
                x = A[i];
                j = i-1;
                while( j >= 0 && A[j] > x ){
                        A[j+1] = A[j];
                        j--;
                }
                A[j+1] = x;
        }
}

int main(int argc, char* argv[]){

        int arr[5] = {9,1,6,2,3};
        
        InsertionSort(arr,5);
        printArr(arr,5);

return 0;
}
