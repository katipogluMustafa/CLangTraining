#include<stdio.h>

int carp(int x, int y){

	if( y == 0){
		return 0;
	}

	if(y < 0){
		return -1 * x + carp(x,y+1);
	}

	return x + carp(x, y - 1);

}

int main(){

  printf("5 * 4 : %d\n",carp(5,4));
  printf("5 * -4 : %d\n",carp(5,-4));
  printf("-5 * -4 : %d\n",carp(-5,-4));
  printf("-5 * 4 : %d\n",carp(-5,4));

return 0;
}
