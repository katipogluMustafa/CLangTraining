#include <stdio.h> 
#include <string.h> 
  
void printArray(int arr[], int n) 
{ 
   for (int i=0; i<n; i++) 
      printf("%d ", arr[i]); 
} 
  
int main() 
{ 
    int n = 10; 
    int arr[n]; 
  
    // Fill whole array with 100. 
    memset(arr, 10, n*sizeof(arr[0])); 
    printf("Array after memset()\n"); 
    printArray(arr, n); 
 	
 	printf("\n"); 
    return 0; 
}

// Note that the above code doesn’t set array values to 10 
// as memset works character by character and an integer contains more than one bytes (or characters).