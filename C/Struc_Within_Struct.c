//This program demonstrates C principle of building one or more structures in another structure
#include <stdio.h>


struct meal
{
	const char* ingredients;
	float weight;
	
};
struct exercise 
{
	const char* description;
	float duration;
};

struct preferences
{
	struct meal food;
	struct exercise exercises;
};
struct fish
{
	const char* name;
	const char* species;
	int teeth;
	int age;
	struct preferences care;
	
};


/*How to initialise a struc which contains another structure inside it?
  Use: stuct fish snappy ={"Snappy","Piranha",69,4,{"Meat",7.5}}
  * 
  * */

void label(struct fish f)
{
	printf("Name: %s\n",f.name);
	printf("Species: %s\n",f.species);
	printf("Food Ingredients: %s\n",f.care.food.ingredients);
	printf("Food Weight: %.3f lbs\n",f.care.food.weight);
	printf("Exercise Description: %s\n",f.care.exercises.description);
	printf("Exercise duration: %.3f\n",f.care.exercises.duration);
}

int main()
{
	struct fish snappy={"Snappy","Piranha",69,4,{{"Meat",0.3},{"Swim in the jacuzzi",7.5}}};//Take note of how to declare structs which contain other structs in them
	label(snappy);
	return 0;
}

