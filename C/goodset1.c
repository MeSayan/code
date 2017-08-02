#include <stdio.h>

int main() {
    int T, n, i;

    scanf("%d", &T);
    while( T-- > 0) {
        scanf("%d",&n);
        for(i = 1; i <=n; i++)
            printf("%d ",500-i+1);
        printf("\n");
    }
    return 0;
}
