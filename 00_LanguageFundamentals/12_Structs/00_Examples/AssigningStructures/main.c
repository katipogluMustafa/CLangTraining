#include<stdio.h>

struct
{
int a;
float b;
} s1, s2, sf(), *ps;

int main(){

s1 = s2;
s2 = sf() ;
ps = &s1;
s2 = *ps;

return 0;
}