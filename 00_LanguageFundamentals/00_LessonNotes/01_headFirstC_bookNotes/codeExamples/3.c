#include<stdio.h>
#include<string.h>

int main(){

char s0[] = "dysfunctional";
char s1[] = "sfun";

if( strstr(s0,s1))
  printf("I found the %s in %s\n",s1,s0);
else
  printf("Nothing has been found...\n");
return 0;
}
