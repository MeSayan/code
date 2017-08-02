/*
------------------------------------------------------------------------
In most programming languages to access a variable we need to specify:
it's name and it's scope. In C++ in addition to theese two we have 
another paramter called namepace. Thus two variables having same name
and scope can belong to different namespaces and thus occupy separate
memory locations and be different from one another.
All elements defined in C++ standard library are defined under 'std' 
namespace therefore to access them we need to prefix their namespace
in this manner, namespace::element_name
Examples: std::cout , std::cin
An alternative is to already direct the compiler to look for variables
in a namespace which is predefined 
Example: using namepace std;
Multiple namepaces can be stacked one on top of other using multiple 
using statements one after all
	using namepace namespace_1
	using namespace namespace_2
Thus namepaces can be thought of like JAVA packages. Classes,
functions and variables are first declared and then grouped into
namespaces so that theese elements dont become keywords and forbid the 
use of other elements which happen to have a same name.
It is considered not to import entire namepaces u via the 'using' 
command rather import only speciffic elements using syntax like
using namespace:variable;
------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

//Assigning some Global Variable with same name but different namespaces

namespace first {
	int x = 1;
	int y = 2;
}

namespace second{
	int x = 3;
	int y = 4;
}

int main(){
	
	// To avoid conflicts arising due to same variable name
	//the using statements have been grouped in { } blocks
	
	{
	using namespace first;
	cout << "The Value of x in namespace 'first': " << x<<endl; //Refferrin to x of first namepace
	cout << "The Value of x in namespace 'second': " << second::x<<endl;
	}
	
	{
	using namespace second;
	cout << "The Value of x in namespace 'second': " <<x<<endl; //Referring to x of second namespace
	cout << "The Value of y in namespace 'first': " <<first::x<<endl;
	}
	
	return 0;
}
