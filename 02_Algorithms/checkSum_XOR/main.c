#include<stdio.h>

unsigned char checksum(FILE* fp, unsigned char key){

	unsigned char sum = key;

	// save the position in which the file pointer has been located.
	long current_position = ftell(fp);

	fseek(fp, 0, SEEK_SET);

	while( !feof(fp) ){
		sum ^= fgetc(fp);
	}

	// set the position as the old current position back so that its file pointer wouldn't be changed.
	fseek(fp, current_position, SEEK_SET);

	return sum; 
}

int main(){

	FILE* myFile = fopen("main.txt", "r");

	printf("key : 25, checksum:%u\n", checksum(myFile, 25) );
	printf("key : 7, checksum:%u\n", checksum(myFile, 7) );
	printf("key : 193, checksum:%u\n", checksum(myFile, 193) );
	printf("key : 255, checksum:%u\n", checksum(myFile, 255) );

	fclose(myFile);
return 0;
}
