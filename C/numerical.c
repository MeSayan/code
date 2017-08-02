#include <stdio.h>
#include <math.h>
#include <float.h>

double abs_double(double x) 
{
  if(x > 0)
  return x;
  return -x;
}

double findRootsInterval(double *a,double *b,int origin,double (*fp)(double)) 
{
  /* a stores lower bound of interval
   * b storess upper bound of interval
   * origin specifies the point around which values are to be tested
   * fp is a function pointer
   * Return 
   * -1 : Error
   * 0 : Success
   */
  
  double  i;
  for(i = 1;;i+=0.5) {
    if( (*fp)(origin+i) * (*fp)(origin-i) < 0 ) {
      *a = origin-i;
      *b = origin+i;
      return 0;
    }
  }
  return -1;
}

double bisectionMethod(double a,double b,int e,double (*fp)(double)
                        ,int verbose) {
  /* a is the lower bound of the interval
   * b is the upper bound of the interval
   * e is the desired accuracy specified in no of decimal places
   * fp is a function pointer specifying the equation
   */
  
  //fp = function pointer;
  double mid = (a+b)/2.0;
  double premid =0.0;
  int no = 0;
  
  while( abs_double((mid-premid)) >= pow(10,-(e+1))) {
    
    if(verbose)
      printf("xn = %lf and xn+1=%lf and |xn+1-xn|=%lf\n",premid,mid
           ,abs_double(mid-premid));
    
    premid = mid;
    
    if( (*fp)(mid) == 0)
    return mid;
    
    if( (*fp)(a) * (*fp)(mid) < 0 )
    b = mid;
    
    else if ( (*fp)(mid) * (*fp)(b) < 0 )
    a = mid;
    
    no++;
    mid = (a+b)/2;
    
    }
    
    if(verbose)
      printf("No Of Iterations: %d\n",no);
    
    return mid;
  }
  
double NRMethod(double x0,double (*f)(double),double (*g)(double)
                 ,double accuracy,int verbose)
{
  double x1,diff;
  int i = 0;
  
  do
    {
      x1 = x0 - f(x0) / g(x0);
      diff = x0 > x1 ? (x0-x1) : x1-x0;
      if( verbose )
        printf("x0 = %lf x1 = %lf and |x1-x0| = %lf\n",x0,x1,diff);
      x0 = x1;
      i++;
    }
  while( diff > accuracy);
  
  if(verbose)
    printf("No of Iterations: %d\n",i);
  
  return x1;
}
  
double trapezoid_numerical_integration(double x0,double xn,
                                        int ndivisions,double (*fp)(double))
{
  int i;
  double result = 0,h;
  h = (xn-x0)/ndivisions;
  printf("Value of h is %lf:\n",h);
  
  for(i = 0;i <= ndivisions;i++) {
    if( i == 0 || i == ndivisions ) 
      result += fp(x0+i*h);
    else
      result += 2.0 * fp(i);
    printf("%lf ",2.0*fp(i));
    printf("Iterations: %d and f(x) = %lf and sum = %lf \n",i,fp(x0+i*h),result);
    }
  result = result*0.5*h;
  
  return result;
}



