#include <list>
#include <stdio.h>


#define all(C) C.begin(), C.end()
#define tr(C,it) \
		for( decltype(C.begin()) it = C.begin(); it != C.end(); it++)


using namespace std;
int main() {
	int A[] = {1,24,1,5,3};
	
	list<int> li(A,A+5);
	
	tr(li,it) {
		printf("%d ",*it);
	}
	printf("\n");
	
	// Insert 1,2,3 at the back

	
	
	return 0;
	
}


