#include<stdarg.h>
#include<stdio.h>

enum drink{
 WATER, COLA, COFFEE, MILK,
};

double price(enum drink d)
{
  switch(d) {
  case WATER:
    return 6.79;
  case COLA:
    return 5.31;
  case COFFEE:
    return 4.82;
  case MILK:
    return 5.89;
  }
  return 0;
}

double total(int args, ...){
  double total = 0;
  int i;
  va_list myList;
  va_start(myList, args);
  for(i = 0; i < args; i++){
     total += price( va_arg(myList, double) );  
  }
  va_end(myList);
  
return total;
}

int main(){
  printf("%lf\n", total(8,WATER, COLA, COFFEE, MILK,WATER, COLA, COFFEE, MILK));
  printf("%lf\n", total(5,WATER, COLA, COFFEE, MILK,WATER, COLA));
return 0;
}
