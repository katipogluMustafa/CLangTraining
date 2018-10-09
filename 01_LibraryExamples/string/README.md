# string Library

This directory includes string functions of c.

## strlen

```c

int strlen(char str[]) {
	int i = 0;

	while(str[i])
		++i;
	return i;
}

```

## strcopy

```c
void strcpy(char *s1, char *s2){
	while(*s1++ = *s2++);
}

```

```c

void strcpy(char *s1, char *s2){
	int i;
	for(i = 0; *(s2 + i); ++i){
		*(s1+i) = *(s2 + i);
	}
	s1[i++] = 0; // add null at the end of the string
}

```