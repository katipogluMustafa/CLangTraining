#include<stdio.h>
#include<stdlib.h>

typedef struct{

	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char Y;

} IMG;

IMG** create(unsigned int row, unsigned int col);
void findGrayScale( IMG** mtr, unsigned int row, unsigned int col );
findHistogram(IMG** mtr, unsigned int n, unsigned int m, unsigned int* hist);

int main(){

	IMG **resim;
	unsigned int n,m,i,j;

	static unsigned int hist[256];		// Gözleri sıfırla static kullanarak

	scanf("%d %d", &n, &m);

	resim = crate(n,m);
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%u %u %u", &resim.R, &resim.G, &resim.B);			// matrisi doldur
		}
	}

	findGrayScale(resim,n,m);
	findHistogram(resim,n,m,hist);
	return 0;
}

IMG** create(unsigned int row, unsigned int col){
	unsigned int i;

	IMG** mtr;

	mtr = (IMG**)calloc( n, sizeof(IMG*));
	for(i = 0; i < m; i++){
		mtr[i] = (IMG*)calloc(m, sizeof(IMG));
	}

	return mtr;
}


void findGrayScale( IMG** mtr, unsigned int row, unsigned int col ){

	int i,j;
	for(i = 0; i < row;i++){
		for(j = 0; j < col; j++){
				mtr[i][j].Y = ( mtr[i][j].R + mtr[i][j].G + mtr[i][j].B ) / 3; 
		}
	}

}

findHistogram(IMG** mtr, unsigned int n, unsigned int m, unsigned int* hist){
	unsigned int i,j;
	for(i = 0; i < n;i++){
		for(j = 0; j < n; j++){
				hist[ mtr[i][j] ]++;
		}
	}


}