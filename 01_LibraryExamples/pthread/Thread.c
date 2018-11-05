#include <pthread.h>
#include <stdio.h>

//int pthread_cancel(pthread_t thread)
//int pthread_create(pthread_t * pth, pthread_attr_t *att, void * (*function), void * arg);
//pthread_detach(pthread_t t)
//pthread_join(pth,NULL)
//baðýmsýz kod parçalarýný eþ zamanlý çalýþtýrmak için thread kullanýlmalýdýr.
void *threadFunc(void *arg)
{
	char *str;
	int i = 0;
	int a=0;
	str=(char*)arg;

	while(i < 110)
	{
		usleep(1);
		printf("\nfunc: %d\n",i);
		++i;
	}

	return NULL;
}

int main(void)
{
	pthread_t pth;	// this is our thread identifier
	int i = 0;

	pthread_create(&pth,NULL,threadFunc,"fo");//Parametreler: .(thread,NULL,Fonksiyon,Fonksiyon parametresi)
	
	while(i < 100)
	{
		usleep(1);
		printf("main: %d\n",i);
		++i;
	}

	printf("main waiting for thread to terminate...\n");

	pthread_join(pth,NULL); //Pthread'ýn bitene kadar beklenmesi
	return 0;
}
