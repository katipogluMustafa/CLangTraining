#include<stdio.h>

#define plot(moo) moo "moo"
int main(){
	
  printf("%s\n", plot("zzz"));
	
  #undef plot
  #define plot(moo) printf("%s\n", #moo); // stringification of moo using #moo
	
  plot("zzz");

return 0;
}
