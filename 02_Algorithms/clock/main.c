#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> // for Delay in linux gcc

void printTime(int);
void printHours(int);
void printMins(int);
void printSeconds(int);

int main(){

int sec = 0;
int temp;

printf("Please give the starting time for the clock - 24 hour Format\n");

// Take Hour
printf("Hour:");
scanf("%d",&temp);

printf("\n");

sec += temp * 3600;

// Take Min
printf("Minutes:");
scanf("%d",&temp);

printf("\n");

sec += temp * 60;

// Take Secs
printf("Seconds:");
scanf("%d",&temp);

printf("\n");

sec += temp;

/* Calculate The Time */

while(1){ 
	printTime(sec);		// Print the current time
	sec++;			// simulate waiting for 1 sec
	sleep(1);  		// wait for 1 seconds
	}
return 0;
}

void printTime(int sec){

	printHours(sec);
	printf(":");
	printMins(sec);
	printf(":");
	printSeconds(sec);

	printf("\n");
}

void printHours(int sec){
	sec /= 3600;		 // calculate hours, store in sec
	sec %= 24; 		 //  if the num.of hours > 24, take mod of 24
	printf("%02d",sec);
}

void printMins(int sec){
	sec = (sec % 3600) / 60; // calculate mins, store in sec
	sec %= 60;		 // if the num. of min > 60, take mod of 60
	printf("%02d",sec);
}
void printSeconds(int sec){
	sec = (sec % 3600) % 60;
	sec %= 60;		// if the num. of seconds > 60, take mod of 60
	printf("%02d",sec);
}


