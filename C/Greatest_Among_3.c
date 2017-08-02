#include <stdio.h>

int main()
{
		int a,b,c;
		int max=0;
		printf("Enter three values one after the another:");
		scanf("%d %d %d",&a,&b,&c);
		
		max=a>b?a>c?a:c:b>c?b:c;
		printf("The maxium number entered is:%d",max);
		
		return 1;
}
