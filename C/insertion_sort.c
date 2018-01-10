#include <stdio.h>

void printArray(int A[],int n) {
	int i;
	for( i = 0; i < n; i++)
		printf("%d ",A[i]);
	printf("\n");
}

void insertion_sort(int A[],int low, int high) {
	
	printArray(A,8);
	
	if( high - low  <= 0 ) {
		return;
	}
	
	insertion_sort(A,0,high-1);
	int last = A[high];
	int j = high-1;
	
	while( j>=0 && A[j] > last) {
		A[j+1] = A[j];
		j--;
	}
	A[j+1] = last;
	
}



int main() {
	int A[] = {1,2,5,2,16,626,263,6};
	printArray(A,sizeof(A)/sizeof(A[0]));
	insertion_sort(A,0,sizeof(A)/sizeof(A[0])-1);
	printArray(A,8);
	return 0;
}

		
