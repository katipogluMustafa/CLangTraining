# Initializing Unions

In ANSI C (although not K&R C), you can initialize a union by assigning
the initialization value to the first union component:

```c
union init_example{
  int i;
  float f;
}

union init_example test = {1};
```

* If the first component of a union is a structure, the entire structure may
be initialized as in:

```c
union u {
	struct{ int i; float f;} S;
	char ch[6];	
};

union u test2 = {1, 1.0};
```
