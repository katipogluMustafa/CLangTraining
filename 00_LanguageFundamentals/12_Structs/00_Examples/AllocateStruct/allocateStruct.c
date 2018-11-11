#include<stdio.h>	
#include<stdlib.h>
#include<string.h>

typedef struct _person{
	char* firstName;
	char* lastName;
	char* title;
	unsigned int age;
} Person;

int main(){
	
	//

	Person* ptrToPerson;
	ptrToPerson = (Person*) malloc( sizeof(Person) );

	ptrToPerson->firstName = (char*)malloc( ( strlen( "Mustafa" ) + 1 ) * sizeof(char)  );
	strcpy(ptrToPerson->firstName, "Mustafa");

	ptrToPerson->lastName = (char*)malloc( ( strlen( "Katipoglu" ) + 1 ) * sizeof(char) );
	strcpy(ptrToPerson->lastName,"Katipoglu");
	
	ptrToPerson->title = (char*)malloc( ( strlen("student") + 1 ) * sizeof(char) );
	strcpy(ptrToPerson->title,"student" );

	ptrToPerson->age = 20;

	printf("\n%s\t%s\t%s\t%d\n", ptrToPerson->firstName, ptrToPerson->lastName, ptrToPerson->title, ptrToPerson->age);
	
	//

	Person* ptrToAnotherPerson;
	ptrToAnotherPerson = (Person*) malloc( sizeof(Person) );

	(*ptrToAnotherPerson).firstName = (char*)malloc( ( strlen("mert") + 1 ) * sizeof(char) );
	(*ptrToAnotherPerson).firstName = "Mert";

	(*ptrToAnotherPerson).lastName = (char*)malloc( ( strlen("oz") + 1 ) * sizeof(char) );
	(*ptrToAnotherPerson).lastName = "Oz";

	(*ptrToAnotherPerson).title = (char*)malloc( ( strlen("student") + 1 ) * sizeof(char) );
	(*ptrToAnotherPerson).title = "Student";

	(*ptrToAnotherPerson).age = 20;


	printf("\n%s\t%s\t%s\t%d\n", (*ptrToAnotherPerson).firstName, (*ptrToAnotherPerson).lastName, (*ptrToAnotherPerson).title, (*ptrToAnotherPerson).age);
	
	return 0;
}