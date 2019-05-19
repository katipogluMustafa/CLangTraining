#include<stdio.h>
#include<limits.h>

int binarySearch(int A[], int n, int x){
  int first = 0,last = n,middle = (first + last)/2;

  while( first <= last && A[middle] != x){
    if( x > A[middle] )
	first = middle + 1;
    else
	last = middle - 1;
    middle = (first + last) / 2;
  }

  if( first > last )
    return INT_MIN;
  else
    return middle;
}

int recursiveBinarySearch(int A[], int n, int x){
  int search(int [],int, int, int);			// private function prototype
  return search(A, 0, n, x);
}

int search(int A[],int first, int last, int x){

  if( first < last){
    int middle = ( first + last ) / 2; 

    if( A[middle] == x)
	return middle;
    else if( A[middle] > x)
    	return search(A, first, middle - 1, x);
    else
	return search(A, middle + 1, last, x);
  }

  return INT_MIN;		// Not found if we reach here
}


/* Unit Test*/
int main(){
  int arr[] = {1,3,5,7,9,11,13,15,17};
  printf("\n*** Binary Search Test 1 ***\n");
  int search = 3;
  int index = binarySearch(arr, 9, search);

  if( index != INT_MIN )
	printf("%d found at %d\n", search, index);
  else
	printf("Not found!\n");

  printf("\n*** Binary Search Test 2 ***\n");
  
  search = 11;
  index = recursiveBinarySearch(arr, 9, search);

  if( index != INT_MIN )
	printf("%d found at %d\n", search, index);
  else
	printf("Not found!\n");

  return 0;
}




