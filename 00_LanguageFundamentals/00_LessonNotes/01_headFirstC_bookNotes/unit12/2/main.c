#include<stdio.h>
#include<pthread.h>

int bottleOfWaters = 2000000;

int main(){
	void* drinkWater(void* a);
	int i;
	pthread_t threads[20];

	for(i = 0; i < 20; i++){
		pthread_create(&threads[i], NULL, drinkWater, NULL);
	}	

	void* result;
	for(i = 0; i < 20; i++){
		pthread_join(threads[i], &result);
	}

		

return 0;
}


void* drinkWater(void* a){
	int i;

	for(i = 0; i < 100000;i++){
		bottleOfWaters -= 1;
	}

	printf("There are %d bottles of water left...\n", bottleOfWaters);

	return NULL;
}
