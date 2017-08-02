#include <stdio.h>
typedef struct 
{
	const char* name;
	const char* species;
	int age;
}turtle;

void happybirthday(turtle* t)
{
	(*t).age++;
	/*Structures are passed by pass by value that is they are cloned
	 * To ensure that changes made by a function are permanent or reflected use struct pointers instead
	 * Instead of using (*t).age we could have used t->age
	 * Thus the "->" operator is used to refer to data members of structures that are pointed to by the pointer variable
	 * In this case -> points to the data member  age
	 * 
	 * */
	printf("Happy Birthday %s! You are now %d years old!\n",t->name,(*t).age);
}

int main()
{   
	turtle myrtle={"Myrtle","Leather back sea turtle",99};
	happybirthday(&myrtle);
	printf("%s's age is now %d\n",myrtle.name,myrtle.age);
	
	return 0;
}
