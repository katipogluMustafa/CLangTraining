# Pointers

## PRACTICAL POINTER USAGE

There are primarily four useful things you can do with pointers in C code:

1. Ask the OS for a chunk of memory and use a pointer to work with it. This includes strings and something you haven’t seen yet, structs.
2. Pass large blocks of memory (like large structs) to functions with a pointer, so you don’t have to pass the whole thing to them.
3. Take the address of a function, so you can use it as a dynamic callback.
4. Scan complex chunks of memory, converting bytes off of a network socket into data structures or parsing files.

* For nearly everything else, you might see people use pointers when they should be using arrays.
	*  In the early days of C programming, people used pointers to speed up their programs, because the compilers were really bad at optimizing array usage.
	*  These days, the syntax to access an array versus a pointer are translated into the same machine code and optimized in the same way, so it’s not as necessary.
	*  Instead, you should go with arrays whenever you can, and then only use pointers as a performance optimization if you absolutely have to.

## THE POINTER LEXICON

Whenever you run into a complex pointer statement, just refer to this and break it down bit by bit

```c

type *ptr // A pointer of type named ptr

*ptr // The value of whatever ptr is pointed at

*(ptr + i) // The value of (whatever ptr is pointed at plus i)

&thing // The address of thing

type *ptr = &thing // A pointer of type named ptr set to the address of thing

ptr++ // Increment where ptr points

```

## POINTERS AREN’T ARRAYS

No matter what, you should never think that pointers and arrays are the same thing. They aren’t the same thing, even though C lets you work with them in many of the same ways.

* For example, if you do sizeof(cur_age) [in the code](main.c), you would get the size of the pointer, not the size of what it points at.
	* If you want the size of the full array, you have to use the array’s name