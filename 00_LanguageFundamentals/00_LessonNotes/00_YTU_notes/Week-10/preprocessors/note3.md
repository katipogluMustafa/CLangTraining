# Conditional Preprocessors

`#if`


`#else`


`#elif`


`#endif`


```c

// undif komutu tanımlanmış bir makroyu undefined yapar.
# if x == 1
	#undef x
	#define x 0
# elif x == 2
	#undef x
	#define x 3
# else
	#define y 4

#endif


```