#include <stdio.h>
int main()
{
		float PI=3.14;
		float rad,circum,area ;
		
		printf("Enter radius of the circle:");
		scanf("%f",&rad);
		
		circum=2*PI*rad;
		area=PI*rad*rad;
		
		printf("The circumference of the circle is: %f \n",circum);
		printf("The area of the circle is: %f \n",area);
		
		return(0);
	
}