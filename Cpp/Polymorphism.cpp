/* ---------------------------------------------------------------------
 * In computer science polymorphism is the ability of an entity with
 * a fixed identity to behave differently in different scenarious
 * Thus one particular behaviour can not be used to identify the 
 * entity
 * For example a function may have fixed name but have different
 * implementations which not only take different parameters as inputs
 * but also the underlying functionality may be different
 * In C++ this is the case of 'overloaded' and 'virtual functions'
 * Any class which has atleast one virtual function is called a polymor-
 * phic class.
 * A virutal function is a function whose defination provided in one
 * base class can be modified or kept intact in all classes that
 * derive from this class.
 * Thus virtaul functions only serve to give an indication of what
 * is to be performed
 * A virtual function which has atleast some minimal functionality
 * defined in the base class is called an 'impure virtual'  function.
 * On the other hand if the virtual function has zero implementation/
 * functionality defined in it is called a 'pure virtual' function
 * Virtual functions are decalared by placing keyword 'virtual'
 * in their declaration in the base class
 * 
 * SYNTAX
 * ---------------------------------------------------------------------
 * class base_class {
 * 		//Some data members
 * 		//Some functions
 * 		
 * 		//A virtual function (impure)
 * 		virtual int area1() { //Some Implementaion }
 * 		//A pure virtual function (pure)
 * 	virtual int area2()=0; //Note the '0' specified in declaration
 * };
 * ---------------------------------------------------------------------
 * 
 * A class that has atleaat one 'pure virtual' function is called an
 * abstract class. Onjects of such class cannot be instantiated.
 * A class that derives an abstract calss may choose to define
 * one or more of functions of abstract class however at its own 
 * indescrition
 * ---------------------------------------------------------------------
 * In C++ plus a pointer to a derived class is type compatible
 * with a pointer to base class .
 * However the reverse is not true
 * A pointer to base class is not type compatible with pointer to
 * derived class. This is because the derived class may declare one
 * or more of its own data members and so a pointer to a base class
 * cannot possibly have any knowledge of theese members.
 * ---------------------------------------------------------------------
*/

#include <iostream>
using namespace std;
//Base Class
class CPolygon{
	protected:
	int height,width;
	public:
	void set_values(int a,int b){
		height=a;
		width=b;
	}
};
//Derived Classes
class CRectangle : public CPolygon{
	public:
	int area(){
		return height*width;
	}
};
class CTriangle : public CPolygon {
	public:
	int  area() {
		return height*width/2;
	}
};

int main(){
	CRectangle crect;
	CTriangle ctrg;
	//Pointers of base class
	CPolygon * cp1=&crect;
	CPolygon * cp2=&ctrg;
	/*Pointers of a base class when pointing to a derived class 
	can only access those membrs which derived class inherits from that \
	particular base class
	*/
	cp1->set_values(2,4);
	cp2->set_values(2,4);
	
	/* We have to access area function using crect and ctrg 
	cp1 and cp2 cannot be used to access area() because area is not 
	defined in CPolygon
	*/
	cout<<"Area of CRectangle is: "<<crect.area()<<endl;
	cout<<"Area of CTriangle  is: "<<ctrg.area()<<endl;
	return 0;
}
