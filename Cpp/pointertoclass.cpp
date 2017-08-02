#include <iostream>
using namespace std;
class CRectangle{
	int width,height;
	public:
	void set_values(int,int);
	int area(void) { return width*height; }
};

void CRectangle::set_values(int a,int b){
	width=a;
	height=b;
}

int main(){
	CRectangle a,*b,*c;
	//Pointers pointing to CRectangle Objects
	CRectangle *d=new CRectangle[2];  //Array of crectangle obects
	b=new CRectangle; //Default Constructor
	
	/*Use of new operator enusues that concerned variable is created
	 * at runtime from heap memory so 'b' and 'd' are created from heap
	 */
	
	c=&a;
	a.set_values(1,2);
	b->set_values(3,4);
	d->set_values(5,6); //Accesing array elements using pointer
	d[1].set_values(7,8); //Pointer is first dereferenced then used
	
	// Note that areas of a and c will be equal coz c points to a
	cout<<"a area: "<<a.area()<<endl;
	cout<<"b area: "<<b->area()<<endl;
	cout<<"c area: "<<c->area()<<endl;
	cout<<"d area: "<<d[0].area()<<endl; //Also note (d+0)->area();
	cout<<"d[1] area: "<<d[1].area()<<endl; // Equivalent to d[1].area()
	
	//b and d were explicitly allocated form heap using new keyword.
	//A good program must always clean up its heap memory usage though \
	the process is automatic
	delete[] d;
	delete b;
	//NO need to delete a coz it is allocated from stack
	
	return 0;
}
