#include<stdio.h>
#include<stdlib.h>

struct threeNum{
int n1,n2,n3;
};

typedef struct threeNum ThreeNumber;

int main(){

int n;
ThreeNumber num;

FILE *fptr;

if((fptr=fopen("AsafV2.txt","wb"))==NULL){
printf("Error!!!");

exit(1);
}

for(n=1;n<5;++n){
num.n1=0;
num.n2=1;
num.n3=1;

fwrite(&num,sizeof(ThreeNumber),1,fptr);//fwrite(adress od data,sizeofdata,how many data exist,file pointer).

}
fclose(fptr);

return 0;

}
