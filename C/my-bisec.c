#include <stdio.h>
#include <float.h>
#include <math.h>

float f(float x) {
		return x*x*x+2*x-2;
}


int main() {
	float a,b,c;
	
	printf("Enter interval [a,b] : ");
	scanf("%f %f",&a,&b);
	
	do{
		c = (a+b)/2;	
        if( f(c) *f(a) < 0)
        b = c;
        else if( f(c) *f(a) > 0)
        a = c;
        else
        break;
	
	}while( fabs(b-a) > 0.0000001 );
	
	printf("Result: %f",c);
	
	return 0;
}

