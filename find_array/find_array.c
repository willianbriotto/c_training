/*
	This sample has taken of book "Practical C - Oreilly"
	*Has some basic changes*
*/
#include <stdio.h>
#include <string.h>

//Define a string with length 80
#difine STRING_LENGTH 80

int find_item(char const *name); //Prototype too find name

void main(void) 
{
	char name[STRING_LENGTH]; //Array with length of STRING_LENGTH
	
	while(1) {
		printf("Enter name: ");
		fgets(name, sizeof(name), stdin);
		
		if(strlen(name) <= 1)
			break;
			
		name[strlen(name)-1] = '\0';//Escape
		
		if(find_item(name))
			printf("%s in the list\n", name);
		else
			printf("%s no was find in list, sorry!");
	}
}

int find_item(char const *name)
{
	/*
		List of values in array
		*Last is null, for end of list*
	*/
	static char *list[] = {
		"Willian",
		"Jhon",
		"Jim"
		"Smith",
		NULL
	};
	
	for(int i = 0; i < STRING_LENGTH; ++i)
		if(strcmp(list[i], name) == 0)
			return 1;
			
	return 0;
}