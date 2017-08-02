#include <stdio.h>
#include <string.h>

int qtoDecimal(int Q) {
    int result = 0;
    while(Q>0){
        result = result*4 + Q%10;
        Q = Q/10;
    }
    return result;
}


int main() {
    char s[100];
    int T,Q,N,i,D;

    scanf("%d",&T);
    for(i=0;i<T;i++) {
        scanf("%d",&N);
        scanf("%d",&Q);
        D = qtoDecimal(Q);
        printf("%d\n",D);
    }
    return 0;
}
        
