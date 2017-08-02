#include <stdio.h>
#include <math.h>
void series1(int n)
{	int sum,i;
	sum=0;
	for( i=0;i<n;i++)
	{
		if(i==n-1)
		printf("(1+%d)",i);
		else
		printf("(1+%d)+",i);
		sum+=1+i;
	}
	printf("\nSum of above series is %d\n",sum);
}
void series2(int n)
{
	int sum=0,i,j;
	
	for(i=1;i<=n;i++)
	{	
		printf("(");
		for(j=1;j<=i;j++)
		{	sum+=j;
			printf("%d",j);
			if(j!=i)
			printf("+");
		}
		printf(")");
	if(i!=n)
	printf("+");
	}
	printf("\nSum Of Above Series is %d\n",sum);
}
void series3(int n)
{
	int fact=1,i,j;
	int sum=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		fact=fact*j;
		printf("%d!",i);
		i!=n?printf("+"):printf(".");
		sum+=fact;
		fact=1;
	}
		printf("\nSum of the above series is %d\n",sum);
}

void series4(int n)
{
	int i;
	double sum=0.0;
	for(i=1;i<=n;i++)
	{
		printf("1/%d",i);
		i!=n?printf("+"):printf(".");
		sum+=1.0/i;
	}
	printf("\nSum of the above series is %f\n",sum);
}
void series5(int n)
{
	double sum=0;
	int i;
	for(i=0;i<=n;i++)
	{
		printf("1/%d",(int)pow(2,i));
		i!=n?printf("+"):printf(".");
		sum+=1.0/pow(2,i);
	}
	printf("\nSum of the above series is %f",sum);
}
void series6(int n)
{ 	double sum=0.0;
	int i;
	for(i=1;i<=n;i++)
	{
		if(i%2!=0)
		{
			printf("(1/%d)",i);
			sum+=1.0/i;
		}
		else
		{
			printf("(-1/%d)",i);
			sum-=1.0/i;
		}
		i!=n?printf("+"):printf(".\n");
	}
	printf("Sum Of The Above series is %f\n",sum);
}	
void series7(int n)
{
	int fact=1,i,j;
	double sum=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		fact=fact*j;
		printf("1/%d!",i);
		i!=n?printf("+"):printf(".");
		sum+=1.0/fact;
		fact=1;
	}
		printf("\nSum of the above series is %f\n",sum);
}
				
int main()
{	int n,choice;
	puts("Welcome to Seriezzz Mania!!.");
	puts("Enter Value of n");
	scanf("%d",&n);
	puts("Enter a value (1-7) and print corresponding sequence");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: series1(n);break;
		case 2: series2(n);break;
		case 3: series3(n);break;
		case 4: series4(n);break;
		case 5: series5(n);break;
		case 6: series6(n);break;
		case 7: series7(n);break;
		default:puts("Invalid Input");break;
				
	}
	return 0;
}
