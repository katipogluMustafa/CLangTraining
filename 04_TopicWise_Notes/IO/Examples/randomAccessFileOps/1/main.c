#include <stdio.h>

/* clientData structure definition */
struct clientData {
  int acctNum; 				 /* account number */
  char lastName[ 15 ];		 /* account last name */
  char firstName[ 10 ]; 	 /* account first name */
  double balance; 			 /* account balance */
}; /* end structure clientData */

int main( void ){

int i; /* counter used to count from 1-100 */

 /* create clientData with default information */
struct clientData blankClient = { 0 , "" , "" , 0.0 };

FILE *cfPtr; /* credit.dat file pointer */
 	/* fopen opens the file; exits if file cannot be opened */
if ( ( cfPtr = fopen( "credit.dat" , "wb" ) ) == NULL ) {
  printf( "File could not be opened.\n" );
} 
else {
	/* output 100 blank records to file */
	for ( i = 1 ; i <= 100 ; i++ ) {
	  fwrite( &blankClient, sizeof ( struct clientData ), 1 , cfPtr );
	}

    fclose ( cfPtr ); /* fclose closes the file */
}
return 0 ; /* indicates successful termination */
}