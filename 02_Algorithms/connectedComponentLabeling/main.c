/* Connected Component Labeling	*/

		// Input 

		// [1 0 0 0 0 1 0 0 0 0]
		// [1 1 0 0 0 1 1 1 0 0]
		// [0 1 1 1 0 0 1 1 0 0]
		// [0 0 0 0 0 0 0 0 0 0]	
		// [0 0 0 0 0 0 0 1 1 1]
		// [0 0 0 0 0 0 0 0 1 0]
		// [0 0 1 1 1 1 0 0 0 0]
		// [0 0 0 0 1 1 1 1 0 0]
		// [0 1 1 0 0 0 0 0 0 0]
		// [0 0 1 0 0 0 1 1 1 0]

        // Expected Output

        // [1 0 0 0 0 2 0 0 0 0]
        // [1 1 0 0 0 2 2 2 0 0]
        // [0 1 1 1 0 0 2 2 0 0]
        // [0 0 0 0 0 0 0 0 0 0]
        // [0 0 0 0 0 0 0 3 3 3]
        // [0 0 0 0 0 0 0 0 3 0]
        // [0 0 4 4 4 4 0 0 0 0]
        // [0 0 0 0 4 4 4 4 0 0]
        // [0 5 5 0 0 0 0 0 0 0]
        // [0 0 5 0 0 0 6 6 6 0]

#include<stdio.h>

void print(int col, int row, int in[][col]){
	int i,j;
	for(i = 0; i < row; i++ ){
		for(j = 0; j < col;j++){
			printf("%d",in[i][j] );
		}
	printf("\n");
	}

}

void checkConflict(int** in, int col, int row, int **conflicts, int confCol, int confRow ){

	if(  *( *( in + row ) + col - 1 ) && *( *( in + row - 1 ) + col  )  ){
		
			// check if the conflicts array has space
			if( !**(in + row ) ){

			// if it doesn't have space, double the size

				conflicts = (int**)realloc(conflicts, )
	
			}

			
			// if it does have space, add the elements

	}


}

void labelConnectedComponents( int col, in row, int in[][col] ){
	int conflicts[10][2] = { 0 };
	int i,j;	
	int count = 1;
	int conflictCount = 0;
	for(i = 0; i < row; i++){
	
		for(j = 0; j < col; j++){
			
			// if the number and left number of the matrix is different than 0
			if( in[i][j] && in[i][j-1]  ){

				in[i][j] = in[i][j-1];
				
				// Check Conflicts
				
				if( in[i][j-1] && in[i-1][j] ){
					
					conflicts[ conflictCount ][ 0 ] = in[ i ][ j-1 ];
					conflicts[ conflictCount ][ 1 ] = in[ i-1 ][ j ];
					conflictCount++;	
					
				}				
			// if the number and upper number of the matrix is different than 0	
			}else if(in[i][j] && in[i-1][j]){

				in[i][j] = in[i-1][j];
				
			        // Check Conflicts

                                if( in[i][j-1] && in[i-1][j] ){

                                        conflicts[ conflictCount ][ 0 ] = in[ i ][ j-1 ];
                                        conflicts[ conflictCount ][ 1 ] = in[ i-1 ][ j ];
                                        conflictCount++;

                                }


				
			}else{


				in[i][j] = count;
				count++;


			}			
			

		}

	}
	
	handdleConflicts();

}

int main(){
	int in[10][10] = { {1,0,0,0,0,1,0,0,0,0 } ,
			   {1,1,0,0,0,1,1,1,0,0 } ,
			   {0,1,1,1,0,0,1,1,0,0 } ,
			   {0,0,0,0,0,0,0,0,0,0 } ,
			   {0,0,0,0,0,0,0,1,1,1 } ,
			   {0,0,0,0,0,0,0,0,1,0 } ,
			   {0,0,1,1,1,1,0,0,0,0 } ,
			   {0,0,0,0,1,1,1,1,0,0 } ,
			   {0,1,1,0,0,0,0,0,0,0 } ,
			   {0,0,1,0,0,0,1,1,1,0 } 
			 };
	
	labelConnectedComponents(10,10,in);

	print(10,10,in);
	
	
return 0;
}
