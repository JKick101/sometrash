#include <iostream>
#include <cmath>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

void bubbleSort(int *a,unsigned int SIZE);

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
	cout<<"After insertSort"<<endl;
	bubbleSort(massiv,SIZE);
	
	
	
	
}

void bubbleSort ( int *a,unsigned int SIZE )
{
	int in, out;
	for(out=1; out<SIZE; out++) // out - �������������� ������
		{
			long temp = a[out]; // ����������� ���������� �������
				in = out; // ������ ����������� � out
			while(in>0 && a[in-1] >= temp) // ���� �� ������ ������� �������
				{
					a[in] = a[in-1]; // �������� ������� ������
					in--;
					for (int i = 0 ; i < SIZE; i++)
		cout<<a[i]<<" ";
		cout<<endl;
				 // ������� �� ���� ������� �����
				}
			
			a[in] = temp;
				for (int i = 0 ; i < SIZE; i++)
		cout<<a[i]<<" ";
		cout<<endl; // �������� ���������� �������
		}			
		
		for (int i = 0 ; i < SIZE; i++)
		cout<<a[i]<<" ";
		cout<<endl;
	
}
