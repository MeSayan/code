#include <stdio.h>


	struct fish
	{
		const char* name;
		const char* species;
		int teeth;
		int age;
	};
	
	void catalog(struct fish f)
	{
		printf("%s is a %s with %d teeth. He is %d\n",f.name,f.species,f.teeth,f.age);
		
		
		
	}
	void label (struct fish f)
	{
	     printf("Name:%s\n",f.name);
	     printf("Species:%s\n",f.species);
	     printf("%d years old, %i teeth\n",f.age,f.teeth);
	     
	
	
	}
		
		int main()
		{
			struct fish snappy={"Snappy","Piranha",69,4};
			catalog(snappy);
			label(snappy);
			return 0;
		}
