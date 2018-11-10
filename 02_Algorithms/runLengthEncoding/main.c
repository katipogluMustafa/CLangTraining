#include<stdio.h>
#include<stdlib.h>

void printMatrix(int col, int (*in)[col],int row){
	int i,j;
	printf("\n\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			printf("%d ",in[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
	
void printArray(int* arr, int n){
	int i;
	printf("\n\n");
	for(i = 0; i < n; i++){
		printf( "%d ", arr[i] );
	}
	printf("\n\n");
}

// return 0 if complated its job properly.
// returning -1 means we couldn't able to reallocate the enough space.
int doubleTheSizeOfTheArr(int* arr, int* n){

	arr = realloc(arr, 2 * (*n) * sizeof(int) );

	if(arr){
		*n *= 2; 
		return 0;
	}

	return -1;
}

// returns -1 if there exist an error, 0 if properly worked.
int AddElementToCompressedArr(int* arr, int  n, int* compressedArr, int* lenOfCompressedArr, int num, int* count ,int* currIndexOfCompArr){

	// If the array is full, double the size of the array.
	if( *lenOfCompressedArr <= *currIndexOfCompArr ){
		
		int flag = doubleTheSizeOfTheArr(compressedArr, lenOfCompressedArr);

		// check if the doubleTheSizeOfTheArr functions worked properly
		if( flag ){ // if flag is not 0
			return -1;
		}

	}


	// Compressing is okay, we write the compressed versions into the compressedArr.
	compressedArr[ *currIndexOfCompArr ] = *count;
	(*currIndexOfCompArr)++;	
	compressedArr[ *currIndexOfCompArr ] = num;
	(*currIndexOfCompArr)++;

	return 0;
}

// returns -1 if there exist an error, 0 if properly worked.
int compress(int* arr, int n, int* compressedArr, int* lenOfCompressedArr){
	int i;
	int currIndexOfCompArr = 0;
	int num = arr[0];
	int count = 1;

	for(i = 1; i < n; i++){

		if(arr[i] == num){
			count++;
		}else{

			int flag = AddElementToCompressedArr(arr,n,compressedArr,lenOfCompressedArr,num,&count,&currIndexOfCompArr);
			if( flag ){
				return -1;
			}


			// assign new number into num so that we could control in later iterations
			// for the purpose of finding the duplicates of it.
			num = arr[i];
			count = 1;
		}

	}

	// Add the last element of the array
	int flag = AddElementToCompressedArr(arr,n,compressedArr,lenOfCompressedArr,num,&count,&currIndexOfCompArr);
	if( flag ){
		return -1;
	}

	printf("Compressed Array");
	printArray(compressedArr, currIndexOfCompArr);


	return 0;
}

int runLengthEncoding( int n , void(*x)(), void(*y)(), int col, int (*in)[col], int row){
	
	int len = col * row;
	int* readings = malloc( len * sizeof(int) );

	if( !n ){

		x(col,in,row,readings,len);

	}else{

		y(col,in,row,readings,len);

	}

	printf("Scanned Array");
	printArray(readings, len);

	int lenOfCompressedArr = 2;
	int* compressedArr = malloc( lenOfCompressedArr * sizeof( int ) );

	int flag = compress(readings,len,compressedArr,&lenOfCompressedArr);
	if( flag ){ // if flag is not 0, this means compressing is not working properly.
		return -1;
	}

	return 0;
}



int main(){

	void scanRowByRow( int, int (*)[], int, int*, int );
	void scanColByCol( int, int (*)[], int, int*, int );

	int n;
	int in[5][4] = { {3,3,3,3},{8,8,3,3},{8,5,6,7},{1,4,2,2},{1,9,9,9} };

	printf("\n**** Run Length Encoing ****\n");
	printf("\n\nHow would you like us to scan the matrix ?[0-1]\n\n");
	scanf("%d",&n);

	printMatrix(4,in,5);

	int flag = runLengthEncoding( n , scanRowByRow, scanColByCol, 4, in, 5);

	// if something wrong about runLengthEncoding function
	// this means this program is not working properly
	// report to OS.
	if( flag ){
		return -1;
	}

	return 0;
}



void scanRowByRow(int col ,int (*in)[col], int row, int* arr, int len){

	int k = 0;
	int i,j;

	for(i = 0; i < row; i++){

		if( i % 2 ){

			for(j = col - 1; j >= 0; j--){
					arr[k] = in[i][j];
					k++;
			}	

		}else{

			for(j = 0; j < col; j++){
					arr[k] = in[i][j];
					k++;
			}
			
		}
	}

}

void scanColByCol(int col ,int (*in)[col], int row, int* arr, int len){

	int k = 0;
	int i,j;

	for(i = 0; i < col; i++){

		if( i % 2 ){
			
			for(j = row - 1; j >= 0; j--){
				arr[k] = in[j][i];
				k++;
			}
			

		}else{

			for(j = 0; j < row; j++){
				arr[k] = in[j][i];
				k++;
			}
			
		}
	}

}


