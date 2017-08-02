/* C++ implements a powerful string object class similar to that
 * of java. Thus there are two ways in string manipulation
 * The first method is derived from C where strings are noting but
 * 'null' terminated character arrays.
 * In the second method 'string' objects are used like other data types
 * such as int etc
 * It will be shown that string objects of C++ provide all features of 
 * Strings so it is 
 * preferable to use string objects only and ignore including C specific 
 * code like strcat strcpy etc which are very much required if we use
 * C's implementation of strings that is null terminated char arrays
 */


#include <iostream>
#include <string> //To utilise string objects implemented in C++
#include <cstdlib>
#include <string.h> 
/*We can include C header files so we are including string.h library
from C  to get access  to strcat strcpy etc
Alternatively we could haves  included the 'cstring' library to get
access to functions like strcat strlen etc
*/

using namespace std;
int main()
{
	int a=1,b=2;
	
	//Approach 1 : Using string objects
	
	string s="Hello this is a string.";
	cout<<s<<a<<endl;
	s="This is another string."; //String objects can be reassigned to other literals
	cout<<s<<b<<endl;
	s=s+"This is third string."; //String obects can also be added to one another
	cout<<s<<(a+b)<<endl;
	
	
	for(int i=0;i<s.size();i++)  //s.size() gives size of the string
	{
	  if(s[i]=='\0')				//Like C string objects are also null terminated.
	  break;
	  cout<<s[i];					//Individual string characters can be accesed using [] notation
    }
    
	cout<<endl;
	
	//Approach 2: Using char arrays;
	
	char str[80]="Hello this is a string.";
	cout<<str<<a<<endl;
	strcpy(str,"This is another string.");
	cout<<str<<b<<endl;
	strcat(str,"This is third string.");
	cout<<str<<(a+b)<<endl;
	
	return 0;

}
