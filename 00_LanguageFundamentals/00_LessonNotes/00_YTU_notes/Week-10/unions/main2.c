#include<stdio.h>
#include<string.h>
#define TRUE 1
#define FALSE 0

struct VitalStat{

	char name[19], ssnum[11];
	unsigned int vs_day:5, vs_month:4, vs_year:11;
	unsigned  uscitizen:1;

	union{
		char nationality[20];
		char city_of_birth[20];
	}location;

}

int main(){

	struct VitalStat person;
	int day,month, year;

	scanf("%s %s", person.name, person.ssnum);

	scanf("%d %d %d", &day, &month, &year);

	person.vs_day = day;
	person.vs_month = month;
	person.vs_year = year;

	get_city_info(&person);

	writePersonInfo(person);


	return 0;
}

void writePersonInfo(struct VitalStat pvs){
	printf("%s %s", pvs.name, pvs.ssnum);

	printf("%s", pvs.location.nationality);		// bilgi aynı yerde yerleştiğinden nationality ise onu değilse diğerini yazdırır.
}

int is_yes(){
	char answer[64];
	while(1){
		scanf("%s", answer);
		switch(answer[0]){
			case 'y':
			case 'Y':
				return TRUE;
			case 'n':
			case 'N':
				return FALSE;
			default:
				printf("Please answer yes or no...\n");	
		}
	}
}

int double_check(char*s){
	printf("%s correct?(Y-N)", s);
	return is_yes();

}

void get_city_info( struct VitalStat* pvs){
	int answered = FALSE;

	printf("Are you a US citizen ?");
	pvs-> uscitizen = is_yes();
	
	while(!answered){
		if(!pvs->uscitizen){
			printf("Nationality");
			scanf("%s", pvs->location.nationality);
			answered = double_check(pvs->location.nationality);
		}else{
			printf("Enter the city of birth: ");
			scanf("%s", pvs->location.city_of_birth);
			answered = double_check(pvs->location.city_of_birth);
		}	
	}
}
