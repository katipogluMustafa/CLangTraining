#include<stdio.h>

/**
 * Inserts given value inside of array of heap tree with n elements, Mutates n since adds new element, Heap has new size
 *@param int HT[] The Array of Heap Tree
 *@param int* n The number of elements inside the Heap tree
 *@param int value The value that we want to insert 
 */
void insertMaxHeap(int HT[], int* n, int value){
  int i,parent;

  i = *n;
  HT[*n] = value;
  *n += 1;
  parent = (i - 1) / 2;
  while( i >= 1 && value > HT[parent] ){
    HT[i] = HT[parent]; 		
    i = parent;
  }
  HT[i] = value; 		// insert the value
}

/**
 * Find biggest child of the given index 'i'
 * @param int i The index that we're looking for biggest childs of it
 * @param int n number of elements inside heap
 * @return int 0 on error, otherwise non-zero index for biggest child
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
 *@return int The deleted element's value which is the maximum element of the Heap
 */
int removeMaxHeap(int HT[], int* n){
  if( *n == 0 ) 
    return -1;
  int tmp;
  int max = HT[0];
  *n -= 1;
  HT[0] = HT[*n];
  HT[*n] = max;		// put the deleted element max outside of the maxHeap's range
  int i = 0;
  int adr = findBiggestChild(HT, i, *n);
  while( adr && (HT[i] > HT[adr] ) ){
    tmp = HT[i];
    HT[i] = HT[adr];		// These 3 lines for swap(HT[i], HT[adr]);
    HT[adr] = tmp;
    adr = findBiggestChild(HT, i, *n);
  }
  return max;
}

/**
 * Create max heap with array of n elements
 * @param int A[] Array of elements
 * @param int n Number of elements
 */
void createMaxHeap(int A[], int n){ 		
  int i = 1;
  while( i < n )
    insertMaxHeap(A,&i,A[i]);		// i is incremented by insertMaxHeap function 
}

void heapSort(int A[], int n){
  createMaxHeap(A,n);
  while( removeMaxHeap(A,&n) != -1 );
}

void printArray(int* Arr, int n){
  int i;
  for(i = 0; i < n ; i++)
    printf("%d ", Arr[i]);
  printf("\n");
}

int main(){
  int Arr[] = {1,2,3,4,5,6,7,8,9,10};
  printArray(Arr, 10);
  createMaxHeap(Arr, 10);
  printArray(Arr, 10);
//  heapSort(Arr, 5);
//  printArray(Arr, 5);

return 0;
}
