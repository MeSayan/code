// Custom implementaion of String in C++, and demonstration of operator
// overloading to concatanate 2 Strings

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct _String { char * str; } String;

String operator+(const String &s1,const String& s2) {
    String s;
    s.str = (char *)malloc(strlen(s1.str) + strlen(s2.str) + 1);
    strcpy(s.str, s1.str);
    strcat(s.str, s2.str);
    return s;
}

int main() {
    String fname, lname, name;

    fname.str = strdup("Sayan");
    lname.str = strdup("Mahapatra");
    name = fname + lname;

    cout << fname.str << endl;
    cout << lname.str << endl;
    cout << name.str << endl;

    return 0;
}

