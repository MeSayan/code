#include <iostream>
#include <new>


using namespace std;
int main()
{
	int i,n;
	int * p;
	cout<<"How many numbers would you like to type?";
	cin>>n;
	
	/* While using new operator if the request for memory is unsuccesful
	 * the program execution is stopped as an Exception is thrown
	 * The nothrow modifier allows us to proceed with  the program  
	 * even if memory could not be allocated
	 * if 'new' fails then it returns '0' to the pointer
	 * 
	 * */
	p= new (nothrow) int[n];
	
	
	if(p==0)
	{
		cout<<"Memory Could not be allocated";
		return 1;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			cout<<"Enter no: ";
			cin>>p[i];
		}
	}
	cout<<"You have entered.";
	
	for(i=0;i<n;i++)
	cout<<p[i]<<" ";
	
	//Freeing up memory
	delete[] p;
	/* To delete more than one memory block like array delete [] is used
	 * to delete a single element just 'delete' followed by pointer name
	 * is sufficient
	 * */
	
	return 0;
}
