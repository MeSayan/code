#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int N, k;
  int i = 0;
  
  scanf("%d", &N);
  double R[N];
  
  for( i = 0; i < N; i++) {
    scanf("%lf", R+i);
  } 
  
  scanf("%d", &k);
  
  sort(R,R+N);
  
  
  
  long double sum = 0.0;
  double percent = (100 - k)/100.0;
  
  for( i = N-1; i >= 0; i--) {
    sum += (4*3.14*R[i]*R[i]*R[i]*pow(percent,N-1-i))/3;
    //printf("%llf\n", sum);
  }
  
  printf("%.2llf\n", sum);
  return 0;
  
}
