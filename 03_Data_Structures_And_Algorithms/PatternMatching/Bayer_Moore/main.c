#include<stdio.h>
#include<stdlib.h>
#include<string.h>		// for just strlen();

int* horspoolAlgorithm( char pattern[], int n, int numberOfCharsInTheAlphabet){
  int i;
  // Crea an array with given number of characters in the alphabet
  int* arr = (int*)malloc( sizeof(int) * numberOfCharsInTheAlphabet );
  // initialize each cell in the array as -1  
  for(i = 0; i < numberOfCharsInTheAlphabet; i++){
    arr[i] = -1;   
  }

  // let's say pattern = 'BALOON' and alphaber 26 char eng alphabet
  //                      012345
  // A B C D E F G H J K L M N O P .....
  // 1 0 - - - - - - - - 2 - 5 4 -
  // we'll put in each character's position in the alphabet, the index of the char in the pattern(if more than one, we only got the last one)
  for(i = 0; i < n-1; i++){
    if( arr[ pattern[i] - 'A' ] == -1 )			// check if already we put index or not, if we did, do not change it
      arr[ pattern[i] - 'A' ] = i;  
  }


return arr;
}

int bayerMooreAlgorithm( int numberOfCharsInTheAlphabet, char text[], int n, char pattern[], int m ){
 
  int* arr = horspoolAlgorithm(pattern,m, numberOfCharsInTheAlphabet);	
  
  int i = 0,j;
  int found = 0;
  int skip;

  while(i < n-m && !found){
    j = m-1;
    while( j >= 0 && pattern[j] == text[i+j] ) 
      j--;
    if( j >= 0 ){
      skip = j - arr[ text[i+j]-'A' ];		// text[i+j] the char that doesn't match, subtract -'A' to find its index
      if(skip < 0)
        i++;
      else
        i += skip;
    }else{
      found = 1;
      return i;
    }
  }
 
return -1;
}

// For ASCII
int* horspool(char pattern[], int n){
  int i;
  int *arr = (int*)malloc(sizeof(int) * 256);
  for(i = 0; i < 256; i++)
    arr[i] = -1;

  for(i = 0; i < n-1;i++)
    if( arr[pattern[i]] == -1 )
      arr[pattern[i]] = i;

return arr;
}

// For ASCII
int bayerMoore(char text[], int n, char pattern[], int m){
  int* arr = horspool(pattern,m);
  int i = 0,j;
  int skip;
  int found = 0;
  
  while( i < n-m && !found){
    j = m-1;
    while( j>=0 && pattern[j] == text[i+j] )
      j--;
    if( j >= 0 ){
      skip = j - arr[ text[i+j] ];
      if( skip < 0 )
        i++;
      else
        i += skip;
    }else{ 
      found = 1;	// just for illustration
      return i;
    }
  }

return -1;
}


int main(){
  // Works only on all upper or all lower case if we don't make the alphabet ASCII or UTF
  int i = bayerMooreAlgorithm(26, "merhabaBenmustafa", 19, "mustafa",3);
  if(i != -1)
    printf("Found at %d\n", i);
  else
    printf("Not Found!\n");

  // Let's do it for ASCII
  i = bayerMoore( "Merhabalar Ben Mustafa Katipoglu", 32, "afa", 3 );
  if(i != -1)
    printf("Found at %d\n", i);
  else
    printf("Not Found!\n");


return 0;
}
