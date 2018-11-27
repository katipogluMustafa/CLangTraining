// hesap topla 4 6
// topla yerine başka bişey girilirse çıkarma yap

#include<stdio.h>
#include<string.h>
#include<stdlib.h>			// atoi için

int main( int argc, char* argv[] ){

	int sayi1, sayi2;

	printf("%s\n",argv[0]);		// 0.indiste programın adı var.

	if(argc != 4){
		printf("Yanlis Kullanim");
		return 1;
	}else{

		sayi1 = atoi( argv[2] );		// atoi string kütüphanesinden
		sayi2 = atoi( argv[3] );				// atoi string'i int'e çevirmede kullanılıyor.
	}

	if( !strcmp("topla", argv[1]) ){			// strcmp 0 ise iki girdide aynıdır.

		printf("%d", sayi1 + sayi2);

	}else{

		printf("%d", sayi1 - sayi2);

	}

	return 0;
}