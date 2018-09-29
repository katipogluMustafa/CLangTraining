#include <stdio.h>

int main(int argc,char *argv[]){
	int i = 0;

	/* If Else */

	if(argc == 1){
		printf("You don't have any argument!\n");		
	} else if(argc > 1 && argc < 4){
		printf("Here your arguments...\n");
		for(i = 1; i < argc; i++){
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments!\n");
	}

	/* While loop */

	i = -10;
	while( i < 0){
		printf("%d\n",i);
		i++;
	}

	while(i >= -10){
		printf("%d\n",i);
		i--;
	}

	/* Switch Statements */
	/*
     * In C, the switch-statement is actually quite different and is really a jump table. 
     * Instead of random Boolean expressions, you can only put expressions that result in integers. 
     * These integers are used to calculate jumps from the top of the switch to the part that matches that value.
	 */

	if (argc > 6){
		printf("Error: you can't have more than 5 argument!");
		return 1;
	}


	if(i < 2){
		printf("Error: you don't have any argument\n");
		return 1;
	}

	i = 0;

	for(;argv[1][i] != '\0'; i++){
		char letter = argv[1][i];

		switch(letter){
			case 'a':
			case 'A':
				printf("%d: 'A'\n",i);
				break;

			case 'e':
			case 'E':
				printf("%d: 'E'\n",i);
				break;	
			case 'i':
			case 'I':
				printf("%d: 'I'\n",i);
				break;
			case 'o':
			case 'O':
				printf("%d: 'O'\n",i);
				break;
			case 'u':
			case 'U':
				printf("%d: 'U'\n",i);
				break;
			case 'y':
			case 'Y':
				if (i > 2) {
					printf("%d: 'Y'\n",i);
				}				
				break;
			default:
				printf("%d: %c is not a vowel\n",i,letter);		

		}
		/*
		 *  Once it knows the location, the program jumps to that spot in the code, and then continues running.
			  This is why you have break on some of the case blocks but not on others.
		 * If 'a' is entered, then it jumps to case 'a'. There’s no break, 
		    so it “falls through” to the one right under it, case 'A', which has code and a break.
 			Finally, it runs this code, hits the break, and then exits out of the switch-statement entirely.	  
		 * Always include a default: branch so that you catch any missing inputs.
		 * Don’t allow fall through unless you really want it. 
		    It’s also a good idea to add a //fallthrough comment so people know it’s on purpose.
		 * Always write the case and the break before you write the code that goes in it.
		 */
	}



}

/*
 * In C, there really isn’t a Boolean type.
 * Instead, any integer that’s 0 is false or otherwise it’s true. 
 */