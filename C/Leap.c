#include <stdio.h>
int  main()
{
	 float basic,gross;
	 puts("Enter basic salary");
	 scanf("%f",&basic);
	 if(basic>=1&&basic<=4000)  gross=basic*(1+0.15+0.5);
	 else if(basic>=4001 && basic<=8000) gross=basic*(1+0.3+0.6);
	 else if(basic>=8001 && basic<=12000) gross=basic*(1+0.45+0.70);
	 else gross=basic*(1+0.5+0.85);
	 
	 printf("The gross salary is:%f",gross);
	 return 0;
 }
