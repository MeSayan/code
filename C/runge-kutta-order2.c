#include <stdio.h>

float f(float x,float y) {
		return x - y;
}

int main() {
	
	float x0,y0,h,x,k1,k2;
	int i;
	
	printf("Enter x0 y0 x and h: ");
	scanf("%f %f %f %f",&x0,&y0,&x,&h); 

    int n = (x-x0)/h;
    
    for ( i = 0;i <= n;i++) {
		k1 = h*f(x0,y0);
		k2 = h*f(x0+h,y0+k1);
		y0 += (k1+k2)/2;
		x0 += h;
		
	}
	
	printf("Result: %f",y0);
	return 0;
}
