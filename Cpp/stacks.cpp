#include <iostream>
using namespace std;
int topofstack=-1;
int capacity;
int *a;  //Integer pointer to point to array

void pop()
{
	if(topofstack==-1)
	cout<<"Stack is empty";
	else
	cout<<a[topofstack--];
}

void push()
{
 	if(topofstack==capacity-1)
 	cout<<"Stack is full";
 	else
 	{
		cout<<"Enter no to be pushed : ";
		cin>>a[++topofstack];
	}
}

int main()
{   
	cout<<"Enter capacity of stack ";
	cin>>capacity;
	int choice;
	a=new int[capacity];
	
	while(1)
	{
		cout<<"\nEnter 1 to pop , 2 to push and 3 to print stack ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: pop();break;
			case 2: push();break;
			case 3: for(int i=topofstack;i>=0;i--)
					cout<<a[i]<<" ";
					cout<<endl;
					break;
			default : return 1;
		}
   }
}
