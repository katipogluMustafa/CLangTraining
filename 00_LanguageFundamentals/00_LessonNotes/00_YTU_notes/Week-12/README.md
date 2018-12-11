# Week 12

## Random Access to Files

```c

int fseek(FILE* stream, long int offset, int whence);
/* Offset değeri pozitif veya negatif değer alabilir.*/
/* possible whence values.

	- SEEK_SET	--> Dosya Başlangıcından itibaren offset kadar gitmemizi sağlar.
	- SEEK_END 	--> Sondan
	- SEEK_CUR	--> File indicator'un mevcut konumundan offset kadar ileri kadar geri gitmemizi sağlar.

*/

```


```c

stat = fseek(fp, 10, SEEK_SET);
/* file'ın 9. byte'ına götür file position indicator'ı.(0dan başlıyor) */

if( stat ){
	printf("Error!");
}

```

```c
/* File positipon indicator'un yerini döndürür.*/

long ftell( FILE* stream); 

/* örneğin binary değilde text dosyalarıyla uğraşırken kullanılıyor, konumumuzu bulmamızı sağlar işletim sistemi bağımlılıklarını halleder.*/

```

```c

cur_pos = ftell(fp);

// arama yaparken hata yaptıysak eski kaldığımız yere dön fseek ile.
if( search(string) == FAIL ){
	fseek(fp, cur_pos, SEEK_SET);
}

```

* ftell fonksiyonuna
	* Binary dosya gönderilirse
		* Number of bytes from the beginning of the file.
	* Text Dosya gönderilirse
		* implementation defined value that only has meaning when used as an offset to an fseek;

---

```c
#include<stdio.h>
#define NAME_LEN 20

typedef struct{

	char vs_name[NAME_LEN];
	char vs_ssnum[NAME_LEN];
	int vs_day;
	int vs_year;
	int vs_month;

}VITALSTAT;

int main(){
	char filename[20];
	
	FILE* data_file;


	scanf("%s", filename);

	print_file(filename);

	// r+ seçmemizin sebebi eski verilerin üzerinde dğeişiklik yapmak,
	// eğer a+ ile açsaydık yapamazdık. a+ sadece yeni ve ekleme ve değiştirmeye yarıyor.
	// eskiden varolana erişip değişmede fseek() ile dahi hata alıyoruz.
	data_file = fopen(filename, "r+b");
	list_file(data_file);

	int k;
	scanf("%d",&k);					// hangi kayıt i istediğimizi sor

	int offset = k * sizeof(VITALSTAT); // istenilen elemanın offsetini hesapla.
	fseek( data_file, offset, SEEK_SET );

	VITALSTAT vs;
	fread(&vs, sizeof(VITALSTAT), 1, data_file );
	scanf("%d", &vs.vs_year);		// doğum yılını sdeğiştirmek istiyoruz doğum yılını kullanıcıdan al.
	
	// ilgili kaydı olduğu gibi yazmamız lazım.
	// ya bu şekilde
	fseek(data_file, -1 * sizeof(VITALSTAT) , SEEK_CUR);
	// yada eski hesapladığımız offset değeri ile
	fseek(data_file, offset, SEEK_SET);

	fwrite(&vs, sizeof(VITALSTAT), 1, data_file);

	list_file(data_file);

	fclose(data_file);


	return 0;
}

void list_file(FILE* fp){
	VITALSTAT vs;
	// eskiden file position indicator nerde olursa olsun başa al
	long curr_pos = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while( !feof(fp) ){
		fread(&vs, sizeof(VITALSTAT), 1 , fp);
		// kayıtları yazdır
		printf("%s...", vs.vs_name,...);
	}
	// file position indicator ı kaldığımız yere geri al çıkmadan önce fonksiyondan
	fseek(fp, cur_pos, SEEK_SET);
}

void print_file(char filename[]){

	int nb,i;

	VITALSTAT vs;

	FILE* fs = fopen(filename, "wb");


	scanf("%d", &nb);
	for(i = 0; i < nb; i++){
		// vs'nin fieldlarını kullanıcıdan al
		scanf("%s %d.....", vs.vs_name......    );
		// sırayla her forda elemanları yazıyoruz.
		fwrite( &vs, sizeof(VITALSTAT), 1, fs );
		// sizeof(VITALSTAT) kısmı unsigned int veya unsigned long
	}

	fclose(fs);
}


```


```c

typedef struct{

	int no, sure, gol[3];	// 3 maçta atılan goller

} OYUN;


int main(){

	int i, y , n;

	OYUN *oyuncu;
	scanf("%d", &n);

	oyuncu = Structure_Yer_Ac_1(n);

	for(i = 0; i < n; i++){
		scanf("%d %d %d %d %d", 
				&oyuncu[i].no, &oyuncu[i].sure, 
				&oyuncu[i].gol[0], &oyuncu[i].gol[1], &oyuncu[i].gol[2]);
	}

	// oyuncuların tamamını dizi olarak alıp maximum verime sahip oyuncunun dizini kaçıncı elemanı olduğunu dönüyor.
	y = hesapla(oyuncu, n);
	printf("no %d", oyuncu[i].no);

	OYUN maxOyuncu;

	maxOyuncu = hesaplaV2(oyuncu, n); 		// return olarak max verimli oyuncunun kendisinin dönüyoruz bu sefer.

	return 0;
}


OYUN* Structure_Yer_Ac_1(int n){

	OYUN *dizi;

	dizi = (OYUN*)calloc( n, sizeof(OYUN) );

	return dizi;
}

int hesapla(OYUN* oyuncu, int n){

	int i, yer;

	float verim, maxVerim = 0;

	for(i = 0; i < n; i++){
		verim = oyuncu[i].gol[0] + oyuncu[i].gol[1] + oyuncu[i].gol[2];
		verim /= (float)sure;

		if(verim > maxVerim){
			maxVerim = verim;
			yer = i;
		}
	}

	return yer;
}


OYUN hesapla_V2(OYUN* oyuncu, int n){

	int i, yer;

	OYUN maxOyuncu;

	float verim, maxVerim = 0;

	for(i = 0; i < n; i++){
		verim = oyuncu[i].gol[0] + oyuncu[i].gol[1] + oyuncu[i].gol[2];
		verim /= (float)sure;

		if(verim > maxVerim){
			maxVerim = verim;
			maxOyuncu = oyuncu[i];
		}
	}

	return maxOyuncu;
}


OYUN hesapla_V3(OYUN* oyuncu, int n){

	int i, yer;

	OYUN maxOyuncu;

	float verim, maxVerim = 0;

	for(i = 0; i < n; i++){
		verim = oyuncu->gol[0] + oyuncu->gol[1] + oyuncu->gol[2];
		verim /= (float)sure;

		if(verim > maxVerim){
			maxVerim = verim;
			maxOyuncu = *oyuncu;
		}

		oyuncu++;
	}

	return maxOyuncu;
}
```


---

* eğer gollerin sayısı değişse.


```c

typedef struct{

	int no, sure, *gol, macSayisi;

} OYUN;


int main(){

	int i,j, y , n;
	int mac;
	OYUN *oyuncu;
	scanf("%d", &n);

	oyuncu = Structure_Yer_Ac_1(n);

	for(i = 0; i < n; i++){

		scanf("%d", &oyuncu[i].no);
		scanf("%d", &mac);
		oyuncu[i].macSayisi = mac;
		oyuncu[i].goal = (int*)calloc( mac, sizeof(int) );

		for(j = 0; j < mac; j++){
			scanf("%d", &oyuncu[i].gol[j] );
			scanf("%d", &oyuncu[i],sure);
		}

	}

	// oyuncuların tamamını dizi olarak alıp maximum verime sahip oyuncunun dizini kaçıncı elemanı olduğunu dönüyor.
	y = hesapla(oyuncu, n);
	printf("no %d", oyuncu[i].no);

	return 0;
}


OYUN* Structure_Yer_Ac_1(int n){

	OYUN *dizi;

	dizi = (OYUN*)calloc( n, sizeof(OYUN) );

	return dizi;
}

int hesapla(OYUN* oyuncu, int n){

	int i, j yer, toplam;

	float verim, maxVerim = 0;

	for(i = 0 ; i < n; i++){
		toplam = 0;
		for(j = 0; j < oyuncu[i].macSayisi; j++){
			toplam += oyuncu[i].gol[i];
		}
		verim = (float) toplam / oyuncu[i].sure;

		if(verim > maxVerim){
			maxVerim = verim;
			yer = i;
		}
	}

	return yer;
}


```


* elimde 4 tane integer sayı var, sayıların hepsini her bir haneyi 4 bit bilgide tutulucak structure yapısı kullanıyor.
* her bir field digitlerin bir tanesini tutucak, gönderirken tamamını göndericez.

--> benim çözümüm

```c

typedef union{
	struct{
		unsigned int x:4;
		unsigned int y:4;
		unsigned int z:4;
		unsigned int k:4;
	} sayilar;

	short q;

} DATA;

int main(){

	int n;
	int dizi[4];
	int q;

	printf("4 haneli sayi:");
	scanf("%d", &n);

	for(i = 0; i < 4; i++){
		dizi[i] = n % 10;
		n /= 10;
	}

	DATA myData;

	myData.sayilar.x = dizi[3];
	myData.sayilar.y = dizi[2];
	myData.sayilar.z = dizi[1];
	myData.sayilar.k = dizi[0];

	FILE* fp = fopen("cripted.dat", "w+b");
	fwrite(&mydata, sizeof(DATA), 1, fp);
	fclose(fp);
	return 0;
}


```

--> Hocanın Çözümü

```c

typedef union{
	struct{
		unsigned int digit1:4;
		unsigned int digit2:4;
		unsigned int digit3:4;
		unsigned int digit4:4;
	} digitAll;

	short int all;

} BCD;

int main(){

	int bilgi;
	unsigned int b1, b2, b3, b4;
	BCD code;

	scanf("%d", &bilgi);

	b1 = bilgi %10;

	bilgi /= 10;


	b2 = bilgi %10;

	bilgi /= 10;

	b3 = bilgi %10;

	b4 /= 10;

	code.digitAll.digit1 = b1;
	code.digitAll.digit2 = b2;
	code.digitAll.digit3 = b3;
	code.digitAll.digit4 = b4;
	/* rakamlar ters çıkabilir */
	printf("%d", code.all);

	return 0;
}

```

--> Şöylede yapılabilirdi, bitfield dizisi kullanarak.

```c

typedef struct{

	unsigned int digit:4

} DIGITS;

typedef union{
	
	DIGITS digitAll[4];

	unsigned int All;

}BCD;

int main(){
	BCD code;
	code.digitAll[0].digit = b1;

	int bilgi;
	unsigned int b1, b2, b3, b4;
	BCD code;

	scanf("%d", &bilgi);

	b1 = bilgi %10;

	bilgi /= 10;


	b2 = bilgi %10;

	bilgi /= 10;

	b3 = bilgi %10;

	b4 /= 10;

	code.digitAll[0].digit = b1;
	code.digitAll[1].digit = b1;
	code.digitAll[2].digit = b1;
	code.digitAll[3].digit = b1;
		/* rakamlar ters çıkabilir */
	printf("%d", code.all);



	return 0;
}


```

















