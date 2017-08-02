/* A derived class derives all members except Constructors, Destructors 
 * and friends of base class. However the constructors and destructors of
 * base class are automatically called when objects of derived class are
 * created or destroyed.
 * We can also specify which constructor of the base class to be called
 * when objects of derived class are created 
 * SYNTAX
 * derived_constructor_name(params) : base_constructor_name(params)(...)
 * This program demonstrates the use of syntax
 */
#include <iostream>
using namespace std;

class mother {
	public:
	mother(){
		cout<<"Mother Constructor with no parametes"<<endl;
		
	}
	mother(int a){
		oout<<"Mother Constructor with parameter "<<endl;
	}
};

class daughter : mother {
	public:
	daughter(){
		cout<<"Daughter with no parameter"<<endl;
	daughter(int a){
		cout<<"Daughter with parameter "<<endl;
	}
};
class son : mother {
	public:
	son(){
		cout<<"Son with no parameter"<<endl;
	son(int a) : mother(a){
		cout<<"Son with parameter "<<endl;
	}
};
		
int main(){
	daughter disha();	
	son sayan(0);

	return 0;
}
