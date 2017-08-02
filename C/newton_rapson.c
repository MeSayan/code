double poly(double x)
{
  return x * x * x + x - 6;
}
double poly_diff(double x)
{
  return 3 * x * x + 1;
}  

double trans(double x)
{
  return exp(x) * cos(x) - 1.2;
}

double transd(double x)
{
  return exp(x) * ( cos(x) - sin(x) );
}

int main()
{
  double result = NRMethod(-1,trans,transd,0.00000000000001,1);
  printf("Root is: %lf",result);
  return 1;
}
