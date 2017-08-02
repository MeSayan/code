#include <stdio.h>

float f(float x) {
	return x + 1/x;
}

int main() {
	
	float a,b,h,x,sum;
	int n,i;
	
	printf("Enter Interval [a,b]: ");
	scanf("%f %f",&a,&b);
	printf("Enter no of subinterals:");
	scanf("%d",&n);
	
	h = (b-a)/n;
	
	for(i = 0;i<=n;i++) {
		x = a+i*h;
		if( i!=0 && i!=n) {
			if( i%2 == 0)
			sum += 2*f(x);
			else
			sum += 4*f(x);
		}
		else
		sum += f(x);
	}
	sum = sum*h/3;
	
	printf("Resul: %f",sum);
	return 0;
}
