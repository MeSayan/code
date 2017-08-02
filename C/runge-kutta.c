#include <stdio.h>

float f(float x,float y) {
	return x*x + y*y ;
}

int main() {
	
	float x0,y0,x,h,y;
	float k1,k2,k3,k4,k5;
	printf("Enter x0 y0 x and h: ");
	scanf("%f %f %f %f",&x0,&y0,&x,&h);
	
	int n = (x-x0)/h;
	int i;
	x = x0;
	y = y0;
	for( i = 0;i <= n;i++) {
		k1 = h*f(x0,y0);
		k2 = h*f(x0+h/2,y0+k1/2);
		k3 = h*f(x0+h/2,y0+k2/2);
		k4 = h*f(x0+h,y0+k3);
		k5 = (k1+2*k2+2*k3+k4)/6;
		y += k5;
		x += h;
	}
	
	printf("Result: %f",y);
	return 0;
}
