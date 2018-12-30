#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void* myThreadFunc(void* x){
	while(1){
		printf("myThread\n");
		sleep(1);
	}
}

int main(){
	pthread_t myThread;

	if( !pthread_create( &myThread, NULL, myThreadFunc, NULL ) ){
		printf("Thread Creation is successful.\n");
	}else{
		fprintf(stderr,"Thread is not created!\n");
		exit(0);
	}

	while(1){
		printf("Main Thread!\n");
		sleep(1);
	}


	return 0;
}