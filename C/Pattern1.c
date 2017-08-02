#include <stdio.h>
#include <math.h>
int i,j,k,l,c,no;
void pattern1()
{
	
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		printf("*");
		printf("\n");
	}
}

void pattern2()
{
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=i;j++)
		printf("*");
		printf("\n");
	}
}

void pattern3()
{
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4-i;j++)
		printf(" ");
		
		for(k=1;k<=i;k++)
		printf("*");
		printf("\n");
	}
}
void pattern4()
{
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=i;j++)
		printf("%d",j);
		printf("\n");
	}
}
void pattern5()
{
	c=1;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=i;j++)
		printf("%d",c++);
		printf("\n");
	}
}
void pattern6()
{    c=1;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=5;j++)
		{
			if(j==c||j==6-c)
			printf("1");
			else
			{
				printf("0");
			}

		}
			c++;
			if(c==4)
			c=1;
		printf("\n");
	}
}
void pattern7()
{
	for(i=1;i<=6;i++)
	{
		c=i<=4?4-i:i-4;
		
		for(j=1;j<=c;j++)
		printf(" ");
		
		for(k=1;k<=4-c;k++)
		printf("*");
		
		printf("\n");
	}
}
void pattern8()
{
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4-i;j++)
		printf(" ");
		
		for(k=1;k<=i;k++)
		printf("%d",k);
		
		for(l=i-1;l>=1;l--)
		printf("%d",l);
		
		printf("\n");
	}
}
void pattern9()
{
	for(i=1;i<=5;i++)
	{
	     no=(int)pow(11,i-1);
	     for(j=1;j<=5-i;j++)
	     printf(" ");
	     
	     while(no>0)
	     {
			 printf("%d ",no%10);
			 no=no/10;
		 }
		 printf("\n");
	 }
 }
 
 void pattern10()
 {
	 int i,j,k,c;
	 for(i=1;i<8;i++)
	{
		c=i<=4?i:8-i;
		for(j=1;j<=4-c;j++)
		printf(" ");
		
		for(k=1;k<=2*c-1;k++)
		{
			if(k%2==0)
			printf(" ");
			else
			printf("*");
		}
		printf("\n");
	}
}
		
int main()
{	
	puts("Welcome to Pattern Maker!!");
	printf("Enter a no from (1-10) and view a unique pattern\nEnter Choice: ");
	int choice;
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:pattern1();break;
		case 2:pattern2();break;
		case 3:pattern3();break;
		case 4:pattern4();break;
		case 5:pattern5();break;
		case 6:pattern6();break;
		case 7:pattern7();break;
		case 8:pattern8();break;
		case 9:pattern9();break;
		case 10:pattern10();break;
		default:puts("Invalid Input");break;
	}
	return 0;
	
}
