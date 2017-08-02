#include <stdio.h>
#include <stdlib.h>

int main()
{
	int weight=63;
	
	/*
	 * Nos after % sign indicate the field-width ie the no of columns the display area for the variable spans.
	 * For instance if by virtue of its size a variavble requires 6 columns then specifying %10 causes the variable to be printed with extra padding.
	 * cd A value of - before the no indicates  right adjustment i.e the extra spaces added (if any) are added to right as paddin
	 * 
	 * */ 
	printf("weight is %d kg \n",weight);
	printf("weight is %1d kg \n",weight);//If field width is less than the nole of columns requires then it is ignored.
	printf("weight is %2d kg \n",weight);
	printf("weight is %4d kf \n",weight);
	printf("weight is %6d kg \n",weight);
	printf("weight is %-6d kg \n ",weight);
	
	char firstname1[]="Sandy";
	char lastname1[]="Malya";
	char firstname2[]="Ajay Kumar";
	char lastname2[]="Gurubaxani";
	
	printf("%20s %20s \n",firstname1,lastname1);
	printf("%20s %20s \n",firstname2,lastname2);
	
	/*Other specifiers
	 * the '.' specifier is used to separate the precission field from field width.
	 * Precission field is simply the no of digits after decimal point to be printed.
	 * */
	 printf("%10.1f %10.1f %10.1f %10.6f",5.0,13.567,133.57966,67.67);
	/* Notes:
	 * if the variable contains more decimal places than specified in the format then the variable is rounded.
	 * (Check output of variable 13.567 which is rounded off to 13.6 coz the format specifies one decimal places.
	 * Now if the  literal or variable has fewer decimal places than that specified in the format then extra zeroes are added to increase decimal places.
	 * */
 
 }
	 
	 
	

