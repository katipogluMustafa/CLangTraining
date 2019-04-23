#include<stdio.h>

/**
 * Choses a pivot element then puts every element less than pivot on its left,  greater ones to its right
 * Takes An array of elements and the boundary indexes for the element
 * returns the pivot's sorted position
 */
int partition(int A[], int low, int high){

  int pivotIndex = low			// for now just we select first one;
  int pivot = A[pivotIndex];
  int i = low, j = high;
  int temp;

  do{
    do{i++;}while( i < j && A[i] <= pivot );		// Until you see greater element from the pivot, increment i
    do{j--;}while( i < j && A[j] > pivot );		// Until you see lesser element from the pivot, decrement j
    // Then A[i]<-->A[j] if i < j
    temp = A[i];	// We could have put this swap into if(i < j) but it would be expensive
    A[i] = A[j];	// since it will just only one time will do more swap when it shouldn't
    A[j] = temp;
  }while(i < j);	

    temp = A[i];	// we can revert that last wrong swap back, by performing just one extra swap
    A[i] = A[j];
    A[j] = temp;

    // Now every element less than pivot is in the left side, greater ones in the right side
    // sides are seperated by the j index currently
    
    temp = A[pivotIndex];		// Put pivot into its sorted position
    A[pivotIndex] = A[j];
    A[j] = temp;

    pivotIndex = j;   			// Update pivot index into its new place 

return pivotIndex;			// return new pivot index
}

int main(){



return 0;
}
