#include<stdio.h>

/* Given a file that has numbered records inside of it
 * get the nth record out of all records.*/

#include<stdio.h>

typedef struct{

	char name[20];
	char authorName[25];
	// ... and other fields


}BOOKINFO;


BOOKINFO* getRecord(FILE* fp, int n){

	BOOKINFO* info = calloc(1, sizeof(BOOKINFO) );
  
  // save the position of file pointers
	long current_position = ftell(fp);
  
	long infoPosition = (n-1) * sizeof(BOOKINFO);
  
	if( fseek(fp, infoPosition, SEEK_SET) ){
		printf("There isn't a record numbers as %d\n", n);
		return NULL;
	}

	fread(info, sizeof(BOOKINFO), 1, fp);
  
  // set the old position so that the file pointer position doesn't change.
	fseek(fp, current_position, SEEK_SET);

	return info; 
}
