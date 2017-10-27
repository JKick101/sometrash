#include <iostream>
#include <cmath>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

void bubbleSort(int *massiv,unsigned int SIZE);

int main ()
{
	cout<<"Enter max value:";
	unsigned int max;
	cin>>max;
	cout<<endl;
	cout<<"Enter SIZE of massiv:";
	unsigned int SIZE;
	cin>>SIZE;
	int massiv[SIZE];
	for (int i = 0 ; i < SIZE; i++)
	{
	
	massiv[i]=rand() % max + 1;
	cout<<massiv[i]<<" ";
	}
	cout<<"After bubbleSort"<<endl;
	bubbleSort(massiv,SIZE);
	
	
	
	
}

void bubbleSort ( int *massiv,unsigned int SIZE )
{
	int i,j;
	for ( i=SIZE-1; i>0; i--)
		for( j=0; j<i; j++)
		if (massiv[j]>massiv[j+1])
		{
			long temp;
			temp=massiv[j];
			massiv[j]=massiv[j+1];
			massiv[j+1]=temp;
		}
		
		for (int i = 0 ; i < SIZE; i++)
		cout<<massiv[i]<<" ";
		cout<<endl;
	
}
