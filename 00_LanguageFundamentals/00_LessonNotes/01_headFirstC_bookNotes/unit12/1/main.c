#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<pthread.h>

void error(char* msg){
	fprintf(stderr, "%s: %s\n", msg, strerror(errno) );
	exit(1);
}

int main(void){
	void* does_not(void* a);
	void* does_too(void* a);

	pthread_t t0;
	pthread_t t1;

	if( ( pthread_create(&t0, NULL, does_not, NULL) ) == -1 )
		error("Can't Create Thread t0");
	if( ( pthread_create(&t1, NULL, does_too, NULL) ) == -1 )
		error("Can't Create Thread t1");

	void* result;

	if( ( pthread_join(t0, &result) ) == -1 )
		error("Can't join Thread t0");
	if( ( pthread_join(t0, &result) ) == -1 )
		error("Can't join Thread t1");

	/*
	 * The pthread_join() also receives the return value of your thread function and stores it in a void pointer variable.
	 */

	return 0;
}

void* does_not(void* a){
	int i;

	for(i = 0; i < 5; i++){
		sleep(1);
		puts("Does not!");
	}

	return NULL;
}


void* does_too(void* a){
	int i;

	for(i = 0; i < 5; i++){
		sleep(1);
		puts("Does too!");
	}

	return NULL;
}