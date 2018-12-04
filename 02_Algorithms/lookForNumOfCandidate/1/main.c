#include"person.h"

struct Person** takeStream(FILE* fp){	
	int capacity = 2, i;
	struct Person** list = (struct Person**) malloc( capacity * sizeof(struct Person*) );


	for(i = 0; !feof(fp); i++){
		list[i] = (struct Person*)malloc( sizeof(struct Person) );
		fread(list[i], sizeof(struct Person*),1, fp);

		if( i == capacity ){
			capacity *= 2;
			list = (struct Person**)realloc(list, capacity * sizeof(struct Person*) );
		}
	}

	if(++i < capacity){
		list[i] = NULL;
	}else{
		capacity += 1;
		list = (struct Person**)realloc(list, capacity * sizeof(struct Person*) );
		list[i] = NULL;	
	}

	return list;
}

struct Person* fillRandomPerson( struct Person** list ){
  // take random person from the binary stream
  // assign values to to person
  int num = 0;
  int i;
  
  for(i = 0; list[i] != NULL; i++, num++);

  return list[rand() % num];
}



void Person_print(struct Person* who){

  printf("Name: %s\n",(*who).name);
  printf("\tAge: %d\n", (*who).age);
  printf("\tHeight: %d\n", (*who).height);
  printf("\tWeight: %d\n", (*who).weight);

}	
 	
int main(int argc, char* argv[]){

  /* Declarations */
  srand( time(NULL) );
  struct Person** team;
  int n;
  int NumOfPossibleCandidates = 0,capacity = 2;
  struct Person** possibleCandidates = (struct Person**)malloc( sizeof(struct Person*) * capacity );
  register int i;
  
  /* Process */  
  
  if(argc < 1){
    printf("You need to send num of people as the parameter of the main function.");
    exit(0);
  }else if( argc == 2){
    n = atoi( argv[1] );
    team = (struct Person**)malloc( n * sizeof(struct Person*) );
  }

  FILE* fp = fopen("people.dat", "r+");
  struct Person** data = takeStream(fp);
  for( i = 0; i < n; i++){
    team[i] = fillRandomPerson( data );
  }
 
  // let every person become 5 years older than now.
  for(i = 0; i < n; i++){
    team[i]->age += 5;
  }
  
  for(i = 0; i < n; i++){
    if( team[i]->age >= 18 && team[i]->age <= 27 ){
    	
	if(NumOfPossibleCandidates == capacity){
          possibleCandidates = (struct Person**)realloc(possibleCandidates, capacity * 2 * sizeof(struct Person*) );
	  capacity *= 2;
   	}
        possibleCandidates[NumOfPossibleCandidates] = team[i];
	NumOfPossibleCandidates++;
    }
  }

  /* Output */

  printf("Num of Possible Candidates: %d\n", NumOfPossibleCandidates);
  for(i = 0; i < NumOfPossibleCandidates; i++){
    Person_print( possibleCandidates[i]  );
  }
  
  /* Deallocation */

  for(i = 0; i < n; i++){
    Person_destroy(team[i]);
  }
  free(team);
  free(possibleCandidates);
  fclose(fp);
  return 0;
}
