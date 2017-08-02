/*  Often we donnot know in advance what is the data type of a variable. What we do
 * know in advance is some operations that we wish to peform on the variable .
 * And that theese operations are largely independent of the type of variable.
 * Say for example if we wish to compare two numbers a and b. The code for comparing the two is similar for both int and float.
 * The question arises how do we implement this function if the data type is not known
 * beforehand ?
 * C++ provides us with a feature called Templates where we can write code using
 * 'template ' variables. This variable can be anything legal data type in C++.
 * The exact type of the varible is determined by the compiler when the code is 
 * beinf compiled and the compiler undertakes the duty to ensure that correct code
 * is generated  in accordance with the data type of the variable.
 * 
 * SYNTAX
 * --------------------------------------------------------------------------------------------------------------------
 * template <Class T> //Any class T which will be  used to refer to data type
 * 
 * T greaterOfTwo(T a,T b) {
 *    if a>b
 *        return a;
 *    else
 *    return b;    
 * }
 * To call the function we would do greaterOfTwo<int>(a,b) or greaterOfTwo<float>(a,b)
 * Thus we see that the data type is specified explicitly in the method calling statement
 * 
 * 
-------------------------------------------------------------------------------------------------------------------------
* */

#include <iostream>
#include <string>
using namespace std;

template <class T>
T getMax(T a,T b){
  T result;
  result = a > b ? a : b;
  return result;
  }


int main() {
  
  int i = 5,j = 6, k;
  float l = 10.1, m = 5.6, n ;
  string a= "Hello World", b= "World";
  
  k = getMax<int>(i,j);
  n = getMax<float>(l,m);
  
  //For int values
  cout << "Value of k is: " << k << endl;
  //For floating point values
  cout << "Value of n is: " << n << endl;
  //Even Strings are supported;
  cout << getMax<string>(a,b);
  return 0;
}
  
  



