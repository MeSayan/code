#include <stdio.h>

double f(double x)
{
  return x * x * x + x - 6;
}

double g(double x)
{
  return 3 * x * x + 1;
}

int main() {
  double x0,x1,diff;
  int i = 0;
  x0 = 1;
  do {
    x1 = x0 - f(x0)/g(x0);
    diff = x0 > x1? (x0-x1) : x1 - x0;
    x0 = x1;
    i++;
  }while( diff > 0.00001);
  printf("The Root correct upto 4 decimal places if %.4lf ",x1);
  printf("\nNo of Iterations required: %d",i);
  return 0;
}
