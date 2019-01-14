#include<stdio.h>

int main(){

char tracks[][80] = {
			"I left my heart in Harvard Med School",
			"Newark, Newark - a wondeful town",
			"Dancing with a Dork ",
			"From here to maternity",
			"The gril from Iwo Jima",
		 };

int i,j;

printf("\n\nLet's print using %%s\n");

for(i = 0; i < 5; i++){
	printf("%s\n", tracks[i]);	
}

printf("\n\nLet's print using %%c\n");

for(i = 0; i < 5; i++){
	for(j = 0; j < 80; j++){
		printf("%c",tracks[i][j]);
	}
	printf("\n");
}




return 0;
}
