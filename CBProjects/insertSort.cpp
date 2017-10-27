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
	for(out=1; out<SIZE; out++) // out - разделительный маркер
		{
			long temp = a[out]; // Скопировать помеченный элемент
				in = out; // Начать перемещения с out
			while(in>0 && a[in-1] >= temp) // Пока не найден меньший элемент
				{
					a[in] = a[in-1]; // Сдвинуть элемент вправо
					in--;
					for (int i = 0 ; i < SIZE; i++)
		cout<<a[i]<<" ";
		cout<<endl;
				 // Перейти на одну позицию влево
				}
			
			a[in] = temp;
				for (int i = 0 ; i < SIZE; i++)
		cout<<a[i]<<" ";
		cout<<endl; // Вставить помеченный элемент
		}			
		
		for (int i = 0 ; i < SIZE; i++)
		cout<<a[i]<<" ";
		cout<<endl;
	
}
