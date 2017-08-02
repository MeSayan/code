#include <stdio.h>
int main()
{
	int i,no,pro;
	
	puts("Enter no:");
	scanf("%d",&no);
	
	for(i=1;i<=50;i++)
	{
		pro=no*i;
		printf("%d*%d=%d\n",no,i,pro);
	}
	return 0;
}
