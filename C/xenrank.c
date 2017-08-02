#include <stdio.h>

int main() {
    int i, u, v, T;
    long long sum;
    scanf("%d", &T);

    while( T-- > 0) {
    
        scanf("%d %d",&u,&v);
        sum = 0;
        
        sum = (long long) (u+v)*(u+v+1)/2;

        sum = sum + (u+v+1) - v;
        printf("%lld \n",sum);
    }
    return 0;
}
