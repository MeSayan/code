#include <iostream>

using namespace std;
int main() {
	int e1 = 5, e2 = 20, e3 = 15;
	int *arr[3] = {&e1, &e2, &e3};
	
	cout << *arr[*arr[1] - 19];
	
	return 0;
}
