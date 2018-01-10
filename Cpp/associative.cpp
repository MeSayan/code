#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

std::mutex mut;

template <typename T>
T f(T a, T b) {
	return min<T>(a,b);
}

template <typename T, typename InpItr>
void f_block(InpItr first, InpItr last, T &result) {
	
	mut.lock();
	cout << "Thread starts for block from " <<*first << " to " 
	     << *(prev(last)) << "\n";
	mut.unlock();
	     
	T m = *first;
	
	for ( InpItr j = next(first); j != last; ++j) {
		m = f(m, *j);
	}
	
	result = m;
	
	mut.lock();
	cout << "Thread Ends for block from " << *first << " to "
	     << *(prev(last)) << "\n" ;
	mut.unlock();
}

template <typename T, typename InpItr>
void f_range(InpItr first, InpItr last, T res) {
	
	InpItr block_start, block_end;
	
	block_start = block_end = first;
	
	int size = distance(first, last);
	//No of thread
	int n_thread = 4;
		
	//No of blocks
	int block_size = size/n_thread;
	
	//Vector for storing result from each block, there are n
	// blocks
	vector<T> results(n_thread);
	
	//Vector for storing threads. size n-1
	vector<std::thread> threads(n_thread-1);
	
	auto f = [&](auto start, auto stop, int i) { f_block(block_start, stop, results[i]); };
	
	//Create thread
	for ( int i = 0; i < n_thread-1; ++i) {
		block_start += i*block_size;
		block_end = block_start+block_size;
		threads[i] = thread(f, block_start, block_end, i);
    }
    
    f_block(block_start, last, results[3]);
    
    for(auto &t:threads) {
		t.join();
	}
	
    //print results vector
    for (auto r: results)
		cout << r << " ";
	cout << "\n";

}
    

int main() {
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	vector<int> results(4);
	
	int result = 0;
	//int n = v.end()-v.begin();
	
	f_range(v.begin(), v.end(), result);
	
	//auto g = [&](auto start, int span) { f_block(start, start+span, result); };
	
    cout << "Result of performing f on range: " << result << endl;
    return 0;
}
