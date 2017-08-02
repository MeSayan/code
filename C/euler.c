#include <stdio.h>

float f(float x,float y) {
return x-y;
}

int main() {
	int i,n;
	float x0,y0,x,y,h;
	printf("Enter x0 y0 x and h: ");
	scanf("%f %f %f %f",&x0,&y0,&x,&h);
	
	n = (x - x0)/h;
	x = x0;
	y = y0;
	for( i = 0;i <=n;i++){
		y += h*f(x,y);
		x = x+h;
	}
	printf("The Result is: %f",y);
	return 1;
}
