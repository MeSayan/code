#include <stdio.h>
float f(float x)
{
  return x*x*x-9*x-5;
  }

void main()
{
  int i = 0;
  float newmid = 0,mid = 0,a = 0,b = 0;
  
  
  do{
    printf("Enter values of interval:");
    scanf("%f %f",&a,&b);
    }
  while( f(a)*f(b) > 0);
  
  do {
    
    mid = (a+b)/2;
    
    printf("mid = %f newmid = %f i= %d and f(mid) = %f\n",mid,newmid,i,f(mid));
    if( mid == newmid)
    break;
    else if (f(a) * f(mid) < 0)
    b = mid;
    else if ( f(mid) * f(b) <0 )
    a = mid;
    
    newmid = mid;
    i++;
    
    }
    
  while( f(mid) != 0 );
  
  printf("The Interval is [%f, %f]\n",a,b);
  printf("Root of f(x) is : %f\n",mid);
  printf("No of iterations: %d\n",i);
  
}
