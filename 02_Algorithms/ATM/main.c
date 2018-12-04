#include "session.h"

int main(){

	printf("********* ATM *********");
	int terminate = 0;
	int flag = 1;
	int fchoice;
	int sState;

	while(flag){
		printf("\n");
		printf("0 For Terminating The Session\n"
			   "1- Login\n"
			   "2- Register\n");
		scanf("%d",&fchoice);

		switch(fchoice){
			case 0:
					terminate = 1;
					break;
			case 1:
					sState = session();
					if( !sState){
						flag ^= flag;			// Sucessfull session	
					}else if( sState == -1 ){
						terminate = 1;			// Termination request
					}
					// Else						// Error while opening session
					break;						
			case 2:
					registerToSys();
					break;
			default:
					printf("\nErroneous Input\n");
		}
	}

	if(terminate){
		return 0;
	}


	return 0;
}
