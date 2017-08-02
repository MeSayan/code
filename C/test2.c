#include <stdio.h>


int main() {

    int ch, T, x;
    
    scanf("%d",&T);

    
    while(T-- > 0 ) {
        x = 0;       
        for(ch = getchar_unlocked(); ch < '0' || ch > '9'; ch = getchar_unlocked());
        
        for(;ch >= '0' && ch <= '9';ch = getchar_unlocked()) {
        x = (x << 3) + (x << 1) + ch - '0';
        }
    }

    return 0;
}
