#include<stdio.h>

int fun(int n){

    if( n >0 )
        return fun(n-1) + n;

return 0;
}

int fun1(int n){
    static int x = 0;
    
    if( n > 0){
        x++;
        return fun1(n-1) + x;        // x values will be added at returning time so it if n = 5, 
                                    // at the end of ascending, x will be 5 and at descending time all the x values will be 5
    }

return 0;
}


int main(){
    int a = 5;
    printf("fun:  %d \n", fun(a) );
    printf("fun1: %d \n", fun1(a) );
    // static int x = 0;                       // This one is not same global x as the fun1 was created, so the result doesn't change
    printf("fun1: %d \n", fun1(a) );        // If we call the same function again, still x global variable exist for this scope.
        
return 0;
}


