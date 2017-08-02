#include <stdio.h>
 
int main()
{
	int a,b;
	
	scanf("%d %d",&a,&b);
	
	printf("\n Before swapping we have a=%d and b=%d",a,b);

	 a=a+b;
	b=a-b;
	a=a-b;

	printf("\n After swapping we have a=%d and b=%d",a,b);
}
