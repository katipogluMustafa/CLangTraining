#include<stdio.h>


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
    pivotIndex = partitionSlow(A,low,high);
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
  printArray(A,7); 
  quickSort(A,0,6);
  printArray(A,7); 


return 0;
}
