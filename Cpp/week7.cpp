/* Week 7 programming assignment for NPTEL course DAA.
Date: 5/9/17
Author: Sayan
Comments: Uses a greedy algorithm to find jobs which have earlier finish times
*/

#include <stdio.h>
#include <algorithm>

#define S(x) J[x].second
#define F(x) J[x].first


int main() {

    int N, s, d, c = 0, i, j;
    scanf("%d", &N);
    std::pair<int,int> J[N];

    for( i = 0; i < N; i++) {
        scanf("%d %d", &s, &d);
        J[i] = std::make_pair(s+d,s); // Pair( Finish, Start)
    }

    std::sort(J, J+N);

    for( i = 0; i < N; i++) {
        printf("%d %d\n", J[i].first, J[i].second);
    }
    printf("\n");

    for( i = 0; i < N; ) {
        c++; // Increase counter by 1
        for( j = i+1; j < N; j++) {
            if( S(j) > F(i) )
                break;
        }
        i = j;
    }

    printf("%d\n", c);
    return 0;
}
