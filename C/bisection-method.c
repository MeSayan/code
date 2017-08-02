#include <stdio.h>
#include "numerical.h"

double func(double x) {
  double result = x*x*x-9*x-5;
  return result;
  
  }
  
  
int main() {
  
  double a,b,result;
  int e;
  printf("Enter no of decimal places: ");
  scanf(" %d",&e);
  findRootsInterval(&a,&b,5,func);
  result = bisectionMethod(3,4,e,func);
  
  printf("Interval: [%lf ,%lf]\n",a,b);
  printf("Root: %.*lf\n",e,result);
  
  
  return 0;
  
  
  }  
