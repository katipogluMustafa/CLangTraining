#include"person.h"
#define NUM 10

char* randomName(){
	int n = rand() % 20, i;
	char* str = (char*)malloc( n * sizeof(char) );

	for(i = 0; i < n; i++){
		str[i] = rand() % 26;
		str[i] += 97;
	}

	return str;
}

int main(void){
  srand( time(NULL) );
  
  FILE* fp = fopen("people.dat", "w+");
  int i;
  struct Person* arr[NUM];
  
  /* Create random data */

  for(i = 0 ; i < NUM; i++){
  	arr[i] = Person_create( randomName(), 
  				   15 + ( rand() % 80 ),
  				   195 - ( rand() % 50 ),
  				   50 + ( rand() % 80 )   
  				 );
  }
  
  /* Write random data into stream */
  assert(fp != NULL);

  fwrite(arr, sizeof(struct Person*), NUM, fp);


  /* Deallocation*/
  fclose(fp);
  for(i = 0; i < NUM; i++){
  	Person_destroy( arr[i] );
  }

return 0;
}


