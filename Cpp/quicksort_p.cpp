/* C++ implementation QuickSort using Lomuto's partition
Scheme.*/
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++) {

		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot) {

			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
	// Generate a random number in between
	// low .. high
	int random = low + rand() % (high - low);

	// Swap A[random] with A[high]
	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}


void quickSort_seq(int arr[], int low, int high)
{
	if (low < high) {

		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition_r(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		
		
		quickSort_seq(arr, low, pi - 1);
		quickSort_seq(arr, pi + 1, high);
		
	}
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort_par(int arr[], int low, int high)
{
	std::thread t1,t2;
	if (low < high) {

		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition_r(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		
		// if no of elements in subarray is < 2028 
		// switch to sequential quicksort
		int K = 1000;
		
		if ( high-low < K) {
			//switch to seq version
			quickSort_seq(arr,0, pi-1);
			quickSort_seq(arr, pi+1, high);
		
		} else {
			// Use parallelization
			std::thread t1(quickSort_par, arr, 0, pi-1);
			quickSort_par(arr, pi+1, high);
			t1.join();
		}
	}
}	    


/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	
	srand(time(NULL));
	//fill array with large random numbers
	int  values[100000];
	int n = sizeof(values)/sizeof(values[0]);
	generate(values, values+n, []() { return rand()%100; });
	
	
	auto start = std::chrono::high_resolution_clock::now();
	quickSort_par(values, 0, n - 1);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
	
	//printf("Sorted array: \n");
	//printArray(values.data(), n);
	
	cout << "Sorting took: " << duration.count() 
	     << " microseconds"<< endl;
	
	return 0;
}
