#include <stdio.h>
#include <string.h>

int main()
{
	char sent[4096];
	//no=n=0;
	int i=8;
	while(i>0)
	{	
		//fgets(sent,100,stdin);
		fgets(sent,100,stdin);
		//Removing trailing newline character from input
		
		if(sent[strlen(sent)-1]=='\n')
			sent[strlen(sent)-1]='\0';
		
		if(!strcmp(sent,"stop"))
		{	
			break;
		}
		/*
		 * strcmp() compares to string . Returns 1 if the two strings are equal
		 * 
		 * */	
		else
		printf("%s\n",sent);
	}
}

