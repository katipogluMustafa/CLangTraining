#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int arraySize = 9;                      /* For just Debug Printing*/

void printArray(int arr[], int n){
    int i;
    for( i = 0; i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int match(int A[], int chosen ,int low, int high){
    // for now just we select first element as pivot;
    int k = low;
    while(A[k++] != chosen);        // find chosen elements index
    swap(&A[k-1], &A[low]);         // put the chosen into index low

    int pivot = A[low];
    int i = low, j = high+1;

    do{
        do{i++;}while( i < j && A[i] <= pivot );		// Until you see greater element from the pivot, increment i
        do{j--;}while( i < j && A[j] > pivot );		// Until you see lesser element from the pivot, decrement j


        swap(&A[i], &A[j]);

    }while(i <= j);

    swap(&A[i], &A[j]);             // take the last swap back

    // Now every element less than pivot is in the left side, greater ones in the right side
    // sides are separated by the j index currently

    swap(&A[low], &A[j]);           // Put pivot into its sorted position
    return j;			        // return new pivot index
}

void keyLockMatcher(int Lock[], int Key[], int l, int h){

    if( l <  h ){
        printf("\nCurrent l: %d h: %d\n",l,h);
        int i = l + rand() % ( h - l + 1);

        printf("We chosed i = %d and Key[%d] = %d\n",i,i,Key[i]);

        int x = match( Lock, Key[i], l, h);
        printf("Lock Array: \t");
        printArray(Lock, arraySize);


        match(Key, Lock[x],l, h);

        printf("Key Array: \t\t");
        printArray(Key, arraySize);

        keyLockMatcher(Lock, Key, l, x - 1);
        keyLockMatcher(Lock, Key, x + 1, h);
    }
}



int main(){
    time_t t;
    /* Initializes random number generator */
    srand((unsigned) time(&t));

/*
    int Lock[] = {7,5,4,1,2,8,9,3,6};
    int Key[]  = {5,1,7,3,4,6,2,8,9};
*/

    int Lock[] = {1,2,3,4,5,6,7,8,9};
    int Key[]  = {1,2,3,4,5,6,7,8,9};


/*
    int Lock[] = {9,8,7,6,5,4,3,2,1};
    int Key[]  = {9,8,7,6,5,4,3,2,1};
*/

/*
    int Lock[] = {1,2,3,4,5,6,7,8,9};
    int Key[]  = {9,8,7,6,5,4,3,2,1};
  */
    printf("Lock Array: \t");
    printArray(Lock, 9);
    printf("Key Array: \t\t");
    printArray(Key, 9);
    keyLockMatcher(Lock, Key, 0, 8);



/*      Take Dynamic Input

    // Take N and Allocate
    int* Key;
    int* Lock;

    int N;
    printf("N: ");
    scanf("%d", &N);
    Key = (int*)malloc(sizeof(int) * N);
    Lock = (int*)malloc(sizeof(int) * N);

    // Take Key Array
    int i;
    for(i = 0; i < N; i++){
        printf("Key[%d]: ",i);
        scanf("%d", &Key[i]);
    }
    // Take Lock Array
    for(i = 0; i < N; i++){
        printf("Lock[%d]: ", i);
        scanf("%d", &Lock[i]);
    }

    arraySize = N;                              // For Debug printing in keyLockMatcher Function
    keyLockMatcher(Lock, Key, 0, N-1);
    printArray(Lock, N);
    printArray(Key, N);
*/


    return 0;
}

