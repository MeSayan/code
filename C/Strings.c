#include <stdio.h>
#include <string.h>

void printMessage( char msg[])
{
	puts(msg);
	printf(sizeof(msg));
}

int main()
{
	char a[12],b[12],c[12];
	/*
	puts("Enter first name");
	scanf("%11s",a);
	
	puts("Enter last name");
	scanf("%11s",b);
	
	strcat(c,a);
	strcat(c,b);
	
	puts(c);
	
	printf("%d",strlen(c));
	printf("%d",sizeof(c));
	* 
	* */
	printMessage("Hello World");
}


/*String Functions
 * strcat(); conctenates string s2 to string s1
 * strcpy(s1,s2): copies string s2 to string s1
 * strlen(s2): returns the length of string s2 excluding the /0 character
 * */

/*Arrays and pointers
 * Arrays are a special class of pointers
 * Applying sizeof() operator on arrays gives us the size of array ie no of elements present in the array
 * Applying sizeof() on a pointer gives either 4 or 8 bytes depending on the computer system
 * pointer cannot modify string literals but arras can do so
 * char * point="Hlll";
 * *(point+2)=z is wrong
 * 
 * also when arrays are passed to functions they are passed as normal pointers
 * also syntactically speaking
 * *(p+i)=*(i+p)=p[i]=i[p];
 * 
 * */
