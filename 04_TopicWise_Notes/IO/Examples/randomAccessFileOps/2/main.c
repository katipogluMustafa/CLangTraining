/* Writing to a random access file */

#include <stdio.h>
#include <stdlib.h> /* for exit(0) */

/* clientData structure definition */
struct clientData {
  int acctNum; /* account number */
  char lastName[ 15 ]; /* account last name */
  char firstName[ 10 ]; /* account first name */
  double balance; /* account balance */
};


int main( void ){
FILE *cfPtr; /* credit.dat file pointer */

 /* create clientData with default information */
 struct clientData client = { 0 , "" , "" , 0.0 };

 /* fopen opens the file; exits if file cannot be opened */
if ( ( cfPtr = fopen( "credit.dat" , "wb+" ) ) == NULL ) {
	printf( "File could not be opened.\n" );
	exit(0);
}
 /* require user to specify account number */
printf( "Enter account number"
		" ( 1 to 100, 0 to end input )\n? " );
scanf( "%d" , &client.acctNum );

/* user enters information, which is copied into file */
while ( client.acctNum != 0 ) {
/* user enters last name, first name and balance */
	printf( "Enter lastname, firstname, balance\n? " );

/* set record lastName, firstName and balance value */
	fscanf( stdin, "%s%s%lf" , client.lastName, client.firstName, &client.balance );

/* seek position in file to user-specified record */
	fseek( cfPtr, ( client.acctNum - 1 ) * sizeof ( struct clientData ), SEEK_SET );

/* write user-specified information in file */
    fwrite( &client, sizeof ( struct clientData ), 1 , cfPtr );

/* enable user to input another account number */
    printf( "Enter account number\n? " );
	scanf( "%d" , &client.acctNum );
}

	fclose( cfPtr ); /* fclose closes the file */


  return 0;
}