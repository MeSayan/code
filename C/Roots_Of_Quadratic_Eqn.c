#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c,determinant;
	char ch='f';
	int i=1;
	while(i>=0)
	{
		
		printf("Enter the coefficient of x^2:");
		scanf("%lf",&a);
		printf("Enter the coefficient of x:");
		scanf("%lf",&b);
		printf("Enter the constant terms:");
		scanf("%lf",&c);
		printf("The entered equation is : %lfx*x+%lfx+%lf \n",a,b,c);
		printf("Submit(1/0)? \n");
		scanf("%d",&i);
		if(i==1)
		i=-1;
		
	}
	
	determinant= (b*b-4*a*c);
	//printf("The determinant is %lf",determinant);
	
	
	
	if(determinant>0)
	{
		printf("First Root: %lf\n",(-b+sqrt((determinant))/(2*a)));
		printf("Second Root: %lf\n",(-b-sqrt((determinant))/(2*a))); 
	}
	else if(determinant==0)
	{
		printf("Equal roots are: %lf\n",-b/(2*a));
	}	
	else 
	{
		printf("The equation has imaginary roots\n");
		float real, imag;
		real=-b/(2*a);
		imag=sqrt(-determinant)/(2*a);
		printf("One root is: %lf+%lfi\n",real,imag);
		printf("Another root is: %lf-%lfi",real,imag);
	}	
	return 1 ;
}
