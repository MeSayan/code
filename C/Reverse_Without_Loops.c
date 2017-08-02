#include <stdio.h>

int main()
{
	int no,rev;
	puts("Enter no");
	scanf("%d",&no);
	rev=100*(no%10)+10*((no/10)%10)+no/100;
	printf("Reversed No is: %d",rev);
	return 0;
}
