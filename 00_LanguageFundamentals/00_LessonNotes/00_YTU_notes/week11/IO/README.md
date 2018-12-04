# IO

## Stream

Ordered series of byte.

Sahip olduğunuz cihaz ile program arasında köprü görevi görüyor.

* Klavyeden veri okuma/yazma
* File'dan veri okuma/yazma
* Processler arası pipe'da okuma
* Socket işlemlerinde


### Standard Streams

* stdin
* stdout
* stderr


### Pointer to a File Structure

* File Pointer
	* İlişkili FILE'ı gösteriyor.

* File position indicator
	* File'daki pozisyonu gösteriyor.

### TEXT & BINARY STREAM

* Satır sonunda newline olduğunu bildiğimiz stream, text stream

* Verinin olduğu gibi işlendiği ve satır sonlarında newline olup olmadığını bilmediğimiz işlemlerde Binary Stream kullanmamız gerekir.

### Buffering

* Her seferinde aygıta ulaşıp bişeyler almak programı çok yavaşlatır sürekli diske ulaşmaya çalıştığımızdan bunu çözmek için buffering yapılır.
	* (1.Katman)Birini işletim sistemi yapar, bir ara alan oluşturulur.İlgili yere gitmeden önce bi süre memoryde toplanır.
		* Buffer'ın boyutu bilgisayarın özelliklerine bağlı, CACHE vs.ye göre.
		* genelde 512 - 4096 byte arası.
		* Buffer'ların her birinie fixed size chunk denir, bloklar halinde sabit boyutlu olarka OS bunları tutar.
	* (2.Katman) C'de runtime'de sunulan buffeing katmanı.

#### Line Buffering

* Newline görene kadar buffer boyutunu aşmadığı sürece buffer'a alma. 

#### Block Buffering

* Default olarak block buffering kullanılır.

* Block olarak bufferlama yapılır.


#### Buffer Management

* Buffer'ların memory'de daha uzun tutulmasını sağlamak için C yapar.
* Memory'de ilgilendiğimiz verinin bulunma ihtimalini arttırmak için yapılır.

```c
fflush()	// Buffer'ı boşaltmayı sağlar.
```


Her zaman buffer kullanılmayabilir.Bazen buffer'lama mekanizmasını kapatmak isteyebiliriz.

```c
setbuf()	// 1- File pointer, 2- Buffer olarak kullanılacak karakter dizisini alır.

setbuf(stdin, NULL)	// Buffer'ı kapatır.Buffer olarak kullanılıcak yapıyı NULL oalrak tanımlamış oluyoruz.
```


## Error Handling

* Her IO işlemi çalıştığında hata oluşma ihtimali var.Hataların neler olduğunu anlayıp kullanıcıyı yönlendirmek için Error Handling kullanılır.

* Her dosyanın sonuna geldiğimizde EOF(End of file) görürüz.

```c
feof(FILE* fp)		// file'in sonuna gelip gelmediğini kontrol için kullanılır.

ferror(FILE* fp)			// Error flag'i kontrol etmke için kullanılıyor.Dosyada hata oluşup oluşmadığını anlamamızı sağlar.
// non-zero output, problem var
// zero output, problem yok.
```

```c
#include<stdio.h>
#define ERR_FLAG 1
#define EOF_FLAG 2


// Hata varsa onu anlamaya çalışan fonksiyon.
char stream_stat(FILE* fp){
	chat stat = 0;

	if( ferror(fp) ){
		stat |= ERR_FLAG;
	}

	if( feof(fp) ){
		stat |= EOF_FLAG
	}
	// Sadce error olduysa stat = 1
	// Sadce eof olduysa stat = 2
	// hem error hem eof olduysa stat = 3

	return stat;
}


```

## Opening And Closing A File

```c

FILE* fopen()	// 1- Dosya ismi, 2- Erişim Modu

```

## Modes

* r: sadece okuma yapar. Varolan bir dosyayı okuyabilir.(file indicator başta)

* w: yazma yapar. Böyle bi dosya yoksa boş olarak oluşturur var ise bu isimde bu dosya içindekileri boşaltır ve dosya başında yazma yapar.

* a: var olan dosyanın sonuna ekleme yapmak için açar.Eğer dosya yok ise oluşturur.

* r+: Hem dosyayı okumak hemde yazmak için açar. File position indicator dosyanın başında olur.Dosya yoksa hata verir.

* w+: Hem okuma hem yazma. Eğer dosya var is dosya 0lanır.Dosya yoksa sıfırdan oluşturur.File posinition indicator başta olur. Mecvut dosyayı silmiş oluruz bu şekilde açarsak.

* a+: Hem okuma hemde ekleme için. Var olan dosyayı açar. Dosya yoksa yeniden oluşturur.Dosya varsa sadece açıyor sıfırlamış olmuyor. istediğin yerden veri okuyabilirsin ancak dosyanın sonuna ekleme yapabilirsin.

* Binary işlem yapmak için yukardaki modların sonuna b ekleyerek binary stream ile iş yapmış oluruz. Örneğin rb, w+b


```c

#include<stdio.h>
#include<stdlib.h> // exit() için.


int main(){
	FILE *fp = fopen("note.txt", "w");

	if( !fp ){
		printf("Dosya acilamadi.");
		exit(0);
	}

	fclose(fp); // buffer'i temizliyo ve fp yi başka bi dosya ile ilişkilendirebiliriz bu aşamadna sonra.

	return 0;
}


```

```c

#include<stdio.h>

FILE* open_file(char*, char*);

int main(){

	char file_name[20], access_mode[4];

	FILE *fp;
	scanf("%s %s", file_name, access_mode);


	fp = open_file(file_name, access_mode);

	fclose(fp);

	return 0;
}

FILE* open_file(char* file_name, char* access_mode){

	FILE* fp = fopen(file_name, access_mode);

	if( !fp ){
		printf("Error");	
	}

	return fp;

}

```

## Reading And Writing Data

* 3 Şekilde okuma ve yazma ihtimalimiz var.

1. one character at a time

2. one line at a time

3. one block at a time


### Karkater Karakter okuma

```c
// Makro olarak tanımlı
getc()
putc()
// Fonksiyon olarak tanımlı
fgetc()
fputc()

```

```c
// fi , file input dosya.
// fo, file output dosya
char ch;

ch = getc(fi);
putc(ch,fo);

```

```c
#include<stdio.h>
#define FAIL    (0)
#define SUCCESS (1)
#define LINESIZE 100


int copyFileCharByChar(char* inFile, char* outFile){
  
  FILE *fp1, *fp2;
  
  char ch, ch2;
  int charNum = 0;

  if(  ( fp1 = fopen(inFile, "r") ) == NULL ){
  	return FAIL;
  }
  
  if( ( fp1 = fopen(outFile, "w") ) == NULL ){
  	fclose(fp1);	// çıkmadan açık olsan fp1 stream'ini kapat.
  	return FAIL;
  }
/*
  fscaf(fp1, "%c", &ch2); // ilk karakteri okuduk pozisyon tutan şey şuan 2.karakteri gösteriyor ilk karakteri okuduğumuzdam.
  
  while( !feof(fp1) ){
  	
  	ch = getc(fp1);
  	putc(ch, fp2);
  	charNum++;
  
  }
*/
  // Böyle daha iyi üsttekinden böylece son karakter için döngüye girdikten sonra ek olarak döngüye girmicek yukardaki kod fazladan 1 adım döngüye girer ve ekrana beklenmedik bi karakter yazar en sona.
  fscaf(fp1, "%c", &ch2);
  ch = getc(fp1);
  while( !feof(fp1) ){
  	
  	putc(ch, fp2);
  	ch = getc(fp1);
  	charNum++;
  
  }

  fclose(fp1);
  fclose(fp2);

  return SUCCESS;
}

int main(){
    char file1[20], file2[20];
    scanf("%s %s", file1, file2);

    if( copyFileCharByChar(file1, file2) == SUCCESS ){
    	printf("Sucessful Copy");
    }else{
    	printf("Failed to Copy");
    }

	return 0;
}

```



### Satır satır okuma

```c

// fgetc vs. gibi fonksiyonlardan oluşturulmuştur bu fonksiyonlar.
fgets() // düzgün okuma yaptıysa buffer'ı döndürüyor.
fputs()

```

```c
// fi , file input dosya.
// fo, file output dosya
while( gets(line, lineSize, fi) != NULL ){
	fputs(line, fo);
}

// lineSize, satırda max kaç karakter okuyabilirim.
// line char*, içine okuyacağımız buffer.

```

```c
/* File Copy ~ char by char - line by line*/

#include<stdio.h>
#define FAIL    (0)
#define SUCCESS (1)
#define LINESIZE 100

int copyFileLineByLine( char* inFile, char* outFile ){
  
  FILE *fp1, *fp2;
  char line[LINESIZE];
  int lineNum = 0;

  if( ( fp1 = fopen(inFile, "r") ) == NULL  )
  	return FAIL;

  if( ( fp2 = fopen(outFile, "w") ) == NULL ){
    fclose(fp1);
    return FAIL;
  }

  // en sonda newline olsun diye LINESIZE - 1 yaptık.
  while(  ( fgets(line, LINESIZE - 1, ) ) != NULL ){ 
  	fputs(line, fp2);
  	lineNum++;
  }

  fprintf(fp2, "dosyada %d satir var\n",lineNum);
  fclose(fp1);
  fclose(fp2);

  return SUCCESS;

  // en sona new line ı kendisi koyuyor. kendin koymana gerek yok.
}

int main(){
    char file1[20], file2[20];
    scanf("%s %s", file1, file2);

    if( copyFileLineByLine(file1, file2) == SUCCESS ){
    	printf("Sucessful Copy");
    }else{
    	printf("Failed to Copy");
    }

	return 0;
}

```



### Blok Blok

```c

fread()
fwrite()

```

```c

// size_t	 okunan karakterlerin boyutu byte cinsinden

size_t fread(void* ptr, site_t size, size_t n, FILE* str)
// ilk parametre okunacak dizinin tutulacağı dizinin pointerı.
// ikinci parametre arraydaki her elemanın boyutu
// Ücüncü parametre okunacak elemean sayısı
// sondada file pointer

fwrite(void* ptr, size_t size, size_t n, FILE* stream  )

```


```c
// iki dosyan var içinde binary olarak öğrencilerin isimleri bilgileri puanları var
// iki dosyadada öğrenciler sıralı olarak kaydedilmiş bu bilgileri sıralı olarak birleştirip yeni bir dosyaya kaydedicez.
// blok blok okicaz ve blokların her biri bilgileri tutan structure olucak.


#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char isim[20], soyisim[20];
	int numara;
	float puan;
} OGRENCI;

void dosyaOlustur();
void dosyaOku(FILE*);

int main(){
    
    FILE *fa, *fb, *fs;   

    OGRENCI ogr1, ogr2;
    dosyaOlustur();

    fa = fopen("Akitap.bin", "rb");
    if( fa == NULL){
		exit(0);
	}
    fb = fopen("Bkitap.bin", "rb");
    if( fb == NULL){
    	fclose(fa);

		exit(0);
	}
    fs = fopen("Sonuc.bin", "wb");
    if( fs == NULL){
    	fclose(fa);
		fclose(fb);

		exit(0);
	}

	fread(&ogr1, sizeof(OGRENCI), 1, fa);
	fread(&ogr2, sizeof(OGRENCI), 1, fb);

	while( !feof(fa) && !feof(fb) ){
		
		if(  ogr1.puan < ogr2.puan  ){
			fwrite(&ogr2, sizeof(OGRENCI),1, fs);
			fread(&ogr2, sizeof(OGRENCI), 1, fb);
		}else{
			fwrite(&ogr1, sizeof(OGRENCI), 1 ,fs);
			fread(&ogr1, sizeof(OGRENCI), 1 , fa);
		}

	}
	// 1.dosyanın sonuna gelindiyse 2.dosyada kalan öğrencileri sonuc'a ekle
	// 2.dosyanın sonuna gelindiyse 1.dosyada kalan öğrencileri sonuc'a ekle


	if( feof(fa) ){
		while( !feof(fb) ){
			// en son elimizde bi okuma yapılmştı zaten else kolunda ondan direk fwrite yaptık.
			fwrite(&ogr2, sizeof(OGRENCI), 1, fs );
			fread(&ogr2, sizeof(OGRENCI), 1, fb);
		}
	}else{
		while( !feof(fa) ){
			fwrite(&ogr2, sizeof(OGRENCI), 1, fs );
			fread(&ogr2, sizeof(OGRENCI), 1, fa);	
		}
	}

	// Yukardaki if in öğrenci öğrenci değilde blok olarak atan versiyonunu yaz.

	return 0;
}

void dosyaOlustur(){
	// girdiler sıralı olarak verildiği varsayılıyor.

	int na,i;
	OGRENCI ogr;
	FILE* fs;

	fs = fopen("Akitap.bin", "wb");
	if( fs == NULL){
		exit(0);
	}
	scanf("%d", &na); // A kitapçıktaki öğrenci sayısı na yı al

	// her blok bir öğrenci olarak

	for(i = 0; i < na; i++){
		scanf("%s %s %d %f", ogr.isim, ogr.soyisim, ogr.numara, ogr.puan);
		fwrite(&ogr, sizeof(OGRENCI), 1, fs);
	}
	fclose(fs);		// kapatırsak tekrar fs ile başka bir dosyaya erişebiliriz.

	// her blok bir dizi öğrenci

	fs = fopen("Bkitap.bin", "wb");
	OGRENCI ogrDizi[20];

	scanf("%d", &nb);	// B kitapçıktaki öğrenci sayısı

	for(i = 0; i < nb; i++){
	  
	  scanf("%s %s %d %f", ogrDizi[i].isim, ogrDizi[i].soyisim, ogrDizi[i].numara, ogrDizi[i].puan);
	 
	}

	fwrite(ogrDizi, sizeof(OGRENCI), nb, fs);

}





```

### Formatlı okuma yazma

```c

fprintf()
fscanf()

```




























































































