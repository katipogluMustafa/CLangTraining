#include<stdio.h>
#include "user.h"

int session(){
	
	int login();

	User user = login();

	if( !user ){
		printf("ID and Password does not match! Please try again");
		return 1;
	}

	for(;;){
		int flag = 1;
		int choice;

		printf(		"0- Terminate the program\n"
					"1- Check Balance\n"
					"2- Deposit\n"
					"3- Withdraw\n"
					"4- Transfer\n"
					"5- Take Credit\n"
					"6- Log out\n"				);
		
		scanf("%d", &choice);
		switch(choice){
			case 1:
					//checkBalance();
					break;
			case 2:
					// deposit();
					break;
			case 3:
					// withdraw();
					break;
			case 4:
					// tarnsfer();
					break;
			case 5:
					// takeCredit();
					break;
			case 6:
					// log_out();
					break;
			case 7:
					// terminate
					break;
			default:
				printf("\nPlease try again...\n\n");
		}

		if( !flag ){
			break;			// break the loop
		}

	}

	return 0;
}


User login(){	
	printf("\n\n Login \n\n");
	
	char id[100];
	char pass[30];

	printf("ID:\n");
	scanf("%s", id);

	printf("PASSWORD:\n");
	scanf("%s", pass);


	return getUser(id,pass); 
}	