#include <stdio.h>

int main() {
  int M, order, total;
  scanf("%d %d", &M, &order);
  int N[M];
  total = 0;
  
  for(int i = 0; i < M; i++) {
    scanf("%d", N+i);
    total += N[i];
  }
  
  if( order < total){
    printf("Thank you, your order for %d eggs are accepted \n",order);
  } 
  else{
    order = total - 1;
    printf("Sorry, we can only supply %d eggs \n ", order);
  }
  
  for(int  i = 0; i < M; i++) {
    if( order > N[i]) {
      printf("%d %d %d \n", N[i], N[i], 0);
      order -= N[i];
      N[i] = 0;
    }
    else {
      printf("%d %d %d \n", N[i], order, N[i]-order);
      N[i] -= order;
      order = 0;
    }
  }
  return 0;  
}
