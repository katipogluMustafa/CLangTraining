#include<stdio.h>
#include<stdlib.h> // atoi 
#include<assert.h> // assert

#define add(a,b) ( (a) + (b) )
#define sub(a,b) ( (a) - (b) )
#define mul(a,b) ( (a) * (b) )
#define shl(a,b) ( (a) << (b) )
#define shr(a,b) ( (a) >> (b) )

int main( int argc, char* argv[] ){
  
 assert(argc >= 4);
 
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


/* 
 * ./main shr 16 1
 * ./main shl 32 2
 * ./main sub 16 5
 * ./main mul 4 5  */
