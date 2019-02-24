#include<stdio.h>

/* Takes Inputs from Command Line*/ 

void swap(int* x, int* y){

        int temp = *x;
        *x = *y;
        *y = temp; 

}

void printArr(int A[], int n){
        int i;
        for(i = 0; i < n; i++)
                printf("%d ", A[i]);
}

void BubbleSort(int* A, int n){

        int j, i = 0, flag = 1;

        while( i < n-1 && flag ){
                flag = 0;
                for(j = 0; j < n -1 -i; j++)
                        if(A[j] > A[j+1]){
                                swap(&A[j], &A[j+1]);
                                flag = 1;
                        }
                i++;
        }
}


int main(int argc, char* args[]){

       int A[5] = {8,3,4,2,5};
       BubbleSort(A, 5);
       printArr(A,5);


return 0;
}


