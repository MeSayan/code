#include <stdio.h>

typedef struct island// If we want to add struct pointers then the name of struct should be specified beforehand
{
	char* name;
	char* opens;
	char* closes;
	struct island* next;
}island;

void display(island* start)
{
	island* i=start;
	island* next;
	for(;i!=NULL;i=next)
	{
		printf("Island: %s\n",i->name);
		printf("Opens: %s hours\n",i->opens);
		printf("Closes %s hours\n",i->closes);
		next=i->next;
	}
}
	/*In order to access and print the islands we could have also used
	 * island i=*start;
	 * for(;i.next!=NULL;i=i.next)
	 * {
	 * 	printf("Island: %s\n",i.name);
		printf("Opens: %s hours\n",i.opens);
		printf("Closes %s hours\n",i.closes);
	 * 
		}
		* 

		* */

void xdisplay(island* start)
{
	island i=*start;
	for(;i.next!=NULL;i=*(i.next))
	{
	  	printf("Island: %s\n",i.name);
		printf("Opens: %s hours\n",i.opens);
		printf("Closes %s hours\n",i.closes); 
	}
}
int main()
{
	island amity={"Amity","09.00","17.00",NULL};
	island craggy={"Craggy","09.00","17.00",NULL};
	island isla_nublar={"Isla Nublar","09.00","17.00",NULL};
	island shutter={"Shutter Island","09.00","17.00",NULL};
	
	//Linking the island together 
	//Assuming amity is the starting point

	amity.next=&craggy;
	craggy.next=&isla_nublar;
	isla_nublar.next=&shutter;
	
	display(&amity);
	xdisplay(&amity);
    return 0;

}
