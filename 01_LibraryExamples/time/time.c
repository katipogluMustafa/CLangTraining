#include <time.h>
#include <stdio.h>
//CLOCKS_PER_SEC number of processor per second

//size_t -> unsigned integer
//clock_t -> processor time
//time_t -> bir flag zaman belirler
/*time_t end =  time(0) +2
  end<=time(0) zaman geçmemiþse
  */
/*struct tm {
   int tm_sec;          seconds,  range 0 to 59          
   int tm_min;          minutes, range 0 to 59           
   int tm_hour;         hours, range 0 to 23             
   int tm_mday;         day of the month, range 1 to 31  
   int tm_mon;          month, range 0 to 11             
   int tm_year;         The number of years since 1900   
   int tm_wday;         day of the week, range 0 to 6    
   int tm_yday;         day in the year, range 0 to 365  
   int tm_isdst;        daylight saving time             
};*/


int main(){
	struct tm t;
	int a;
  t.tm_sec    = 10;
   t.tm_min    = 10;
   t.tm_hour   = 6;
   t.tm_mday   = 25;
   t.tm_mon    = 2;
   t.tm_year   = 89;
   t.tm_wday   = 6;
   puts(asctime(&t)); //asctime(const struct tm *timeptr), timeptr'nin gün ve zamanýný belirten bir pointer döndürür.
   
   time_t now;
   struct tm* timeinfo;
   timeinfo=localtime(&now); // time_t yi struct tm t'ye çevirmek
   printf("Simdiki zaman: %s",asctime(timeinfo));
   
   time_t flag = time(0)+5;
   scanf("%d",a);
   if(flag<time(0)){
   	printf("5 Saniye icinde input girdiniz.");
   }

}
