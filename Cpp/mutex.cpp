#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int main() {
	int c = 0;
	
	std::mutex obj;
	
	auto f = [obj,&c] () { for(int i = 0; i < 10000; i++) {
						obj.lock();
						c++;
						obj.unlock(); }};
	
	std::vector<std::thread> V;
	
	for( int j = 0; j < 5; j++) {
		V.push_back(std::thread(f));
	}
	
	// Join All threads
	
	for ( int j = 0; j < 5; j++) {
		V[j].join();
	}
	
	//Print Value of c
	std::cout << c << std::endl;
	
	return 0;
}

