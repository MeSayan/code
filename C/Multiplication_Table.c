#include <stdio.h>

int main()
{
	int a, range;
	
	puts("Enter an  integer to find multiplication table:");
	scanf("%d",&a);
	puts("Enter the range of multiplication  table:");
	scanf("%d",&range);
	printf("The multiplication table of %d is\n",a);
	
	for(int i=1;i<=range;i++)
	{
			printf("%d*%d = %d \n",a,i,(a*i));
	}
	return 0;
}
