#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    vector< string > SS;
    SS.push_back("The number is 10");
    SS.push_back("The number is 20");
    SS.push_back("The number is 30");

    cout << "Loop By Index \n";
    int i;
    for(i = 0; i < SS.size(); i++)
        cout << SS[i] << endl;

    cout << endl << "Looping By Iterator" << endl;

    vector< string >::iterator ite;
    for( ite = SS.begin(); ite != SS.end(); ite++)
        cout << *ite << endl;

    cout << endl << "Reverse Iterator" << endl;

    vector<string>::reverse_iterator rite;
    for( rite = SS.rbegin(); rite != SS.rend(); rite++)
        cout << *rite << endl;

    return 0;
}

    
