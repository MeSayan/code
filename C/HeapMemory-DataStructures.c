#include <stdio.h>
#include <stdlib.h>
// functions malloc() and free() are defined in header file stdlib.h so it must be included to access them
#include <string.h>

typedef struct island
{
	const char* name;
	char* opens;
	char* closes;
	struct island* next;
}island;

 island* create(char *name)
 {
	 island* i=malloc(sizeof(island));
	 //Malloc functions takes amount of memory to be allocated as inputs and returns general purpose pointer of type void* which must be explicitly cast


	i->name=strdup(name);
	i->opens="09.00";
	i->closes="17.00";
	i->next=NULL;
	return i;
}

	void display(island* start)
	{   
		island* i=start;
		island* next;
		
		for(;i!=NULL;i=next)
		{
			printf("%-8s%s\n","Name: ",i->name);
			printf("Opens:  %shrs\n",i->opens);
			printf("Closes: %shrs	\n",i->closes);
		
			next=i->next;
		}
		
	}
	void release(island* start)
	{	
		island* i;
		island* next;
		for(;i!=NULL;i=next)
		{
			free(i->name);
			free(i);
			next=i->next;
		}
	}
int main()
{
	char name[80];
	char input[80];
	char* res;
	char delim[]=":";
	fgets(name,80,stdin);
	name[strlen(name)-1]='\0';
	
	/*fgets() appends the newline characte '\0' if it finds it in stdin  to the destination buffer .Thus an extraline is always printed unnecessarily
	 * To avoid this either use gets()
	 * or explicitly set the last character of char buffer to null character
	 * Method 2 is prefereble because gets() causes memory leasks
	 * 
	 * */
	island * p_island0;
	island * start;
	island * i;
	p_island0=create(name);
	start=p_island0;
	i=start;
	
	while(1)
	{	res=NULL;
		
		fgets(input,80,stdin);
		input[strlen(input)-1]='\0';
		res=strtok(input,delim);
		if(strcmp(res,"Name")==0);
		{
		res=strtok(NULL,delim);
		//printf("%s\n",res);
		}
		
		//display(start);		
		if(strcmp(input,"display")==0)
		   display(start);
		  
	    
		else
		{
		p_island0=create(res);
		i->next=p_island0;
		i=p_island0;
		}
		
	}

    return 0;
}
