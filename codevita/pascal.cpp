// Pascal

#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {

  int N;
  int max1, max2, max3, max4, max5, max6;
  int a, b, c, d, e, f;
  
  scanf("%d", &N);
  int inp[N];
  
  for(int i = 0; i < N; i++){
    
    scanf("%d,", inp+i);
    
  }
  
  sort(inp, inp+N);
  
  d = inp[N-1];
  c = inp[N-2];
  b = inp[N-3];
  e = inp[N-4];
  a = inp[N-5];
  f = inp[N-6];
  
  //printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
  long long int sum = (a+4*b+6*c+4*d+e)*(b+4*c+6*d+4*e+f);
  
  printf("%lld\n", sum );
  return 0;
}
