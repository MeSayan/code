#include <stdio.h>
#include <math.h>


int isPrime_al(int n) {
    if( n == 2 || n == 1)
        return 1;

    float exp = log(n) / log(2); // compute log base 2
    if (exp - floor(exp) != 0)
        return 1;
    else
        return 0;
}
int isPrime(int n)
{
    int i;
    // Corner cases
    if (n <= 1)  return 0;
    if (n <= 3)  return 1;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return 0;
 
    for ( i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return 0;
 
    return 1;
}

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

    int N, Q, i, j, k, sum, number, exponent;
    int l, r, x, y, b_len;

    N = fastRead();

    int a[N+1];
    int b[1000001];

    for( i = 1; i <= N; i++) {
        a[i] = fastRead();
    }

    Q = fastRead();

    for( i = 1; i <= Q; i++) {
        l = fastRead();
        r = fastRead();
        x = fastRead();
        y = fastRead();
        sum = 0;
        b_len = 1;
                    

        for( j = x; j <= y; j++) {
            if( isPrime(j) )
                b[b_len++] = j;
        }

        for( j = 1; j < b_len; j++) {
                for( k = l; k <= r; k++) {
                    number = a[k];
                    exponent = 0;
                    
                    while( number % b[j] == 0 ) {
                        exponent += 1;
                        number /= b[j];
                    }
                   sum += exponent; 
                }
            }
        

        printf("%d\n",sum);
    }
    return 0;
}
