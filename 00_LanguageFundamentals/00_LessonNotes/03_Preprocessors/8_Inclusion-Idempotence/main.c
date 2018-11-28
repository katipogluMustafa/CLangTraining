#include<stdio.h>
#include"test.h"


#define MYTEST "test.h"

#ifndef MYTEST
#include "test.h"	
#endif

int main(){


	return 0;
}