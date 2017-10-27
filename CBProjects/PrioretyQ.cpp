#include <iostream>
#include <string>
using namespace std;

class PrioretyQ
{
	private:
		long nElem;
		long *massiv;
		long size;
	public:
		void insert(long);
		long pop();
		bool isFull();
		bool isEmpty();
		void ReadMin();
		PrioretyQ (long s);
		
};

PrioretyQ::PrioretyQ(long s)
{
	size=s;
	nElem=0;
	 massiv=new long[size];
	
}

void PrioretyQ::insert(long temp)
{
	if(!isFull())
	{
	
		int j;
		if(nElem==0)
			massiv[nElem++]=temp;
		else
		{
			for(j=nElem-1;j>=0;j--)
				if(massiv[j]<temp)
					massiv[j+1]=massiv[j];
				else
					break;
		massiv[j+1]=temp;
		nElem++;
		}
	}
	else
		cout<<"Massiv is full";
		
	
}

long PrioretyQ::pop()
{
	if(!isEmpty())
		return massiv[--nElem];
	else
		cout<<"Massiv is Empty";
}

bool PrioretyQ::isFull()
{
	return (nElem==size);
}

bool PrioretyQ::isEmpty()
{
	return (nElem==0);
}

void PrioretyQ::ReadMin()
{
	if(isEmpty())
		cout<<"massiv is empty";
	else
		cout<<massiv[nElem-1];
}

int main()
{
	PrioretyQ P(3);
while(true)
{

	cout<<"\nMenu:\n\t1:Insert\n\t2:Pop\n\t3:Read\n";
	int symbol;
	cin>>symbol;
	
	switch(symbol)
	{
	
		case 1:
			{
				cout<<"Enter value";
				
				long value;
				cin>>value;
				P.insert(value);
			
			}
			break;
		case 2:
			{
				P.pop();
				
			}
			break;
		case 3:
			P.ReadMin();
			break;
	}
}
}
