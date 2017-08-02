/* According to Gregorian Calender, it was Monday on the date 01/01/01 .If any year is 
 * input through the keyboard write a program to find out the keyboard , write a program to to find out
 * what is the day on 1st January of this year
 * 
 **/
#include <stdio.h>

void whichDay(int count)
{
	switch(count)
	{
		case 1: puts("Yawn! its Sunday");break;
		case 2: puts("Alas! It's Monday");break;
		case 3: puts("A lot of days to go-It's Tuesday");break;
		case 4: puts("Exactly the middle day of the week-It's Wednesday");break;
		case 5: puts("It's Thursday");break;
		case 6: puts("Thank God! It's Friday!");break;
		case 7: puts("Hurray! It's Saturday");break;
		default:puts("Which planet do live in? Deffinately not Earth");break;
	}

}

int isLeap(int year)
{
	if(year%4==0)
	return 1;
	return 0;
}

int main()
{
	int year,count;
	count=1;
	puts("Welcome to Which_Day. This is a c program to print the day of the week of 1st January of the an entered year.");

	for(int j=1;j<10;j++)
	{	
	
		puts("Enter the Year in YY format:");
		scanf("%d",&year);
		if(year<=0)
		{
			puts("Year cannot be negative or zero.Input again in YY Format");
			j--;
			continue;
		}
	
		for(int i=1;i<=year;i++)
		{
			if(count>7)
			count-=7;
		
			if(isLeap(i)==1)
			count+=2;
		
			else count +=1;
			//printf("%d + %d\n",i,count);
		}
		
	printf("Wait.. we are processing the input \n ");
	whichDay(count>0?count-7:count);//Final checking to see that count doesnot exceed 7
	}

	return 0;
}	
		
