#include <stdio.h>

void swap(int, int, char *);

int main(int Args, char *Argv[]){

int length;

printf("Length of the Input");
scanf("%d",&length);

char str[length];

printf("String: ");
scanf("%s",str);

int space;
int firstElement = 0;
for (int i = 0; i <= length; i++) {
	
	
	if(str[i] == '\0'){
		printf("boşluk girdi %d",i);
		space = i;
		for(int j = firstElement; j < (space - firstElement) / 2; j++){
			
			swap(j, space -j + firstElement -1, str);
		}
		firstElement =  space + 1;	
	}else {
		printf("%d\n",i);
		if(str[i] == '\0'){
			printf("girdi%d\n",i);
			for(int k = firstElement; k < (i - firstElement - 1) / 2; k++){
				
				swap(k,i - k - 1 + firstElement, str);
				
			}
		}
	}
	

}

printf("%s", str);


}

void swap(int index1, int index2, char str[]){
	char temp = str[index1];
	str[index1] = str[index2];
	str[index2] = temp;
}
