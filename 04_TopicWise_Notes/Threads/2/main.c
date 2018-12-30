#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t ids[2];

void* worker(void* arg){
	pthread_t id = pthread_self();
	if( pthread_equal(id, ids[0]) ){
		printf("Hello, From First Thread!\n");
	}else{
		printf("Hello, From Second Thread!\n");
	}
}

int main(){

	int i = 0, err;
	void** ret;

	for(i = 0; i < 2; i++){
		err = pthread_create(&ids[i], NULL, worker, NULL);
		if( err){
			printf("Thread can't be created!\n");
		}else{
			printf("Thread number: %d, has been created...\n", i+1);
		}
	}

	for(i = 0; i < 2; i++){
		pthread_join(ids[i], ret);
	}
	

	return 0;
}