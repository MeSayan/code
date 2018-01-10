#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{    
    fstream file;
    file.open("cout.txt",ios::out);
    string line;
    
    //Backup streambuffers of cin and cout
    streambuf * stream_buffer_cout = cout.rdbuf();
    streambuf * stream_buffer_cin = cin.rdbuf();
    streambuf * stream_buffer_file = file.rdbuf();
    
    //Redirect cout to file
    cout.rdbuf(stream_buffer_file);
    
    cout << "This line written to file" << endl;
    
    //Redirect cout back to screen
    cout.rdbuf(stream_buffer_cout);
    cout << "This line is written to screen" << endl;
    file.close();
    
    file.open("cout.txt",ios::in);
    stream_buffer_file = file.rdbuf();
    cin.rdbuf(stream_buffer_file);
    
    getline(cin,line);
    cout << line << endl;
    
    
    return 0;
}
