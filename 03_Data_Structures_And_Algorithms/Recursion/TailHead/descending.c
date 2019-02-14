#include<stdio.h>

void fun(int n){
  if( n > 0){
    fun(n-1);               // We call first the function
    printf("%d ", n);
  }
}

int main(){

    int x = 8;
    fun(x);


return 0;  
}
