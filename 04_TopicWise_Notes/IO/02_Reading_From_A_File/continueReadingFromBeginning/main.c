#include<stdio.h>
#include<stdlib.h>

int main(){
  int n,i;
  FILE* fp = fopen("test","r");
  if( !fp ){
	printf("Error while opening the file.");
	return 1;
  }

  printf("Number of characters you want to read from test file: ");
  scanf("%d",&n);

  char* output = (char*) malloc( ( n + 1 ) * sizeof(char) );
  if(!output){
	printf("Error while allocating space for output.");
  }
  for(i = 0; i < n; i++){

    output[i] =  fgetc(fp);
    if( feof(fp) ){
	printf("Reached end of file at index %d", i);
	break;
    }
  }
  output[n] = '\0';
  printf("%s\n", output);

  printf("Number of characters you want to read from the last position in the test file: ");
  scanf("%d",&n);

  /*    Reading continues from the point we read lastly.       		*/

  free(output);
  output = (char*)malloc( ( n + 1 ) * sizeof(char) );
  if(!output){
 	printf("Error while allocating space for output.\n");
  }

  for(i = 0; i <n; i++){
	output[i] = fgetc(fp);
	if ( feof(fp) ){
	   printf("Reached end of the file at index %d",i);
	   break;
	}
  }
  output[n] = '\0';
  printf("From the position where we've left: %s\n", output);

  /* 	Let's read the from zero not from the point we've read lastly.	*/

  free(output);
  output = (char*)malloc( ( n + 1 ) * sizeof(char) );
  if(!output){
	printf("Error while allocating space for output\n");
  }

   // Set the position to the beginnig of the file using void rewind(FILE* stream)
   // rewind(fp);	// doesn't return anything so we can not check whether it was successfull

   // Set the position to the beginnig of the file using int fseek(FILE *stream, long int offset, int whence)
   // long int offset, is the number of bytes you want to from whence.
   // whence can be -->
   // SEEK_SET -- Beginning of the file
   // SEEK_CUR -- Current position of the file pointer
   // SEEK_END -- End of file

   if( fseek(fp, 0L, SEEK_SET)  ){
	printf("Error while setting the position to the beginning");
   }

  for(i = 0; i < n; i++){
	output[i] = fgetc(fp);
	if( feof(fp) ){
	   printf("Reached end of the file at index %d", i);
	   break;
	}
  }
  output[n] = '\0';
  printf("From the beginning: %s \n", output);

  free(output);
  free(fp);
return 0;
}


