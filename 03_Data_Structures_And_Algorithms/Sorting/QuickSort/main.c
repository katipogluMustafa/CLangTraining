#include<stdio.h>
#include<stdlib.h>

/**
 * Choses a pivot element then puts every element less than pivot on its left,  greater ones to its right
 * Takes An array of elements and the boundary indexes for the element
 * returns the pivot's sorted position
 */

int partitionFast(int A[], int low, int high){
  
  // for now just we select first one;
  int pivot = A[low];
  int i = low, j = high+1;
  int temp;
  
  // I think if we make j here instead of j-1 there will be error, later check this again
  do{
    do{i++;}while( i < j && A[i] <= pivot );		// Until you see greater element from the pivot, increment i
    do{j--;}while( i < j && A[j] > pivot );		// Until you see lesser element from the pivot, decrement j
    // Then A[i]<-->A[j] if i < j
    temp = A[i];	// We could have put this swap into if(i < j) but it would be expensive
    A[i] = A[j];	// since it will just only one time will do more swap when it shouldn't
    A[j] = temp;
 
  }while(i <= j);	

    temp = A[i];	// we can revert that last wrong swap back, by performing just one extra swap
    A[i] = A[j];
    A[j] = temp;

    // Now every element less than pivot is in the left side, greater ones in the right side
    // sides are seperated by the j index currently
    
    temp = A[low];		// Put pivot into its sorted position
    A[low] = A[j];
    A[j] = temp;

return j;			// return new pivot index
}


/**
 * Choses a pivot element then puts every element less than pivot on its left,  greater ones to its right
 * Takes An array of elements and the boundary indexes for the element
 * returns the pivot's sorted position
 */

int partitionSlow(int A[], int low, int high){

  // for now just we select first element as pivot;
  int pivot = A[low];
  int i = low, j = high+1;
  int temp;

  do{
    do{i++;}while( i < j && A[i] <= pivot );		// Until you see greater element from the pivot, increment i
    do{j--;}while( i < j && A[j] > pivot );		// Until you see lesser element from the pivot, decrement j

    if( i < j ){
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
    
  }while(i <= j);	

    // Now every element less than pivot is in the left side, greater ones in the right side
    // sides are seperated by the j index currently
    
    temp = A[low];
    A[low] = A[j];					// Put pivot into its sorted position
    A[j] = temp;

return j;			// return new pivot index
}


/**
 * For Already Sorted List or in other words partitioning done in the ends of list complexity= (n^2)
 * if pivot choosed properly and not sorted list complexity =  O(nlogn)
 */
void quickSort(int A[], int low, int high){
  int pivotIndex;
  if( low < high ){
//    pivotIndex = partitionFast(A,low,high);
    pivotIndex = partitionFast(A,low,high);
    quickSort(A,low,pivotIndex-1);
    quickSort(A,pivotIndex+1,high);
  }
}


void printArray(int A[], int n){
  int i;
  for(i = 0; i < n; i++)
    printf("%d ",A[i]);
  printf("\n");
}

int main(){
  int A[] = {65,60,55,50,45,40,35};
//  printf("Test Case 1: ");
//  printArray(A,7); 
//  quickSort(A,0,6);
//  printArray(A,7); 

  int* G = (int*)malloc(7 * sizeof(int)); 
  for(int i = 0; i < 7; i++)
    G[i] = A[i];  
  printf("Test Case 1 With Malloc: ");
  printArray(A,7);
  quickSort(A,0,6);
  printArray(A,7);

  printf("*********************\n");  
  printf("Test Case 2: ");
  int B[] = {1,4,2,5,3,7,6,8,9,11};
  printArray(B,10);
  quickSort(B,0,9);
  printArray(B,10);
  printf("*********************\n");  
  printf("Test Case 3: ");
  int C[] = {1,3,5,7,9,11,13,15,17, 21};
  printArray(C,10);
  quickSort(C,0,9);
  printArray(C,10);
  printf("*********************\n");  
  printf("Test Case 4: ");
  int D[] = {4,5,3,7,2};
  printArray(D,5);
  quickSort(D,0,4);
  printArray(D,5);
  printf("*********************\n");  
  printf("Test Case 5: ");
  int E[] = {45, 25, 46, 48, 28, 6, 13, 5, 36, 44, 7, 4, 11, 30, 24, 34, 15, 31, 38, 49};
  printArray(E,20);
  quickSort(E,0,19);
  printArray(E,20);
  
   
return 0;
}
