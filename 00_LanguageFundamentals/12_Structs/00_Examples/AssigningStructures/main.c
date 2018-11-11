#include<stdio.h>

struct
{
int a;
float b;
} s1, s2,*ps;

int main(){

s1 = s2;
ps = &s1;
s2 = *ps;

return 0;
}