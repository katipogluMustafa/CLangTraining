# Preprocessors

* Preprocessors `#` ile başlar.

* `#` satırdaki ilk karakter olmalı fakat herhangi bi satırda olabilir.

* \ ile alt satıra geçilebilir uzun makrolarda.

```c

#define LONG_MACRO "this is very\
					long macro"


```


* Aslında preprocessor'ın yaptığı şey bu koddaki BIG_BUFF ın ve N nin olduğu yerlere tanımlanmış olan şeyleri yapışıyor yani dinamil bir işlem yapmış olmuyoruz sadece copy paste yapıyoruz bu yüzdende sonuna noktalı virgül koymuyoruz eğer sona noktalı virgül koyarsan hata olur.

```c
#define N 100
#define BIG_BUFF 512

int main(){
	char kelime[BIG_BUFF];
	double numbers[N];
	return 0;
}

```


```c
#define N 100;			// hatalı noktalı  virgül
#define BIG_BUFF 512;	// hatalı noktalı  virgül

int main(){
	char kelime[BIG_BUFF];	// hatalı kod kelime[512;] <-- parantezin içinde noktalı virgül var.
	double numbers[N];		// hatalı kod numbers[100;] <-- parantezin içinde noktalı virgül var.
	return 0;
}

```

## Function Like Macro

* Fonksiyon gibi çalışabilen makrolar tasarlama şansımız var.

 --> define --> macro_name	--> makro_name ile arada boşluk bırakmadan ( -->  macro arguments   -->  ) --> macro body.


```c
#define MUL_BY_TWO(a) ( (a) + (a) )			// 2 ile yapma işini toplama ile yapıyoruz.

```


* Makrolar fonksiyonlardan daha hızlı çalışır çünkü makroların return yapmalar gerekmez ve tip kontrolü yapmazlar.
* Fakat makrolarn debug edilmesi daha zordur.
* macroya değişkenleri paranteze almaya alışmamız gerekiyo.

```c
#define MUL_BY_TWO(a) ( (a) + (a) )			// 2 ile yapma işini toplama ile yapıyoruz.

int main(){

	int j = MUL_BY_TWO(5);

	// aslında 
	// j = ( (5) + (5) )

	return 0;
}

```

* Fonksiyonları makrolara dönüştürmek sadece sık kullanılan durumlarda daha mantıklık


* Parantez kullanmazsak
```c
#define square(a) a*a

int main(){
	int j = 2 * square(3 + 4);	//2

	// j = 3 + 4 * 3 + 4 
	return 0;
}

```

* Parantez kullanırsak
```c
#define square(a) (a)*(a)

int main(){
	int j = 2 * square(3 + 4);	// 2 * ( (7) * (7) ) 
	return 0;
}

```

---

```c
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )

int main(){
	a = MIN(3,5);
	// a = ( (3) < (5) ? (3) : (5) )
	// a = 3
	int b=MIN(MIN(3,4),2);

	printf("%d", b);

	return 0;
}

```

---

* 2 elemanla min

```c
#define FIND_MIN(x,y)(		\
		if( (x) < (y) ){	\
			printf("%d", x);\
		}else{				\
			printf("%d", y);\
		})

```

```c
#include<stdio.h>

#define MIN(a,b) ( (a) < (b) ? (a) : (b) )

int main(){
	int b=MIN(MIN(3,4),2);

	printf("%d", b);

	return 0;
}
```


* 3 elemanla min

```c

#define FIN_MIN_OF_ALL(a,b,c) ( ( (a) < (b) ? ( (a) < (c) ) ? a : c ) : ( (c) < (b) ? c:b ) )  

```


* function call yapmadığı için hızlı
* tip kontrolü yok
* debug zor
* kodu gereksiz yere büyütüyor her seferinde macroyu koda kopyalandığından.
