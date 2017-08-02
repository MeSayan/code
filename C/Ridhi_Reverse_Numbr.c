#include <stdio.h>
#include <math.h>

int main()
{
	int x,m=0,n=0;
	int count=0;

	scanf("%d",&n);
	
	m=n;
	while(m>0)
	{	m=m/10;
		count++;
	}
	
	x=(int)pow(10,count-1);
	
	m=n%x-n%10+n/x+(n%10)*x;
	/* Shorthand
	 *  To switch first and last digits of a 4 digit number use
	 * m=n%1000-n%10+n/1000+n%10*1000
	 * Probably used by riddhi
	 * *
	 * */
	 

	printf("%d",m);
}
