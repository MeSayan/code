#include <stdio.h>
#include <string.h>

int main()
{
	puts("Enter a sentence ");
	char haystack[50];
	fgets(haystack,50,stdin);
	puts("Enter string to search");
	char needle[50];
	scanf("%s",needle);
	printf("Sentence Entered is: %s",haystack);
	printf("String to be searched is: %s \n",needle);
	
	if(strstr(haystack,needle))
	{ 	puts("String found");
		printf("At location %p",strstr(haystack,needle));
		
		//A small test
		char * p;
		p=strstr(haystack,needle); //a character pointer variable to store the address of first letter of needle in haystack
		puts("");
		//printf("%d \n",strlen(needle));
		for(int i=0;i<strlen(needle);i++)
		{	printf("%c",*(p+i));
		}
		puts("");
		/*Note:
		 * Difference between strlen() and sizeof() for character arrays.
		 * sizeof() gives the size of the array whether it is filled or not.
		 * strlen() gives the no of character present ignoring the terminating character "/0"  in the array
		*/
		}
	
	else
	puts("String not found");

}
