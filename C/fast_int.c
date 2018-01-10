#include <stdio.h>

void scan_int(int *x) {
	register int s = 0;
	int neg = 0;
	char c;

	for( c = getchar(); (c < 48 && c > 57); c = getchar() ) {
		if( c == '-' ) {
			neg = 1;
			c = getchar();
			break;
		}
	}

	for(; c >= 48 && c <= 57; c = getchar() ) {
		s += (s<<1) + (s<<3) + (c - 48);
	}

	if(neg) {
		s = -s;
	}

	*x = s;
}

int main3() {
	int a;
	scan_int(&a);
	printf("%d \n",a);
	scan_int(&a);
	printf("%d \n",a);
	return 0;
}

