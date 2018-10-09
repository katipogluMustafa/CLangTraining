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


