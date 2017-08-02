#include <stdio.h>
#include <math.h>

int main() {
	
	int n,i,j,k,p;
	float t,sum;
	
	printf("Enter no of equations: \n");
	scanf("%d",&n);
	
	float A[n][n+1];
	float X[n];
	
	for(i = 0;i < n;i++) {
		printf("Enter row %d :\n",i+1);
		for(j = 0; j<n+1; j++)
		scanf("%f",&A[i][j]);
		
	}
 
	for(i = 0; i<n;i++) {	
		
		// Pivoting
		
		// Searching for p row:
		for(j = i+1;j < n;j++) {
			if ( fabs(A[j][i] - A[i][i]) > 0 )
			p = j;
		}
		
		// Swapping i and p rows:
		for( j=0;j<n+1;j++) {
			t = A[i][j];
			A[i][j] = A[p][j];
			A[p][j] = t;
		}
		
		
		for(j = i+1;j<n;j++){
				
			float x = A[j][i]/A[i][i];
			for(k = 0;k<n+1;k++){
				A[j][k] = A[j][k] - A[i][k]*x;
			}
		}
	}
	printf("Triangular Matrix: \n");	
	for(i = 0;i < n;i++) {
		for(j = 0;j < n;j++)
		printf("%f \t",A[i][j]);
        printf("| %f",A[i][j]);
		printf("\n");
	}
	
	
	for( i = n-1; i>=0;i--){
		sum = 0;
		for(j = i+1;j<n;j++){
			sum += A[i][j]*X[j];
		}
		X[i] = (A[i][j] - sum )/A[i][i];
	}
	
	printf("Results: \n");
	for(i=0;i<n;i++) 
	printf("x[%d] = %f\n",i,X[i]);
	return 0;
}
