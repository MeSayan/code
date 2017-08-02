#include <stdio.h>

int main() {
    int i, j , a, b, rank, u, v, T, max;
    rank = 1;
    scanf("%d", &T);

    while( T-- > 0) {
    
        scanf("%d %d",&u,&v);
        rank = 1;
        
        for(i = 1; i <= u+v+1 ; i++) {
            for( j = 1; j <= i; j++) {
                if( j == 1) {
                    a = i-1;
                    b = 0;
                }
                else {
                    a--;
                    b++;
                }
                if( a == v && b == u) {
                    max = rank;
                    break;
                }
                
                rank++;
            }   
        }
        printf("%d\n",max);
    }

    return 0;
}
