# Proprocessors


```c

#define x 2

#if x == 1
	printf("öyle");		// 1 ise bura derlenir.

#elif x == 2
	printf("böyle");	// 2 ise bura derlenir.

#endif
```


```c
#if DEBUG
	
	if(exp && DEBUG){

		.
		.
		.
		.
		.

	}
#endif

```

* Platform değişikliği olduğunda kolaylıkla küçük bir makronun değişiiyle ilgili kodu derlemenizi sağlayabilirsiniz.


## Testing Macro Existince


```c

#ifdef x		
// #if defined x

#ifndef x		
//#if ! defined x

#if def Test
	printf("This is a test");
#else
	printf("not a test");

```

```c
#if !FALSE	// if false was defined as 0, this would fail to differentiate defined or undefined.
	#define FALSE 0
#endif
```


```c
#ifndef FALSE
	#define FALSE (0)
#elif FALSE	// tanımlıysa 
	#undef FALSE
	#define FALSE (0)


```




























