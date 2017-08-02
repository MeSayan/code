/* ---------------------------------------------------------------------
 * C++ supports classes. Classes are data structures which not only
 * contain data memebers but also functions. Thus C++ implementaion of
 * a class is similar to that of struct except than we can include
 * functions. Besides this access specifier for each member of the
 * class can be specified
 * An 'access specifier' specifies or lays down rules for accesibility
 * of a variable in different parts of code. Whether we can acces a 
 * variable or modify (directly and indirectly) depends on the access 
 * specifer associated with the variable
 * In C++ the following access specifiers are provide
 * private : Concerned element (both data and functions) can only be
 * accessed from within the class. This is the default specifer for all 
 * elements of a class unless otherwise specified.
 * protected : Concerned element can be accessed from within the class
 * and only from within derived classes.
 * public :   Concerned element can be accessed fom anywhere freely.
 * ---------------------------------------------------------------------  
	SYNTAX
	class class_name
	{
		access_specifier_1 : member_1;
		access_specifier_2 : member_2
		...
		...
	}object_names;
	
 */

#include <iostream>
using namespace std;
class CRectangle{
	int x,y;	//private data members cant't be accessed out of class
	public :
	void setvalues(int,int);
	int area()	{ return x*y; }
};

void CRectangle::setvalues(int a,int b){
	x=a;
	y=b;
}


int main(){
	CRectangle rect;
	rect.setvalues(3,5);
	
	//If we try to access protected memberes directly we have error
	//rect.x=5;
	//rect.y=6;
	
	cout<<"Area is : "<<rect.area();
	return 0;
}
