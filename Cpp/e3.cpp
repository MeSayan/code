#include <iostream>
#include <algorithm>

using namespace std;
bool compare (int i, int j) {return i > j; }

int main() {
	int data[] = {1,2,3,4,5};
	
	rotate(data,data+4,data+5);
	
	for(int i=0;i,5;i++)
	cout << data[i] << " ";
	
	return 0;
}
