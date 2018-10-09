# Structs

Arrays are good for dealing with groups of identically typed variables, but
they are unsatisfactory for managing groups of differently typed data. To
service groups of mixed data, you need to use an aggregate type called a
structure.


* Declare a structure template called vitalstat; 

```c

// Declare Struct Teplate
struct vitalstat {

	char vs_name[19], vs_ssum[11];
	short vs_month, vs_day, vs_year;

};

// Declares an actual variable called vs with the vitalstat form.
struct vitalstat vs;

```

* You can also declare a tag name and variables together. 

```c

struct vitalstat{

	char vs_name[19], vs_ssum[11];
	short vs_month, vs_day, vs_year;

} vs, *pvs, vsa[10];

``` 


* This is useful if you want to declare a single structure type to be used in one place only.

```c

struct{

	char vs_name[19], vs_ssum[11];
	short vs_month, vs_day, vs_year;

} vs;


```

* In this case, the type VITALSTAT represents the entire structure declaration,
including the struct keyword.
	* Note that we use all capital letters for the typedef name to keep it distinct from regular variable names and tag names.


```c
typedef struct {

	char vs_name[19], vs_ssum[11];
	short vs_month, vs_day, vs_year;

} VITALSTAT;

// Declare variable
VITALSTAT vs;

vs = {"George Smith", "0023451526", "3", "5", "1946"};

/* Reference the structe members */

// Method 1

vs.vs_year = 2018;
vs.vs_day = 9;
vs.vs_month = 10;

if(vs.vs_month > 12 || vs.vs_day > 31){
	printf("Illegal Date!\n");
}

// Method 2

VITALSTAT *pvs = &vs;

if(pvs->vs_month > 12 || pvs->vs_day > 31){
	printf("Illegal Date!\n");
}

pvs->vs_month 
//is equal to
(*pvs).vs_month

```

## Arrays Of Structures

```c

VITALSTAT vsa[10];

```


```c

#include "v_stat.h" // contains declaration of VITALSTAT

int agecount(VITALSTAT vsa[], int size, int low_age, int high_age, int current_year){

	int i, age, count = 0;

	for(i = 0; i < size; ++vsa, ++i){
		age = current_year - vsa->vs_year;

		if(age >= low_age  && age <= high_age){
			count++;
		}
	}
	return count;
}


```

* Changing the original parameters can be dangerous sometimes and should be avoided when making complex software.

```c
#include "v_stat.h"

int agecount(VITALSTAT vsa[], int size, int low_age, int current_year){

	int age, count = 0;

	VITALSTAT *p, *p_last = &vsa[size];


	for(p = vsa; p <= p_last; ++p){
		age = current_year - p->vs_year;

		if(age >= low_age && age <= high_age){
			count++;
		}
	}

	return count;
}



```

## Nested Structure

* When one of the fields of a structure is itself a structure, it is called a
nested structure.

```c
#include <stdio.h>

typedef struct{

	char vs_name[19], vs_ssum[11];
	
	struct{
		short vs_day;
		short vs_month;
		short vs_year;
	} vs_birth_date;

} VITALSTAT;

VITALSTAT vs;

printf(vs.vs_birth_date.vs_year);

```

```c
#include <stdio.h>

typedef struct{
	char  day;
	char  month;
	short year;
}DATE;

typedef struct {
	
	char vs_name[19], vs_ssum[11];
	
	DATE vs_birth_date;

} VITALSTAT;

VITALSTAT vsa[1000];

```



















