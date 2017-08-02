// Multi Dimensional Vectors

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector< vector<int> > V;
    vector< int > A,B;
    // Get two iterators, one for top level, another for bottom (nested) level
    vector< vector<int> >::iterator ite_i;
    vector< int >::iterator ite_j;

    A.push_back(10);
    A.push_back(20);
    A.push_back(30);
    B.push_back(100);
    B.push_back(200);
    B.push_back(300);
    V.push_back(A);
    V.push_back(B);

    for(ite_i = V.begin(); ite_i != V.end(); ite_i++) {
        for(ite_j = (*ite_i).begin(); ite_j != (*ite_i).end(); ite_j++) {
            cout << *ite_j << " ";
        }
        cout << endl;
    }

    return 0;
}
