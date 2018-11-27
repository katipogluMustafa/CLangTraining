# Built-in Macrolar

```c

__LINE__ // %d satır bilgisi

__FILE__ // %s dosya ismi	

__TIME__ // %s compilation-time

__DATE__ // %s compilation-date

__STDC__ // %d ANSI standardlarına uygun olup olmadığı


```

```c
printf("this program that last compiled on %s at %s", __DATE__, __TIME__);
```

```c
#define CHECK(a,b)  				\
	if( (a) != (b) ){ 				\
		fail(a,b,__FILE__,__LINE__);\
	}								\

void fail(int a, int b, char*p, int line){
	printf("Check failed in file %s at line %d",p, line);
}


```