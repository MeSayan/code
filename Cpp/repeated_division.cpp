#include <stdio.h>
#include <cmath>


int main() {
	int T, N, Q, i;
	int D[1000000+1];
	unsigned long long int product_D = 1;
	unsigned long long int ans = 1;
	int X;
	
	scanf("%d ", &T);
	
	while( T-- ) {
		scanf("%d %d", &N, &Q);
		product_D = 1;
		
		for(i = 1; i <= N; i++) {
			scanf("%d",D+i);
			product_D *= D[i];
		}
		
		for( i = 1; i <= Q; i++) {
			scanf("%d",&X);	
			ans = (int)((X/product_D));
			printf("%llu ",ans);
			ans = 1;
		}
		printf("\n");
		
	}
	return 0;
}

		
		
		
		
			
			
