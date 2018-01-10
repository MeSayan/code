#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
int main()  {
    int N,i,j,max = 0;

    scanf("%d ",&N);
    char X[N];
    char Y[N];
    vector< pair<int,int> > maxlist[N]; 

    for( i = 0; i < N; i++) { 
        scanf("%c",X+i);
        // Reverse String
        Y[N-1-i] = X[i];
    }

    int LCW[N][N];

    

    // Fill up the first row
    for( i = 0; i < N; i++) {
        LCW[0][i] = 0;
        LCW[i][0] = 0;
        // First Row
        if( Y[i] == X[0] ) 
            LCW[0][i] = 1;
        //First Column
        if( X[i] == Y[0]) 
            LCW[i][0] = 1;
    }

    for( i = 1; i < N; i++) {
        for( j = 1; j < N; j++) {
            
          if( X[i] == Y[j] )
                LCW[i][j] = 1 + LCW[i-1][j-1];
            else
                LCW[i][j] = 0;

            // Keep track of max
            if ( LCW[i][j] >= max ) { 
                max = LCW[i][j];
                maxlist[max].push_back(make_pair(i,j));
            }
        }
    }

    for( i = 0; i < N; i++) {
        for( j = 0; j < N; j++) {
            printf("%d \t",LCW[i][j]);
        }
        printf("\n");
    }

    for( vector< pair<int,int> >::iterator k = maxlist[max].begin(); k != maxlist[max].end(); k++) {
        printf(" I = %d and J = %d \n", k->first,k->second);
    }

    return 0;
}



