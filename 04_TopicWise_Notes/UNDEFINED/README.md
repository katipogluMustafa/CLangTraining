# Undefined Questions in C

a) What is the output of following code?

```c
int i = 7;
printf( “%d”, i++ * i++ );
```

b) What would happen to the array after executing the following statements?

```c
int a[5], i = 1;
a[i] = i++;
```
c) What is the value of i after the execution of the following statement?

```c
int i = 7;
i = ++i;
```

These idiotic questions are very often asked in Programming world. 

The outputsare undefined. 

Even if such questions are asked, the right answer will be “the result is undefined”.

## Note
For the above program, you may get some output. But it is wrong. You have to understand that compilers
may not check ‘Undefined’ grammars.