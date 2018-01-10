#include <stdio.h>

int main() {

    int T, N, i, min, min_index;
    int prefixSum[100000];
    int suffixSum[100000];
    int A[100000];

    scanf("%d", &T);
    
    while( T-- > 0) {

        scanf("%d ", &N);
        
        for(i = 0; i < N; i++ ){
            scanf("%d", A+i);
        }
        // Generate Prefix Sum
        prefixSum[0] = A[0];
        for( i = 1; i < N; i++)
            prefixSum[i] = prefixSum[i-1] + A[i];

        //Generate Suffix Sum
        suffixSum[N-1] = A[N-1];
        for( i = N-2; i >= 0; i--)
            suffixSum[i] = suffixSum[i+1] + A[i];

        // Scan through Prefix and Suffix Sums
        min = prefixSum[0] + suffixSum[0];
        

        for( i = 1; i < N; i++) {
            if( prefixSum[i] + suffixSum[i] < min) {
                min = prefixSum[i] + suffixSum[i];
                min_index = i;
            }
        }
        printf("%d\n",min_index+1);
    }
    return 0;
}
