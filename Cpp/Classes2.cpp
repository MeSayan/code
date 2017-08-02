
/*  SYNTAX of '::' 
 *  -------------------------------------------------------------------- 
 *  The  :: operator is called scope operator and it is used to specify
 *  the scope of an element
 *  the usage is x::y where
 *   y is the element whose scope is to be specified
 * 	 and x is the scope of the elemeny like namespace or class
 *   Examples are std::cout  
 *   where cout is the standard stream object and std is its scope
 */

#include <iostream>
using namespace std;

class CRectangle {
	int width,height;
	public:
	CRectangle() {
		width  = 5;
		height = 2;
	}
	CRectangle(int a,int b) {
		 width = a;
		 height = b;
	 }
	double area();
};

double CRectangle::area(void){
	return width*height*1.0;
}
//Class defination ends

int main(){
	CRectangle recta,rectb(3,5);
	/*To use default specifer simply write the object name without 
	 * parenthesis
	 * so recta is ok
	 * but recta() is not allowed
	 * -----------------------------------------------------------------
	 * Furthermore C++ provides for default constructor iff and only
	 * if no constructors for the clas has been explicitly specified
	 * Thus iff we specify even one constructor then we need to manually
	 * specify the default constructor for the class
	 * The default constructor is the constructor that has no paramaters
	 * and objects can be instantiated simply by specifying their class
	 * and the name of the object without providing default values to
	 * the data members of the class.
	 *------------------------------------------------------------------
	 */
	
	cout<<recta.area()<<"      "<<rectb.area()<<endl;
	
	return 0;
}


