/* In C++ streams are treated as objects and we can perfrom extraction
 * and inclusion of information  through >> and << operators respectively
 * There exixts a mechanism where stings in C++ can be converted to 
 * stream objects using 'stringstream' method. The stringstream objetct
 * so created behaves similar to other stream objects like 'cin' or 'cout'
 * */
 
 #include <iostream>
 #include <string> 		// For String Objects
 #include <sstream>		// For StringStream implementation
 
 using namespace std;
 int main()
 {
	 int i,n1;
	 float f;
	 string n;
	 string s="12 13 14 15 16 5.6 ";
	 //Creating strinstream object
	 stringstream stream1(s);
	 
	 // Or alternatively stream1.str(s)
	 
	 cout<<"We are displaying utitility of 'stringstream' class"<<endl<<
		" This is a standard string and we will extract tokens from it"
		<<s<<endl;
	
	/*
	stream1>>i;
	cout<<i<<endl;	
	
	stream1>>i;
	cout<<i<<endl;
	
	stream1>>i;
	cout<<i<<endl;
	
	stream1>>i;
	cout<<i<<endl;
	
	stream1>>i;
	cout<<i<<endl;
	
	stream1>>i;
	cout<<i<<endl;	
	*/
	for(i=1;i<=6;i++)	
	{
		if(i<=5)
		{
			stream1>>n1;	
			cout<<n1<<endl;
		}
		else
		{
			stream1>>f;
			cout<<f<<endl;
		}
	}
	return 0;
	
}
