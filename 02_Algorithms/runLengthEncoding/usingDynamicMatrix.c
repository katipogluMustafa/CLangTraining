#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){

	int takeYesNoInput();
	void printMatrix(int, int**,int);
	void scanRowByRow( int, int**, int, int*, int );
	void scanColByCol( int, int**, int, int*, int );
	int runLengthEncoding( int , void(*)(), void(*)(), int, int**, int);

	int** in;
	int i,j,rows,cols,n;
	int takeOrNotTakeInput;

	/*
	printf("Would you like to give input, or just see the output using exampe input ? [0-1] : ");
	scanf("%d",&takeOrNotTakeInput);
	*/
	printf("Would you like to give input, or just see the output using exampe input ? [yes-no] : ");
	takeOrNotTakeInput = takeYesNoInput();

	if( !takeOrNotTakeInput ){
		// if the user doesn't want to give specific input
		rows = 5;
		cols = 4;

		in = (int**)malloc( rows * sizeof(int*) );
		for(i = 0; i < rows; i++){
			in[i] = (int*)malloc( cols * sizeof(int) );
		}


		in[0][0] = 3; in[0][1] = 3; in[0][2] = 3; in[0][3] = 3;

		in[1][0] = 8; in[1][1] = 8; in[1][2] = 3; in[1][3] = 3;

		in[2][0] = 8; in[2][1] = 5; in[2][2] = 6; in[2][3] = 7;

		in[3][0] = 1; in[3][1] = 4; in[3][2] = 2; in[3][3] = 2;

		in[4][0] = 1; in[4][1] = 9; in[4][2] = 9; in[4][3] = 9;


	}else{

		// if the user wants to give input
		
		printf("\n\nNumber of Rows: ");
		scanf("%d",&rows);
		printf("\n\nNumber of Columns: ");
		scanf("%d", &cols);

		in = (int**)malloc( rows * sizeof(int*) );
		for(i = 0; i < rows; i++){
			in[i] = (int*)malloc( cols * sizeof(int) );
		}

		for(i = 0; i < rows; i++){
			for(j = 0; j < cols; j++){
				printf("Row %d Column %d: ",i+1,j+1);
				scanf("%d", &in[i][j]);
			}
		}
	}
		printf("\n**** Run Length Encoing ****\n");
		printMatrix(cols,in,rows);
		printf("How would you like us to scan the matrix ?[0-1]\n\n");
		scanf("%d",&n);
		printf("\n\n");

		int flag = runLengthEncoding( n , scanRowByRow, scanColByCol, cols, in, rows);
		// if something wrong about runLengthEncoding function
		// this means this program is not working properly
		// report to OS.
		if( flag ){
			return -1;
		}


		free(in);
	return 0;
}

int runLengthEncoding( int n , void(*x)(), void(*y)(), int col, int** in, int row){
	
	int compress(int*, int, int*, int*);

	int len = col * row;
	int* readings = malloc( len * sizeof(int) );

	// if n == 0 scanRowByRow, n == 1 scanColByCol
	if( !n ){

		x(col,in,row,readings,len);

	}else{

		y(col,in,row,readings,len);

	}

	int lenOfCompressedArr = 2;
	int* compressedArr = malloc( lenOfCompressedArr * sizeof( int ) );

	int flag = compress(readings,len,compressedArr,&lenOfCompressedArr);
	if( flag ){ // if flag is not 0, this means compressing is not working properly.
		return -1;
	}

	free(readings);
	return 0;
}

// returns -1 if there exist an error, 0 if properly worked.
int compress(int* arr, int n, int* compressedArr, int* lenOfCompressedArr){

	void printArray(int*, int);
	int AddElementToCompressedArr(int*, int , int*, int*, int, int* ,int*);

	int i;
	int currIndexOfCompArr = 0;
	int num = *arr;
	int count = 1;

	for(i = 1; i < n; i++){

		if( *(arr + i) == num){
			
			count++;

		}else{

			int flag = AddElementToCompressedArr(arr,n,compressedArr,lenOfCompressedArr,num,&count,&currIndexOfCompArr);
			if( flag ){
				return -1;
			}


			// assign new number into num so that we could control in later iterations
			// for the purpose of finding the duplicates of it.
			num = *(arr + i );
			count = 1;
		}

	}

	// Add the last element of the array
	int flag = AddElementToCompressedArr(arr,n,compressedArr,lenOfCompressedArr,num,&count,&currIndexOfCompArr);
	if( flag ){
		return -1;
	}

	printf("Scanned Array");
	printArray(arr, n);


	printf("Compressed Array");
	printArray(compressedArr, currIndexOfCompArr);

	printf("Compression Rate");
	// negatif compression rate means, it hasn't been compressed rather expended by the rule of the algorithm.
	printf("\n\n%.1f\n", (float)n / currIndexOfCompArr - 1 );

	return 0;
}


// returns -1 if there exist an error, 0 if properly worked.
int AddElementToCompressedArr(int* arr, int  n, int* compressedArr, int* lenOfCompressedArr, int num, int* count ,int* currIndexOfCompArr){

	int doubleTheSizeOfTheArr(int*, int*);

	// If the array is full, double the size of the array.
	if( *lenOfCompressedArr <= *currIndexOfCompArr ){
		
		int flag = doubleTheSizeOfTheArr(compressedArr, lenOfCompressedArr);

		// check if the doubleTheSizeOfTheArr functions worked properly
		if( flag ){ // if flag is not 0
			return -1;
		}

	}


	// Compressing is okay, we write the compressed versions into the compressedArr.
	*( compressedArr + *currIndexOfCompArr ) = *count;
	(*currIndexOfCompArr)++;	
	*( compressedArr + *currIndexOfCompArr ) = num;
	(*currIndexOfCompArr)++;

	return 0;
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

void scanRowByRow(int col ,int** in, int row, int* arr, int len){

	int k = 0;
	int i,j;

	for(i = 0; i < row; i++){

		if( i % 2 ){

			for(j = col - 1; j >= 0; j--){

					*(arr + k) = *( *(in + i) + j);
					k++;

			}	

		}else{

			for(j = 0; j < col; j++){
					*(arr + k) = *( *(in + i) + j);
					k++;
			}
			
		}
	}

}

void scanColByCol(int col ,int** in, int row, int* arr, int len){

	int k = 0;
	int i,j;

	for(i = 0; i < col; i++){

		if( i % 2 ){
			
			for(j = row - 1; j >= 0; j--){
				*(arr + k) = *( *(in + j) + i);
				k++;
			}
			

		}else{

			for(j = 0; j < row; j++){
				*(arr + k) = *( *(in + j) + i);
				k++;
			}
			
		}
	}

}

void printMatrix(int col, int** in,int row){
	int i,j;
	printf("\n\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){

			printf("%d ", *( *(in + i) + j) );

		}
		printf("\n");
	}
	printf("\n\n");
}



void printArray(int* arr, int n){
	int i;
	printf("\n\n");
	for(i = 0; i < n; i++){
		printf( "%d ", *( arr + i ) );
	}
	printf("\n\n");
}

// if the answers is yes, return 1, else return 0
int takeYesNoInput(){
	char myToLower(char);
	int myStrLen(char* str);

	int i,len;
	char str[10];

	scanf("%s",str);

	len = myStrLen(str);
	for(i = 0; i < len;i++){
		myToLower(str[i]);
	}

	if( !strcmp(str,"yes") ){
		return 1;
	}

	return 0;
}

char myToLower(char character){
	
	if( character >= 'a' && character <= 'z' ){
		return character;
	}else if( character >= 'A' && character <= 'Z' ){
		return character + 32;
	}

	return -1;
}

int myStrLen(char* str){
	int count = 0;
	while(*str++){
		count++;
	}

	return count;
}
