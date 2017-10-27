#include <iostream>

using namespace std;


class Stack
{
private:
		char* ptrStack; 
		int Size; 
		int top; 
		
public:
	Stack(int SIZE);
	Stack();
	bool empty();
	bool full();
	void push(char value);
	void pop(char value);
	void readStack();
	~Stack();
};


Stack::Stack()
		{
			Size=10;
			ptrStack=new char[Size];
			top=-1;
			
		}

  Stack::Stack(int SIZE)
		{
			Size=SIZE;
			ptrStack=new char[Size];
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
	
		
		void Stack::push(char value)
		{
			if (!(top==Size-1))
			ptrStack[++top]=value;
			else cout<<"Stack is full";
		}
		
		void Stack::pop(char value)
		{
			if((value-2)==ptrStack[top] || (value-1)==ptrStack[top])
				if(top!=-1)
					--top;
				else
					cout<<"Stack is empty";
			else
				cout<<"Incorrect Brackets!!";
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
	
	
int balance(char *, Stack &);	
	
int main()
{
	
	char str[255];
	cin>>str;
	
	Stack Balance;
	int code;
	code=balance(str,Balance);
	switch(code)
		{
			case 0:
				cout<<"All good";
				break;
			case -1:
				cout<<"Wrong Balance";
				break;
		}
	
	}	
	
int balance(char *s, Stack &Balance)
{
	
	for(int i=0;s[i];i++)
	{
		
		switch(s[i])
			{
				case '[':
				case '(':
				case '{':
					Balance.push(s[i]);
					break;
				case '}':
				case ']':
				case ')':
					Balance.pop(s[i]);
					break;
			}
			
	}
	
	if(Balance.empty())
	return 0;
	else 
	return -1;
	
}	
	
