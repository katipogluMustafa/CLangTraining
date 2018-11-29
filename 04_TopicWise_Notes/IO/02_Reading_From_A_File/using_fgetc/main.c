#include<stdio.h>
#include<stdlib.h>

int main(){
  int n,i;
  FILE* fp = fopen("test","r");
  if( !fp ){
        printf("Error while opening the file.");
        return 1;
  }

  printf("Number of characters you want to read from test.txt: ");
  scanf("%d",&n);

  char* output = (char*) malloc( ( n + 1 ) * sizeof(char) );

  for(i = 0; i < n; i++){

    output[i] =  fgetc(fp);
    if( feof(fp) ){
        printf("Reached end of file at index %d", i);
        break;
    }
  }
  output[n] = '\0';
  printf("%s\n", output);

return 0;
}