#include<stdio.h>
#include<limits.h>


/* upHeap puts the element with given index 'n' into its proper place.
 * @param A[] is the Max heap tree
 * @param n is the index of the recently added element
 */
void upHeap(int A[], int n){
  int temp, i;
  temp = A[n];
  i = n;

  while( i > 0 && temp > A[(i-1)/2]){
    A[i] = A[(i-1)/2];
    i = ( i - 1 ) / 2;
  }

  A[i] = temp;
}

/**
 * Find biggest child of the given index 'i'
 * @param i The index that we're looking for biggest childs of it
 * @param n number of elements inside heap
 * @return 0 on error, otherwise non-zero index for biggest child
 */
int findBiggestChild(int HT[], int i, int n){
  int right = 2 * i + 2;
  int left = 2 * i + 1;

  if( right < n){			// if two child exists
    if( HT[left] > HT[right] )  
      return left;
    else
      return right;
  }else if( left < n) 			// if only one child
      return left;
  else
      return 0;				// if no child, as an indicator of error
}
/**
 * Removes the root from the Max Heap
 *@param int HT[] Heap Tree
 *@param int n number of elements inside heap
 *@return int The deleted element's value which is the maximum element of the Heap, on Error returns INT_MIN
 */
int removeMaxHeap(int HT[], int* n){
  if( *n == 0 ) 
    return INT_MIN;

  int tmp,max;
  *n -= 1;
  max = HT[0];
  HT[0] = HT[*n];	
  HT[*n] = max;		// put the deleted element max outside of the maxHeap's range
  int i = 0;
  int adr = findBiggestChild(HT, i, *n);
  while( adr && (HT[i] < HT[adr] ) ){
    tmp = HT[i];
    HT[i] = HT[adr];		// These 3 lines for swap(HT[i], HT[adr]);
    HT[adr] = tmp;
    i = adr;
    adr = findBiggestChild(HT, i, *n);
  }
  return max;
}

void printArray(int* Arr, int n){
  int i;
  for(i = 0; i < n ; i++)
    printf("%d ", Arr[i]);
  printf("\n");
}

/**
 * @param A[] max heap
 * @param n number of elements currently heap has
 * @param value is the value that you want to insert
 */
void insertMaxHeap(int A[], int* n, int value){ 
  A[*n] = value;
  upHeap(A, *n);
  *n += 1;
}

/**
 * Create max heap with array of n elements
 * Works slower than Heapify when it comes to create heap, this one O(nlogn), heapfiy O(n)
 * @param A[] Array of elements
 * @param n Number of elements
 */
void createMaxHeap(int A[], int n){ 		
  int i = 1;
  while( i < n)
    insertMaxHeap(A, &i, A[i]);		// i is incremented by insertMaxHeap function  
}

/**
 * See Sorting section for faster version
 */
void heapSort(int A[], int n){
  int i;
  int size = n;
  createMaxHeap(A,n);

  while(size)
    removeMaxHeap(A, &size );  
}



int main(){
  int Arr[] = {10,9,8,7,6,5,4,3,2,1};
  heapSort(Arr, 10);
  printArray(Arr,10);
return 0;
}
