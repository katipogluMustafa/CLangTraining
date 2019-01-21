#include<stdio.h>


int compareFiles(FILE* fp1, FILE* fp2 );
/* Main takes two arguments */

int main(int argc, char* argv[]){
  
  if( argc < 3 ){
  	fprintf(stderr,"Not enough parameters, you need to at least give 2 parameters.\n");
	return 1;
  }

  FILE* file1 = fopen(argv[1], "r");
  if( file1 == NULL){
  	fprintf(stderr,"Error while opening first file!..\n");
	return 1;
  }

  FILE* file2 = fopen(argv[2], "r");
  if( file2 == NULL){
  	fprintf(stderr,"Error while opening second file!..\n");
	fclose(file1);
	return 1;
  }

  if( compareFiles(file1,file2) == 0 ){
  	fprintf(stdout,"%s", "Given files are equal to each other...\n");
  }else{
  	fprintf(stdout,"%s", "Given files are not equal to each other...\n");
  }
  
  fclose(file1);
  fclose(file2);
  return 0;
}

/* If equal returns 0 */
int compareFiles(FILE* fp1, FILE* fp2 ){
  int out = 0;
  size_t currPosition1 = ftell(fp1);
  size_t currPosition2 = ftell(fp2);
  fseek(fp1, 0, SEEK_SET);
  fseek(fp2, 0, SEEK_SET);
	char char1;
	char char2;
  	while( ( char1 = fgetc(fp1) ) == ( char2 = fgetc(fp2) ) && !feof(fp1) && !feof(fp2) );

	if(char1 != char2 ){
	  out = 1;
	}

	if( feof(fp1) && !feof(fp2) ){
	  out = 1;
	}

	if( feof(fp2) && !feof(fp1) ){
	  out = 1;
	}


  fseek(fp1, currPosition1, SEEK_SET);
  fseek(fp2, currPosition2, SEEK_SET);

  return out;
}

