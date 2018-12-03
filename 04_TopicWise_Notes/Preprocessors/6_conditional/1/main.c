#include<stdio.h>

int main(){

#ifndef LIMIT
#define LIMIT "Yok"
#endif

#ifdef LIMIT
#undef LIMIT
#endif

#define message_for_you(fmt,args...) printf(fmt, #args);  

	message_for_you("%s\n", "Hey", "Reader");

	message_for_you("%s\n", "Whats up ?", "I hope you know what a variadic function is");



return 0;
}
