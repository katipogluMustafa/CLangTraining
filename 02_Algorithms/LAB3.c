#include<stdio.h>
#include<stdlib.h>

typedef union {
	int adet;
	float kilogram;
	
}MIKTAR;

typedef struct sepet{
	int ID;
	float birimFiyat;
	int tip;
	MIKTAR miktar;
}SEPET;

typedef struct sepetOzeti{
	float toplamTutar;
	int* adetliUrunlerListesi;
	int adetliSay;
	int toplamAdet;
	int* kiloluUrunlerListesi;
	int kiloluSay;
	float toplamKilo;
}OZET;

OZET sepetEkle(SEPET* mysepet, int n){
	int i;
	int x = 0; // x = 0 ilk id
	OZET sepetOzeti;
	sepetOzeti.adetliUrunlerListesi = (int*)calloc(2, sizeof(int) );
	sepetOzeti.kiloluUrunlerListesi = (int*)calloc(2, sizeof(int));
	sepetOzeti.adetliSay = 0;
	sepetOzeti.kiloluSay = 0;
	sepetOzeti.toplamAdet = 0;
	sepetOzeti.toplamKilo = 0;
	sepetOzeti.toplamTutar = 0;
	
	int a = 2,k = 2;	// adetli ve kilolu dizi index;
	
	for(i = 0; i < n; i++){
		
		printf("Birim Fiyat\n");
		scanf("%f",&mysepet[i].birimFiyat);
		
		printf("Urun Tipi[0 adetli, 1 kilolu]\n");
		scanf("%d", &mysepet[i].tip);
		
		if(mysepet[i].tip == 0){
			printf("Urun Adeti:");
			scanf("%d",&mysepet[i].miktar.adet);

			if(sepetOzeti.adetliSay == a){
				sepetOzeti.adetliUrunlerListesi = (int*)realloc(sepetOzeti.adetliUrunlerListesi, a * 2 * sizeof(int) );
				a *=2;
			}
			
			sepetOzeti.adetliUrunlerListesi[sepetOzeti.adetliSay] = x;
			sepetOzeti.adetliSay += 1;
			sepetOzeti.toplamAdet += mysepet[i].miktar.adet;
		}else if(mysepet[i].tip == 1){
			printf("Agirlik Giriniz:");
			scanf("%f", &mysepet[i].miktar.kilogram);
			// ağırlıklılar listesine ekle
			if(sepetOzeti.kiloluSay == k){
				// ağırlıklı ürünler listesi genişlet
				sepetOzeti.kiloluUrunlerListesi = (int*)realloc(sepetOzeti.kiloluUrunlerListesi, k * 2 * sizeof(int) );
				k *= 2;
			}
			
			sepetOzeti.kiloluUrunlerListesi[ sepetOzeti.kiloluSay ] = x;
			sepetOzeti.kiloluSay += 1;
			sepetOzeti.toplamKilo += mysepet[i].miktar.kilogram;
		}
		
		mysepet[i].ID = x;
		sepetOzeti.toplamAdet += 1;
		sepetOzeti.toplamTutar += mysepet[i].birimFiyat;
		x++;
		
	}
	
	return sepetOzeti;
}

void ozetYaz(OZET sepetOzet){
	int i;
	printf("OZET\n");
	printf("Adetli Urun Cesidi: %d, Toplam Adet %d\n", sepetOzet.adetliSay, sepetOzet.toplamAdet);
	printf("Adetli Urunler: ");
	for(i = 0; i < sepetOzet.adetliSay; i++){
		printf("%d ", sepetOzet.adetliUrunlerListesi[i]);
	}
	printf("\n");
	printf("Kilolu Urun Cesidi: %d, Toplam kilo %f\n", sepetOzet.kiloluSay, sepetOzet.toplamKilo);
	printf("Kilolu Urunler: ");
	for(i = 0; i < sepetOzet.kiloluSay; i++){
		printf("%d ", sepetOzet.kiloluUrunlerListesi[i]);
	}
}

int main(){
	SEPET *mySepet;
	int n;
	
	printf("Urun Adedini Giriniz");
	scanf("%d", &n);
	
	mySepet = (SEPET*)malloc( sizeof(SEPET) *  n );
	
	OZET x = sepetEkle(mySepet, n);
	
	ozetYaz(x);
	
	return 0;
}


