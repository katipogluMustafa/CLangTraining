#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int ns_theater(char* s);
int sports_no_bieber(char* s);
int arts_theater_or_dining(char* s);
int sports_or_workout(char* s);

int main()
{


return 0;
}

void find( char** ADS, int NUM_ADS ,int(*match)(char*) ){
  int i;
  puts("Search results:");
  puts("----------------------------------------");
    
  for(i = 0; i < NUM_ADS;i++){
	if( match(ADS[i]) ){
		printf("%s\n",ADS[i]);
	}
  }
  
  puts("----------------------------------------");
}

int sports_no_bieber(char* s){
  return strstr(s,"sports") && !strstr(s,"bieber");
}

int sports_or_workout(char* s){
  return strstr(s,"sports") || strstr(s,"working out");
}

int ns_theater(char* s){
  return strstr(s,"NS") && strstr(s,"theater");
}

int arts_theater_or_dining(char* s){
  return strstr(s,"theater") || strstr(s,"arts") || strstr(s,"dining");
}

