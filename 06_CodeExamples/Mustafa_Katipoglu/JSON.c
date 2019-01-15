#include<stdio.h>

typedef struct{
 float latitude;
 float longtitude;
 char info[80];
}JSON;

/*
 * Example Input style: 42.363400,-71.098465,Speed = 21 
 */

int main(){
  JSON data[100];
  int pointer = 0;

  /* Take input */
  while( scanf("%f,%f,%79[^\n]",&data[pointer].latitude, &data[pointer].longtitude, data[pointer].info) == 3){
	pointer++;

  }
   
  /* Output the JSON */
  puts("data=[");
  
  while( pointer-- ){
    printf("\t{latitude: %f, longtitude: %f, info: '%s'},\n", data[pointer].latitude, data[pointer].longtitude, data[pointer].info);
  }
  
  printf("%6s\n","]");
  

return 0;
}

/*
 * Scanf returns number of values it was able to read. 
 */
