# Void Pointer

* A pointer to void is a general-purpose pointer used to hold references to any data type.

```c
void *pv;
```

* It has two interesting properties:
 
    1. A pointer to void will have the same representation and memory alignment as a pointer to char.
 
    2. A pointer to void will never be equal to another pointer. However, two void pointers assigned a NULL value will be equal.
 
 ---
 
 * Any pointer can be assigned to a pointer to void. 
 
 * It can then be cast back to its original pointer type. 
    * When this happens the value will be equal to the original pointer value.

```
    int num = 471;
    int *pi = &num;
    printf("Value of pi: %d\n", *pi);    // Value of pi: 471
    void* pv = pi;
    pi = (int*) pv;
    printf("Value of pi: %d\n", *pi);    // Value of pi: 471
```

---

* Pointers to void are used for data pointers, **not function pointers**. 

* In Polymorphism in C, we will reexamine the use of pointers to void to address polymorphic behavior.

---

#### NOTE

Be careful when using pointers to void. If you cast an arbitrary pointer to a pointer to void, there is nothing preventing you from casting it to a different pointer type.

---

* The sizeof operator can be used with a pointer to void. However, we cannot use the operator with void as shown below:

```c
   size_t size = sizeof(void*);   // Legal
   size_t size = sizeof(void);    // Illegal
```

* The size_t is a data type used for sizes and is discussed in the section **Predefined Pointer-Related Types**.