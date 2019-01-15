#include<stdio.h>

typedef struct{
 float latitude;
 float longtitude;
 char info[80];
}JSON;

/*
 * Example Input style: 42.363400,-71.098465,Speed = 21 
 */

/*
 * ./JSON < gps_device.data > output.json 
 * ./JSON < err_gps_device.data > output.json 
 * ./JSON < err_gps_device.data > output.json 2> errorBoard.txt
 */

int main(){
  JSON data[100];
  int pointer = 0;

  /* Take input */
  while( scanf("%f,%f,%79[^\n]",&data[pointer].latitude, &data[pointer].longtitude, data[pointer].info) == 3){
  	if( data[pointer].latitude < -90 ||  data[pointer].latitude > 90 ){
		fprintf(stderr,"Invalid latitude: %f\n",  data[pointer].latitude);
		return 2;
	}
	
	if(  data[pointer].longtitude < -180.0 ||  data[pointer].longtitude > 180){
		fprintf(stderr,"Invalid longtitude: %f\n",  data[pointer].longtitude);
		return 2;
	}
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
