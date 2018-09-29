#include <stdio.h>


int main(int argc, char *argv[]){

	float x = 2.345f;
	printf("%f\n",x);


	char letter = 'A';

	printf("%c\n",letter);
	printf("%d\n",letter);


	char first_name[] = "Mustafa";
	char last_name[] = "Katipoğlu";

	printf("%s %s\n",first_name,last_name);
	int i;
	for(i = 0;i < sizeof(first_name)/sizeof(char);i++){
		printf("%c\n",first_name[i]);
	}
	for(i = 0; i < sizeof(last_name)/sizeof(char);i++){
		printf("%c\n",last_name[i]);
	}

	long universe_of_defects = 1L * 1024L * 1024L * 1024L* 1024L * 1024 * 1024 * 7L;
	printf("%ld\n",universe_of_defects);

	unsigned long bugs = 1L * 1024L * 1024L* 1024L * 1024L* 1024L* 1024L * 7L;


	char n = '\0';
	printf("%ld\n",universe_of_defects * n);


	return 0;
}