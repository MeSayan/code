#include <iostream>
#include <thread>
using namespace std;

void foo(int Z) {
    for(int i = 0; i < Z; i++ ) {
        cout << "Thread using function pointer as callback\n";
    }
}

class thread_obj {
	public:
	void operator()(int x)
	{
		for (int i = 0; i < x; i++)
			cout << "Thread using function object as  callback\n";
	}
};

int main() 
{
    cout << "Threads 1 and 2 and 3 operating independently" << endl;
    //This thread is launched by using function pointer as
    // callback
    thread th1(foo, 3);
    
    //This thread is launched by using function object as
    //callback
    
    thread th2(thread_obj(),3 );
    
    //Define a Lambda Expression
    auto f = [] (int x) { for ( int i = 0; i< x; i++) 
								cout << "Thread using lambda"
								        " expression as callback\n";
					    };
	// This thread is lanuched by using lamda expression
	// as callback			
    thread th3(f,3);
    
    
    // Wait for the threads to finish
    // Wait for thread t1 to finish
    th1.join();
    // Wait for thread t2 to finish
    th2.join();
    // Wait for thread t3 to finish
    th3.join();
    
    return 0;
}
