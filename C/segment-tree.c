#include <stdio.h>
#include <stdlib.h>


struct node {
    int value, low, high;
    struct node * leftChild;
    struct node * rightChild;
};
    
    
int buildSegmentTree(int array[], int low, int  high, struct node * SegmentTree) {
    
    if( low == high) {
    // We have only 1 element in array
    SegmentTree->value = array[low];
    SegmentTree->low = SegmentTree->high = low;
    return SegmentTree->value;
    }
    
    // Partition
    int mid = (low+high)/2;
    
    SegmentTree->low = low;
    SegmentTree->high = high;
   
    // Creating Children
    SegmentTree->leftChild = (struct node *)calloc(1,sizeof(struct node));
    SegmentTree->rightChild = (struct node *)calloc(1,sizeof(struct node));
    SegmentTree->value = buildSegmentTree(array, low, mid, SegmentTree->leftChild) +
                                           buildSegmentTree(array, mid+1, high, SegmentTree->rightChild);
                                           
    //Must Return a value to carry on recursion
    return SegmentTree->value;
    }
    
// Allocates memory for root and calls method to construct segment tree

struct node * getSegmentTree(int array[], int n) {

    if (n <= 0)
        return NULL;
        
    struct node * SegmentTree  = (struct node *)calloc(1,sizeof(struct node));
    buildSegmentTree(array, 1, n, SegmentTree);
    
    return SegmentTree;
    }
    
    // A utillity function used for Inorder Walk
    
void print(struct node * SegmentTree) {
        printf("%d -> [%d, %d]\n", SegmentTree->value, SegmentTree->low, SegmentTree->high);
}


void inOrderWalk(struct node * SegmentTree) {
    
    if( SegmentTree == NULL) {
        return;
     }
    
    inOrderWalk(SegmentTree->leftChild);
    printf(" %d ", SegmentTree->value);
    inOrderWalk(SegmentTree->rightChild);

}

// Recursive procedure to find the sum of elements from array[low] to array[high] using the 
// SegmentTree
int getSumQuery(struct node * SegmentTree, int low, int high, int sum)
{
	if (low == SegmentTree->low && high == SegmentTree->high) {
		sum += SegmentTree->value;

		return sum;
	}

	if (low == high) {
		int mid = (SegmentTree->low + SegmentTree->high) / 2;

		if (low <= mid) {
			sum = getSumQuery(SegmentTree->leftChild, low, low, sum);
		} else {
			sum = getSumQuery(SegmentTree->rightChild, high, high, sum);
		}
	} else {
		int mid = (SegmentTree->low + SegmentTree->high) / 2;

		if (low <= mid && high > mid) {
			// Query range is partly in the left child and partly in the right child
			sum = getSumQuery(SegmentTree->leftChild, low, mid, sum);

			if (high >= mid + 1) {
				sum = getSumQuery(SegmentTree->rightChild, mid + 1, high, sum);
			}
		} else if (low <= mid && high <= mid) {
			// Query range is completely in the left Child
			sum = getSumQuery(SegmentTree->leftChild, low, high, sum);
		} else {
			// Query range is completely in the right child
			sum = getSumQuery(SegmentTree->rightChild, low, high, sum);
		}
	}

	return sum;
}


                       
                         
// Updates an element in SegmentTree and makes the necessary adjustments 

int updateQuery(struct node * SegmentTree, int index, int newValue, int difference) {
    
    if(SegmentTree->low == SegmentTree->high) {
        difference += newValue - SegmentTree->value;
        SegmentTree->value = newValue;
        return difference;
    }
    
    int mid = (SegmentTree->low + SegmentTree->high) / 2;

    if( index <= mid) {
        difference = updateQuery(SegmentTree->leftChild, index, newValue, difference);
    } else {
        difference = updateQuery(SegmentTree->rightChild, index, newValue, difference);
    }

    SegmentTree->value += difference;

    return difference;

}

int main()
{
	int n;

	printf("Enter the size of input -\n");
	scanf("%d", &n);

	int arr[n + 1], i;

	printf("\nEnter %d Integers -\n", n);

	arr[0] = -1;
	for (i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
	}

	struct node * SegmentTree = getSegmentTree(arr, n);

	// Printing the Tree after constructing
	printf("\nIn-Order Walk of the Segment Tree -\n");
	inOrderWalk(SegmentTree);

	int low, high;

	// Demonstrating Sum Query
	printf("\nEnter the range for sum query - [1, %d]\n", n);
	scanf("%d%d", &low, &high);
	printf("\nSum = %d\n", getSumQuery(SegmentTree, low, high, 0));

	// Demonstrating Update Query
	printf("\nEnter the index of number and new value to update -\n");
	scanf("%d%d", &i, &low);
	updateQuery(SegmentTree, i, low, 0);

	// Printing the Tree after Updating
	printf("\nIn-Order Walk of the Segment Tree after Update -\n");
	inOrderWalk(SegmentTree);

	return 0;
}
    
    
    
    
