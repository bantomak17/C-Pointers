#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

typedef struct _person { 
	char* firstName;
	char* lastName; 
	char* title; 
	unsigned int age;
} Person;

void initializePerson(Person *person, const char* fn, const char* ln, const char* title, unsigned int age) {
	person->firstName = (char*) malloc(strlen(fn) + 1); 
	strcpy(person->firstName, fn);
	person->lastName = (char*) malloc(strlen(ln) + 1); 
	strcpy(person->lastName, ln);
	person->title = (char*) malloc(strlen(title) + 1); 
	strcpy(person->title, title);
	person->age = age;
}

void displayPerson(Person *person)
{
	printf("[%s] [%s] [%s] [%d]\n", person->firstName, person->lastName, person->title, person->age);
}

int main()
{
 	LinkedList* list = getLinkedListInstance();
	Person *person = (Person*) malloc(sizeof(Person)); 
	initializePerson(person, "Peter", "Underwood", "Manager", 36); 
	addNode(list, person);
	person = (Person*) malloc(sizeof(Person)); 
	initializePerson(person, "Sue", "Stevenson", "Developer", 28); 
	addNode(list, person);
     
	person = removeNode(list);
    displayPerson(person);
    
	person = removeNode(list);
    displayPerson(person);
    
	removeLinkedListInstance(list);
}
