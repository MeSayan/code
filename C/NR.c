#include <stdio.h>
#include <math.h>

float f(float x) {
		return x*x*x+2*x-2;
}

float g(float x) {
	return 3*x*x+2;
}

int main() {
	float x0,x1,h;
	
	printf("Enter first approximation");
	scanf("%f",&x0);
	
	do{
		x1 = x0 - f(x0)/g(x0);
		h = x1>x0?x1-x0:x0-x1;
		x0 = x1;	
	
	}while( h > 0.000001);
	
	printf("Result: %f",x1);
	
	return 0;
}


