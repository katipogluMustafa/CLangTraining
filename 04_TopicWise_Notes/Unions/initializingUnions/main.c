#include<stdio.h>

union myUnion {
	struct{
		unsigned int Day:5;
		unsigned int Month:4;
		unsigned int Year:12;	// Year between 0 - 4096
	}Date;
	char nation[21];
};

int main(){
	int choice;
	union myUnion in;
	unsigned int day, month, year; 

	printf("Date or Nation?[0-1]");
	scanf("%d", &choice);

	if(choice){ // Nation
		printf("Nation: ");
		scanf("%s", in.nation);
	}else{		// Date
		printf("Day -- Mount -- Year");
		scanf("%u", &day);
		scanf("%u", &month);
		scanf("%u", &year);

		in.Date.Day = day;
		in.Date.Month = month;
		in.Date.Year = year;
	}

	printf("%s\n\n", in.nation);
	printf("%u %u %u", in.Date.Day, in.Date.Month, in.Date.Year);


return 0;
}
