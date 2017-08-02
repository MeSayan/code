#include <stdio.h>


int fastRead() {
 register int c = getchar_unlocked();
 int x = 0;
 int neg = 0;
 for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

 if(c=='-') {
  neg = 1;
  c = getchar_unlocked();
 }

 for(; c>47 && c<58 ; c = getchar_unlocked()) {
  x = (x<<1) + (x<<3) + c - 48;
 }

 if(neg)
  x = -x;
 return x;
}




int main() {
    int T, p, q, r, max, i, j, k, l, o;
    long long sum;
    max = l = o = sum = 0;

    // l is the length of array c
    // o is the length of array d

    int a[100000];
    int b[100000];
    int c[100000];
    int d[100000]; // stores modified a

    T = fastRead();
    while( T-- > 0 ) {
        
        p = fastRead();
        q = fastRead();
        r = fastRead();

        for(i = 0; i < p; i++) 
            a[i] = fastRead();

        for(i = 0; i < q; i++) {
            b[i] = fastRead();
            if( b[i] > max ) 
                max = b[i];
        }
     
        for(i = 0; i < r; i++ ) {
            j = fastRead();
            if( j <= max )
                c[l++] = j;
        }

        // form array d
        for(i = 0; i < p; i++) {
            if( a[i] <= max)
                d[o++] = a[i];
        }

        // computing sum 
        for( i = 0; i< o; i++) {
            for( j = 0; j < q; j++) {
                for( k = 0; k<l; k++) {
                    if( d[i] <= b[j] && b[j] >= c[k] ){
                        sum += (d[i] + b[j]) * (b[j] + c[k]);
                    }   
                }
            }
        }
        printf("%lld\n",sum % 10000000007);
    }
    return 0;
}


