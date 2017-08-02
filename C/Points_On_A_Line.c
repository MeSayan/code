#include <stdio.h>

double slope(int x1,int y1,int x2,int y2)
{
	return (y2-y1)/(x2-x1);
}

int main()
{
	int x1,x2,x3,y1,y2,y3;
	puts("Enter three point as x and y one after the other");
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	
	if(slope(x1,y1,x2,y2)==slope(x1,y1,x3,y3))
	puts("The points lie on the same line.");
	else
	puts("The points dont lie on same line.");
}
