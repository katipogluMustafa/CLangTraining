#include<stdio.h>
#include<stdlib.h>


typedef struct{

	unsigned int digit: 4;

}DIGIT;

typedef union{

		DIGIT digits[4];
		unsigned short int all;

}DATA;

typedef struct{

	DATA* data;
	int numOfDigits;

}BCD;

int calcNumOfDigits(int n){
	int digits = 0;

	while(n){
		n /= 10;
		digits++;
	}

	return digits;
}

double power(double x, double y){

	double k = 1;
	int i;
	for(i = 0; i < y; i++){
		k *= x;
	}

	return k;
}

// k kaç dörtlü olduğu
// i kaçıncı dörtlüyü doldurduğumuz
// n ise sayı
void fillDigits(DATA data, int i, int k, int n){
	int j,div = 1, num;
	double dummy,tenTothePowerOfDummy;
	int numOfDigits = calcNumOfDigits(n);
	

	// 3 situation, 
				// i = 0,  first 4 digit
				//  i = middle 4 digit
				//  i = k, last digits

	if(i == 0 && k > 1){ 		// if we're looking for the first tetrad of the number

		dummy = numOfDigits - 4;

		tenTothePowerOfDummy = power(10, dummy);

		num = n / (int)tenTothePowerOfDummy;

	}else if(i == k){ 			// if we're looking for the last tetrad of the number

		// dummy = number of digits other than first series of tetrads.
		dummy =  numOfDigits - i * 4;

		// tenTothePowerOfDummy = 10 ^ dummy
		tenTothePowerOfDummy = power(10, dummy);

		// num = last dummy digits of the n
		num = n % (int)tenTothePowerOfDummy; 		// get the last digits of the number

	}else if(i < k){ 		// if we're not looking for the last or first tetrad of the number

		dummy = numOfDigits - i * 4;

		tenTothePowerOfDummy = power(10, dummy);
		
		// destroy the digits comes after us
		num = n % (int)tenTothePowerOfDummy;

		// destroy the digits comes us before us
		num = num % 10000;

	}

	// fill the digits[4], digit by digit
		for(j = 0; j < 4; num /= 10, j++){
			data.digits[3 - j].digit = num % 10;
		}

}


DATA* getBCDdata(BCD bcd, int n){
	DATA* data;

	int k = bcd.numOfDigits / 4 + 1; 		// her biri 4 hane olan Digit dizilerinden oluşan bi data oluşturcaz.

	data = (DATA*)malloc( k * sizeof(DATA)  ); 	// her 4 hane için 1 data, totalde n tane data için yer aç.

	int i;
	for(i = 0; i < k; i++){
		 fillDigits(data[i],i, k, n); 
	}

	return data;
}

BCD getBCD(int n){
	BCD bcd;
	
	bcd.numOfDigits = calcNumOfDigits(n);
	bcd.data = getBCDdata(bcd,n);

	return bcd;
}

int main(int argc, char* argv[]){

	int n,i;
	printf("n: ");
	scanf("%d", &n);

	BCD num = getBCD(n);

	int numOfDigits = calcNumOfDigits(n);

	int x = numOfDigits / 4 + 1;

	for(i = 0; i < x; i++){
		printf("%x\n", num.data[i].all);
	}

	free(num.data);

	return 0;
}