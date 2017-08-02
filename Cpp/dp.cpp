// Largest Common Subsequence and Largest common subword solved
// using Dynamic Programming
#include <iostream>
#include <string>
using namespace std;

void printMatrix(int M[][100], int m, int n ){
    int r, c;
    for( r = 0; r < m; r++) {
        for ( c = 0; c < n; c++) 
            cout << M[r][c] << "\t";
        cout << endl;
    }
}

int lcw(string u,string v) {
    int m = u.size();
    int n = v.size();
    int LCW[m+1][n+1];
    int r, c, max = 0;

    for(r = 0; r < m+1; r++)
        LCW[r][n] = 0;
    for(c = 0; c < n+1; c++)
        LCW[m][c] = 0;

    for( r = m-1; r >= 0; r--) {
        for (c = n-1; c >= 0; c--) {
            if(u[r] == v[c])
                LCW[r][c] = 1 + LCW[r+1][c+1];
            else
                LCW[r][c] = 0;

            if( LCW[r][c] > max )
                max = LCW[r][c];
        }
    }
    //printMatrix(LCW,m+1,n+1);
        return max;
}

int lcs(string u, string v) {
    int m = u.size();
    int n = v.size();
    int LCS[m+1][n+1];
    int r, c;

    //Setting Boundary Conditions of the table
    for(r = 0; r < m+1; r++)
        LCS[r][n] = 0;
    for(c = 0; c < n+1; c++)
        LCS[m][c] = 0;
    
    for(c = n-1; c >= 0; c--) {
        for( r = m-1; r >= 0; r--) {
            if(u[r] == v[c])
                LCS[r][c] = 1 + LCS[r+1][c+1];
            else
                LCS[r][c] = max(LCS[r+1][c],LCS[r][c+1]);
        }
    }

    //printMatrix(LCS,m+1,n+1);
    return LCS[0][0];
}



int main() {
    cout << "The LCW of secret and bisect is " << lcw("bisect","secret")
        << endl;
    cout << "The LCS of secret and bisect is " << lcs("bisect","secret")
        << endl;
    return 0;
}
