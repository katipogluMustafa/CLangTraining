#include <stdio.h>

int main(int argc, char *argv[]){

	int i;

	if(argc >=2){

		for(i = 1; i < argc; i++){
			printf("%d - %s\n ",i ,argv[i]);
		}

		printf("*******");
	}

	char *countries[] = {
		"Turkey", "Greece", "Iraq", "Russia", "China"
	};

	int numOfState = 5;

	for(i = 0; i < numOfState; i++){
		printf("Country - %d : %s\n",i,countries[i]);
	}	


	return 0;

}