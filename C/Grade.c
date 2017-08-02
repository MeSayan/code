#include <stdio.h>

int main()
{
	int marks;
	char gr='t';
	
	puts("Enter Marks of the student: ");
	scanf("%d",&marks);
	
	gr=(marks-80)>=0?'A':(marks-70)>=0?'B':(marks-50)>=0?'C':(marks-30)>=0?'D':'F';
	printf("Your Grade is: %c",gr);
	
	return 0;
}
	

