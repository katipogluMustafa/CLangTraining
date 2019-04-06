#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000
#define true (1) 
#define false (0)

typedef int boolean;

int minChildIndex(int heap[], int n,int parent){
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if( n > right  ){       // 2 Childs
        if( heap[left] > heap[right] )
            return right;
        else 
            return left;
    }else if( n > left ){    // 1 Child
        return left;
    }else                           // No child
        return 0;                   // To Show Error
}

void arrange(int heap[], int n, int curr) {
    int i = curr;
    int minChild,tmp;

    while( 1 ){
      minChild = minChildIndex(heap, n, i);
      if(minChild != 0){
          tmp = heap[i];
          heap[i] = heap[minChild];
          heap[minChild] = tmp;
      }else{
          return;
      }
      i = minChild;

      if (i >= n)
        return;
    }

}

boolean deleteRoot (int heap[], int *n) {
  if (heap == NULL || n <= 0)
    return false;

  // Swap first and last element of heap
  int tmp = heap[0];
  heap[0] = heap[*n - 1];
  heap[*n - 1] = tmp;
  // Decrement Number of elements of the heap so last element is not in heap
  // anymore
  *n -= 1;

  arrange(heap, *n,0);

  return true;
}

boolean delete(int heap[], int* n, int e){
  if(heap == NULL || n <= 0)
    return false;

  int i = 0; 		// index of the element that we want to delete
  while( heap[i] != e )
    i++;

  if(heap[i] != e)
    return false; 	// We couldn't find the element

  int tmp = heap[*n-1];
  heap[*n-1] = heap[i]; 	// take the element to the end of heap
  heap[i] = tmp;
  *n -= 1; 		// Decrement the heap size
  arrange(heap,*n,i); 

return true;
}

boolean insert(int heap[], int *n, int e) {
    if(heap == NULL || *n == MAX || e > INT_MAX || e < INT_MIN)
        return false;
    
    heap[*n] = e;
    int i = *n;     // index of e
    *n += 1;
   
    while( i < 0 ){
        if( e < heap[ (i-1)/2 ])
            heap[i] = heap[ (i-1)/2 ];
        i = (i-1)/2;
    }
    heap[i] = e;
    return true;
}



int main() {
    int heap[MAX] = {0};
    int n = 0;          // Number of elements inside heap

    int in,inputs,e;
    int j;
    scanf("%d",&inputs);

    for(int i = 1; i <= inputs;i++){
        scanf("%d",&in);
        switch(in){
            case 1:
                scanf(" %d\n", &e);
                insert(heap,&n,e);
                break;
            case 2:
		scanf("%d\n", &e);
                delete(heap,&n,e);
                break;
            case 3:
                fprintf(stdout,"%d\n",heap[0]);
                break;
            case 0:
                exit(0);
                break;
            default: 
                fprintf(stderr, "Wrong Choice\n");
        }
    }

/* 
    insert(heap, &n,4);
    insert(heap, &n,9);
    printf("%d\n", heap[0]);

    delete(heap, &n);
    printf("%d\n",heap[0]);
*/
/*    
    insert(heap, &n,3);
    insert(heap, &n,7);
    insert(heap, &n,9);
    insert(heap, &n,11);
    insert(heap, &n,8);
    insert(heap, &n,14);
    insert(heap, &n,17);
    insert(heap, &n,13);
    insert(heap, &n,11);
   
    for(int i = 0; i < n; i++){
      printf("%d ",heap[i]);
    } 
    printf("\n"); 
    delete(heap, &n);
    delete(heap, &n);
    delete(heap, &n);
    delete(heap, &n);
    delete(heap, &n);
    delete(heap, &n);
    for(int i = 0; i < n; i++){
      printf("%d ",heap[i]);
    } 
*/        
    return 0;
}

