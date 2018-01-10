#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <exception>
#include <random>
using namespace std;

int doSomething(char c) {
	default_random_engine dre(c);
	uniform_int_distribution<int> id(10,1000);
	
	for ( int i = 0; i < 10; i++) {
		this_thread::sleep_for(chrono::milliseconds(id(dre)));
		cout.put(c).flush();
	}
	
	return c;
}

int func1() {
	return doSomething('.');
}

int func2() {
	return doSomething('+');
}

int main() {
	cout << ". in background, + in foreground " << endl;
	future<int> result1 = async(launch::async, func1);
	
	int result2 = func2();
	
	result2 += result1.get() + result2;
	
	cout << "\n Result :" << result2 << endl;
	
	return 0;
}

