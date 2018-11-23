# The Concept Of NULL

The concept of null is interesting and sometimes misunderstood. Confusion can occur because we often deal with several similar, yet distinct concepts, including:

* The null concept

* The null pointer constant

* The NULL macro

* The ASCII NUL

* A null string

* The null statement

---

When NULL is assigned to a pointer, it means the pointer does not point to anything. 

* The null concept refers to the idea that a pointer can hold a special value that is not equal to another pointer. 

* It does not point to any area of memory. 

* There can be a null pointer type for each pointer type, such as a pointer to a character or a pointer to an integer, although this is uncommon.


* Two null pointers will always be equal to each other. 

```c
#include<stdio.h>

int main(){


    char* charPtr1 = NULL;
    char* charPtr2 = NULL;
    int* intPtr1 = NULL;
    int* intPtr2 = NULL;

    if(charPtr1 == charPtr2){
        printf("charPtr1 is equal to charPtr2\n");  // true
    }

    if(intPtr1 == intPtr2){
        printf("intPtr1 is equal to intPtr2\n");    // true
    }
    
    
    // warning: comparison of distinct pointer types lacks a cast
    if(charPtr1 == intPtr1){                        
        printf("charPtr1 is equal to intPtr2\n");   // true
    }

    if( (void*)charPtr1 == (void*)intPtr1  ){   
        printf("casted versions of the charPtr1 and "
                "intPtr1 are equal to each other.\n"); // true
    }

}
```

---

The null concept is an abstraction supported by the null pointer constant.

* This constant may or may not be a constant zero. 
    * A C programmer need not be concerned with their actual internal representation.

The NULL macro is a constant integer zero cast to a pointer to void. In many libraries, it is defined as follows:

```c
#define NULL    ((void *)0)
```

This is what we typically think of as a null pointer. Its definition frequently can be found within several different header files, including stddef.h, stdlib.h, and stdio.h.

---

If a nonzero bit pattern is used by the compiler to represent null, then it is the compiler’s responsibility to ensure all uses of NULL or 0 in a pointer context are treated as null pointers. 

The actual internal representation of null is implementation-defined. The use of NULL and 0 are language-level symbols that represent a null pointer.

--- 


![](img/ascii.png)


The ASCII NUL is defined as a byte containing all zeros. 

* However, this is not the same as a null pointer. 

* A string in C is represented as a sequence of characters terminated by a zero value. 

* The null string is an empty string and does not contain any characters. 

---

* Finally, the [null statement](https://msdn.microsoft.com/en-us/library/1zea45ac.aspx) consists of a statement with a single semicolon.

> The "null statement" is an expression statement with the expression missing. 

> It is useful when the syntax of the language calls for a statement but no expression evaluation. 

> It consists of a semicolon.
  
> Null statements are commonly used as placeholders in iteration statements or as statements on which to place labels at the end of compound statements or functions.

* For example, when you want to find the index of first occurrence of a certain character in a string


```c
int a[50] = "lord of the rings";
int i;

for(i = 0; a[i] != 't'; i++)
    ;//null statement
//as no operation is required
```

```c
char *myStrCpy( char *Dest, const char *Source )  
{  
    char *DestStart = Dest;  
  
    // Assign value pointed to by Source to  
    // Dest until the end-of-string 0 is  
    // encountered.  
    while( *Dest++ = *Source++ )  
        ;   // Null statement.  
  
    return DestStart;  
}  
  
```

---