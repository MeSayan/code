/* Inheritance is a feature in C++ where one class (called derived class)
 * can derive the 
 * attributes i.e both data and functions of another class (called
 * base class)
 * 
 * SYNTAX
 * return_type derived_class_name : max_access_level base_class 
 * 
 * A class may derive data from another class but what about the 
 * acces specifiers of the concerned data.
 * The max_data_level specifies the max access level that derived data
 * obtains in the derived class
 * Let us say class C has 1 private 1 protected and 1 public data membrs
 * Another class D inherits C so it has same 3 data members but width
 * possibly different acces scopes.
 * If the max access for D is specified as public it means that
 * all members will be inherited keeping their access specifiers intact
 * However if max access was specifies as private it means that 
 * data members with acces greater than private will be inherited as 
 * private only
 * Furthermore if max access level is protected it means
 * that private members will be inherited with their access levels intact
 * and data members with acces level greeater than max access will  be
 * inherited but their acccess will be reduced to max access in the
 * derived class
 * public has highest access level and private has lowest
 * 
 * */


#include <iostream>
using namespace std;

class CPolygon {
	protected:
	int height,width;
	public:
	void set_values(int a,int b){
		height=a;
		width=b;
}		
};

class CRectangle: public CPolygon {
	public:
	int area(){
		return width*height;
	}
};
class CTriangle : public CPolygon {
	public :
	double area(){
		return width*height*0.5;
	}
};

int main(){
	CRectangle rect;
	CTriangle trg;
	rect.set_values(2,4);
	trg.set_values(2,4);
	cout<<rect.area()<<endl;
	cout<<trg.area()<<endl;
	
	return 0;
}



