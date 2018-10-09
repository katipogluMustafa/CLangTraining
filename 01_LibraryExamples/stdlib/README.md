# stdlib


### exit()

Terminates the calling process immediately. 

Any open file descriptors belonging to the process are closed and any children of the process are inherited by process 1, init, and the process parent is sent a SIGCHLD signal.

Syntax:
```c

void exit(int status)


```

Example:

```c

#include <stdio.h>
#include <stdlib.h>

int main () {
   printf("Start of the program....\n");
   
   printf("Exiting the program....\n");
   exit(0);

   printf("End of the program....\n");

   return(0);	
}

```


## Dynamic Memory Allocation Functions in standard library

* malloc() --> Allocates requested size of bytes and returns a pointer first byte of allocated space
* calloc() --> Allocates space for an array elements, initializes to zero and then returns a pointer to memory
* free()   --> Deallocate the previously allocated space
* realloc()--> Change the size of previously allocated space


### malloc()

The name malloc stands for "**memory allocation**".

Syntax: 

```c

ptr = (cast-type*) malloc(byte-size)

```

* The malloc() function returns a pointer to an area of memory with size of byte size. 
* If the space is insufficient, allocation fails and returns NULL pointer.

```c

ptr = (int*) malloc(100 * sizeof(int)); 

```

### calloc()

The name calloc stands for "**contiguous allocation**".

* The only difference between malloc() and calloc() is that, malloc() allocates single block of memory whereas calloc() allocates multiple blocks of memory each of same size and sets all bytes to zero.

Syntax:
```c

ptr = (cast-type*) calloc(n, element-size);

```

* This statement will allocate contiguous space in memory for an array of n elements.

```c

ptr = (float*) calloc(25, sizeof(float));

// This statement allocates contiguous space in memory for an array of 25 elements each of size of float,


```


### free()

Dynamically allocated memory created with either calloc() or malloc() doesn't get freed on its own. You must explicitly use free() to release the space.


Syntax:
```c

free(ptr);
// This statement frees the space allocated in the memory pointed by ptr.

```

### realloc()

If the previously allocated memory is insufficient or more than required, you can change the previously allocated memory size using realloc().

Syntax: 
```c

ptr = realloc(ptr, newSize);


```