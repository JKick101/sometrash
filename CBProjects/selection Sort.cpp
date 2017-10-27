#include <iostream>
#include <cmath>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

void selectionSort(int *massiv,unsigned int SIZE);

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
	cout<<"After selectionSort"<<endl;
	selectionSort(massiv,SIZE);
	
	
	
	
}

void selectionSort ( int *massiv,unsigned int SIZE )
{
	int i,j;
	for ( i=0; i<SIZE-1; i++)
	{
		int min=i;
		for( j=i; j<SIZE; j++)
		if (massiv[j]<massiv[min])
		{
			long temp;
			temp=massiv[min];
			massiv[min]=massiv[j];
			massiv[j]=temp;
		}
		
	}	
		for (int i = 0 ; i < SIZE; i++)
		cout<<massiv[i]<<" ";
		cout<<endl;
	
}
