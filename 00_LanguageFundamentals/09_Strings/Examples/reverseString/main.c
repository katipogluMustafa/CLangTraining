#include <stdio.h>

int main(int argc, char *argv[]){
    int length;
    
    printf("Size of the string: ");
    scanf("%d",&length);
    
    char str[length];
    
    printf("String: ");
    scanf("%s",str);
    

    for(int i = 0; i < length / 2; i++){
        char temp = str[i];
        str[i] = str[length - i- 1];
        str[length - i -1] = temp;
    }
    
    printf("%s\n",str);
}   
