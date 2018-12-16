#include<stdio.h>
#include<stdlib.h> // atoi 
#include<assert.h> // assert
															

#define add(a,b) ( (a) + (b) )
#define sub(a,b) ( (a) - (b) )
#define mul(a,b) ( (a) * (b) )
#define shl(a,b) ( (a) << (b) )
#define shr(a,b) ( (a) >> (b) )
										

int main( int argc, char* argv[] ){
	void fail(int, int, char*, const char*, int);
	int checkArguments(int, int);

 if ( checkArguments(argc, 3) ){
 	exit(0);
 }

 switch(argv[1][0]){
 	case 'a':
 		printf("Addition Result: %d\n", add( atoi( argv[2] ), atoi( argv[3] ) ) );
 		break;
 	case 'm':
 		printf("Multiplication Result: %d\n", mul( atoi( argv[2] ), atoi( argv[3] ) ) );
 		break;
 	case 's':
 		     if(argv[1][2] == 'b'){ printf("Subtraction Result: %d\n", sub( atoi( argv[2] ), atoi( argv[3] ) ) ); }
 		else if(argv[1][2] == 'l'){ printf("Left Shifting Result: %d\n", shl( atoi( argv[2] ), atoi( argv[3] ) ) ); }
 		else if(argv[1][2] == 'r'){	printf("Right Shifting Result: %d\n", shr( atoi( argv[2] ), atoi( argv[3] ) ) ); }
 		break;
 	default:
 		printf("Undefined input arguments!...");
 		break;
 			
 }


return 0;
}

void fail(int argc, int n, char* fileName, const char* funcName,int lineNumber){	 											
			printf("Error while getting the required arguments to main function.\n" 	
					"You need to give %d more arguments to the program!\n"				
					"Error at File: %s \n\t Function: %s \n\t Line Number : %d\n",									
					( (n) - ( (argc) - 1) ),											
					(fileName),
					(funcName),															
					(lineNumber) ); 		

			FILE* fp = fopen(fileName, "r");

			int i;
			while( !feof(fp) && i < ( lineNumber - 1 ) ){

				while( fgetc(fp) != '\n' );
				i++;
			}

			printf("\n");
			char c;

			while( !feof(fp) && ( ( c = fgetc(fp )) != '\n' ) ){
				fprintf(stdout,"%c",c);
			}

			printf("\n");

}									

int checkArguments(int argc,int n){
	int ret = 0;
	if( ( (argc) - 1) < (n)   ){			

		fail(argc, n, __FILE__ , __func__ ,__LINE__);
		
		ret = 1;
	}			
	return ret;					
} 				
/* 
 * ./main shr 16 1
 * ./main shl 32 2
 * ./main sub 16 5
 * ./main mul 4 5  */
