#include<stdio.h>
#include<string.h>

void print_reverse(char* s){
  size_t len = strlen(s);
  
  char* t = s + len - 1;

  while(*t){
    printf("%c", *t--);
  }
  printf("\n");
}

int main(){

print_reverse("Mustafa");

return 0;
}
