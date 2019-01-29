#include<stdio.h>

int main(){
  char Buffer[255];

  // Create file

  FILE *fp;
  fp = fopen("test.txt","w+");
 
  // Write to File

  fprintf(fp,"This is just a text to test whether fprint is properly working or not\n");
  fputs("This is test for fputs function\n",fp);

  // Fclose flushes any data still pending in the buffer to the file, closes the file, and releases any memory used for the file
  fclose(fp);

return 0;
}
