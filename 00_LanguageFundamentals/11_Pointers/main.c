#include <stdio.h>

int main(int argc,char* argv[]){

	// Create two arrays

	int ages[] = {23, 42, 12, 89, 2};

	char* names[] = {
		"Alan", "Frank",
		"Marry", "John", "Lisa"
	};

	// safely get the size of ages

	int i = 0, count = sizeof(ages) / sizeof(int);

	/* First Method */

	for(;i < count; i++){
		printf("%s has %d years alive.\n",names[i],ages[i]);
	}

	/* Second Method */
	printf("\n****************\n");

	int *cur_age = ages;
	char **cur_name = names;

	for(i = 0; i < count; i++){
		printf("%s is %d  years old.\n", *(cur_name + i), *(cur_age + i) );	
	}

	/* Third Method */
	printf("\n****************\n");

	for(i = 0; i < count; i++){
		printf("%s is %d years old again.\n", cur_name[i],cur_age[i]);
	}
	
	/*Fourth Method */
	printf("\n****************\n");

	for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++,cur_age++){

		printf("%s lived %d years so far. \n", *cur_name, *cur_age);

	}


}