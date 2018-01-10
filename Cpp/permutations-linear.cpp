#include <stdio.h>

using namespace std;

int main() {
    int T, n;
    int i, j, t;
    int A[100001];



    scanf("%d", &T);
    while( T-- > 0) {
        scanf("%d", &n);
        for(i = 1; i <= n; i+=2) {
            if ( i == n) {
                // Only if i is odd
                //Swap A[n-1] and A[n]
                A[n] = A[n-1];
                A[n-1] = n;
            } 
            else {
                A[i] = i+1;
                A[i+1] = i;
            }
        }
        
       for ( i = 1; i <= n; i++) {
           printf("%d ",A[i]);
       }
       printf("\n");
    }
    return 0;
}
        
        
