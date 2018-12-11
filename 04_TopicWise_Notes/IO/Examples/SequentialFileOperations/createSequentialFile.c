/* Create a Sequential File */

#include<stdio.h>

int main(){
	int account;		/* account number */
	char name[ 30 ];	/* account name */
	double balance;		/* account balance */

	FILE *fp; 			/* fo = clients.dat file pointer */

	if( ( fp = fopen("clients.dat", "w") ) == NULL ){
		printf("File could not be opened\n");
	}

	printf("Enter the account name and balance.\n");
	printf("Enter EOF to end input.\n");
	printf("? ");
	scanf("%d%s%lf", &account, name, &balance);

	 /* write account, name and balance into file with fprintf */
	while( !feof(stdin) ){
		fprintf(fp, "%d %s %.2f\n", account, name, balance);
		printf("? ");
		scanf("%d%s%lf", &account, name, &balance);
	}

	fclose(fp);

	return 0;
}
