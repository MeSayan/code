#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <typeinfo>

#define all(C) C.begin(),C.end()
#define tr(C,it) \
		for( decltype(C.begin()) it = C.begin(); it != C.end(); it++)


using namespace std;

typedef vector<int> vi;
typedef set<int> set_i;
typedef multiset<int> mset_i;


int main() {
	int A[] = {1,2,4,1,5};
	vi a(A,A+5);
	mset_i m(all(a)); // Using range based consturctor
	int B[] = {2,12,4,2,5};
	vi b(B,B+5);
	mset_i n(all(b));
	
	mset_i o;
	
	tr(m,it) {
		printf("%d ",*it);
	}	
	printf("\n");
	
	tr(n,it) {
		printf("%d ",*it);
	}
	printf("\n");
	
	merge(all(m),all(n),inserter(o,o.begin()));
	
	tr(o,it) {
		printf("%d ",*it);
	}
	printf("\n");
	
	
	return 0;
}

