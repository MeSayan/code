#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    long long int N,M;
    int flag = 1, count = 0, r1, r2;
    scanf("%lld", &N);
    M = N;
    
  
    while( M > 0) {
       r1 = M % 10;
       r2 = (M % 100)/10;
      
      if( r1 < r2){
          flag = 0;
      }
      M = M / 10;
      count++;
   }
      
    if(flag == 0) {
      M = r1 * pow(10,count-1) - 1;
      printf("%lld\n", M);
    }
    else {
      printf("%lld\n", N);
    }
  
    return 0;
}

    