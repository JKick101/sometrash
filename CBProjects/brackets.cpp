#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
		int* ptrStack; //указатель на вершину стека
		int Size; // размер
		int top; //номер текущего элемента стека
		
public:
	Stack(int SIZE);
	bool empty();
	bool full();
	void push(int value);
	void pop();
	void readStack();
	~Stack();
};


  Stack::Stack(int SIZE)
		{
			Size=SIZE;
			ptrStack=new int[Size];
			top=-1;
			
		}
		
	bool Stack::empty()
		{
			return (top==-1);
		}
	bool Stack::full()
	{
		return (top==Size-1);
	}
	
		
		void Stack::push(int value)
		{
			if (!(top==Size-1))
			ptrStack[++top]=value;
			else cout<<"Stack is full";
		}
		
		void Stack::pop()
		{
			if(!(top==-1))
			--top;
			else
			cout<<"Stack is empty";
		}
		
	void Stack::readStack()
	{
		
		for(int ix=top; ix>-1; ix--)
		cout<<ptrStack[ix]<<endl;
		
	 } 

	Stack::~Stack()
	{
		delete [] ptrStack;
	}
int main()
{
	
	Stack myStack(10);
	string s;
	string *ss=&s;
	cin>>s;
	int z;
	for(z=0; z!=s.length();z++)
	cout<<ss[z];
	
	
}
