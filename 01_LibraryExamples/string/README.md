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