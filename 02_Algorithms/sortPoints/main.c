#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct{

	int x;
	int y;

} Point;

void sort(Point* dizi, int n, int (*f)() ){
 	int i,j;
 	Point temp;
 	int dist1,dist2;
 	for(i = 0;i < n-1; i++){
 		for(j = 0; j < n- i - 1; j++){
 			dist1 = dizi[j].x *dizi[j].x + dizi[j].y * dizi[j].y;
 			dist2 = dizi[j+1].x *dizi[j+1].x + dizi[j+1].y * dizi[j+1].y;
 			if(  (*f)(dist1,dist2)  ){
 				temp = dizi[j];
 				dizi[j] = dizi[j+1];
 				dizi[j+1] = temp;
 			}
 		}
 	}

}

int main(){
	int artan(int, int);
	int azalan(int, int);	
	void print(Point*, int);

	time_t p;

	srand( time(&p) );
	int n,i,secim;
	Point* dizi;

	printf("Num Of Elements:");
	scanf("%d",&n);

	dizi = (Point*)malloc(n * sizeof(Point) );

	for(i = 0; i < n; i++){
		dizi[i].x = rand() % 10;
		dizi[i].y = rand() % 10;
	}

	printf("Azalan-Artan[0-1]");
	scanf("%d",&secim);

	printf("BEFORE:");
	print(dizi,n);


	if( secim ){
		sort(dizi,n,artan);
	}else{
		sort(dizi,n,azalan);
	}


	printf("SONRA:");
	print(dizi,n);


}


int artan(int dist1, int dist2){
	return dist1 > dist2;
}

int azalan(int dist1, int dist2){
	return dist1 < dist2;
}

void print(Point* dizi, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d - %d \n", dizi[i].x, dizi[i].y);
	}
}