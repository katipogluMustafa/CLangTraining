#include<stdio.h>
#include<stdlib.h>

struct threeNum{

int n1,n2,n3;

};

int main(){

int n;
struct threeNum num;

FILE *fptr;

if( ( fptr = fopen("Asaf.txt","wb") ) == NULL){

  printf("Error!!!");

  exit(1);

}

fseek(fptr,-sizeof(struct threeNum),SEEK_END);
							//SEEK_END-> Starts the offset from end of the file.

for(n=1;n<5;++n){

  fread(&num,sizeof(struct threeNum),1,fptr);
  printf("n1: %d\tn2: %d\tn3: %d\n",num.n1,num.n2,num.n3);
  
  fseek(fptr,-2*sizeof(struct threeNum),SEEK_CUR);
							//SEEK_CUR->Starts the offset from the current location of the cursor in the file
	

}

fclose(fptr);

return 0;
}
