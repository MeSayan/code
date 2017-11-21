#include <stdio.h>
#define INVALID -1

/*=====================================================================
 To change the segment tree from RMQ to MaxSum change the combine()
 function. The combine() function is used to combine results from two
children of the node
Also be for each implementation set the prpoer preprocessor directive.
For RMQ, INVALID < 0, for sum INVALID = 0 etc
=====================================================================*/

class SegTree {
	public:
	int *tree;
	int * A;
	int N;
	
	SegTree();
	SegTree(int);
	~SegTree();
	
	void BringDataToLeaf(int [] );
	void PrintTree();
	int combine(int, int);
	void Build();
	void Update(int,int);
	int Query(int,int);
	
	// Util functions are used to reduce paramteres in function call
	int QueryUtil(int,int,int,int,int);
	void BuildUtil(int,int,int); // Root, Start, End
	void UpdateUtil(int,int,int,int,int);
};

SegTree::SegTree(int n) {
	tree = new int[2*n]; // An array of size N requires 2N-1 tree
	A = new int[n];
	N = n;
}

int SegTree::combine(int a, int b) {
	return a+b;
}

void SegTree::BringDataToLeaf(int src[]) {
	int i ;
	for( i = 0; i < N; i++) 
		A[i] = src[i];
}

void SegTree::PrintTree() {
	int i;
	for( i = 1; i < 2*N; i++) 
		printf("%d ",tree[i]);
    printf("\n");
}


//Build Operation
void SegTree::Build() {
	BuildUtil(1,0,N-1);
}
void SegTree::BuildUtil(int node,int start, int end) {
	if( start == end) {
		tree[node] = A[start];
	}
	else {
		int mid = (start + end) / 2;
		BuildUtil(2*node,start,mid);
		BuildUtil(2*node+1,mid+1,end);
		// Combine
		tree[node] = combine(tree[2*node],tree[2*node+1]);
	}
}

// Update Operation
void SegTree::Update(int position, int value) {
	UpdateUtil(1,0,N-1,position,value);
}
void SegTree::UpdateUtil(int node,int start, int end,int idx, int val) {
	if( start == end ) {
		// At the leaves
		A[idx] = val;
		tree[node] = val;
	}
	else {
		int mid = (start+end) / 2;
		if( start <= idx && idx <=mid) {
			// Left Child
			UpdateUtil(2*node,start,mid,idx,val);
		}
	    else {
			// Right Child
			UpdateUtil(2*node+1,mid+1,end,idx,val);
		}
		// Combine
		tree[node] = combine(tree[2*node],tree[2*node+1]);
	}
}

//Query Function
int SegTree::Query(int l, int r) {
	return QueryUtil(1,0,N-1,l,r);
}

int SegTree::QueryUtil(int node,int start,int end,int l, int r) {
	
	if( r < start || end < l) {
		// Range of node is outside given range
		return INVALID;
	}
	if( l<=start && end <= r) {
		// Range represented by node is completely inside given range
		return tree[node];
	}
	// Range represented by a node is partially inside and partially
	//outside
    int mid = (start+end)/2;
    int q1 = QueryUtil(2*node,start,mid,l,r);
    int q2 = QueryUtil(2*node+1,mid+1,end,l,r);
    return combine(q1,q2);
}

SegTree::~SegTree() {
	delete[] tree;
}
/*=====================================================================
=====================================================================*/


int main() {
	SegTree b(7);
	int c[] = {40,39,38,37,36,35,34};
	b.BringDataToLeaf(c);
	b.Build();
	b.PrintTree();
	b.Update(1,120);
	b.PrintTree();
	printf("Min element in 1 to 3 is %d \n",b.Query(1,3));
	return 0;
}





