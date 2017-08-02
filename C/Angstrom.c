#include <stdio.h>

int main()
{
	int i,j,range,a,r;
	puts("Enter Range");
	scanf("%d",&range);
	
    for(i=1;i<=range;i++)
    {
		j=i;
		a=0;
		while(j>0)
		{
			r=j%10;
			a=a+r*r*r;
			j=j/10;
		}

		if(a==i)
		printf("%d,",a);
		
	}
	return 0;
}
