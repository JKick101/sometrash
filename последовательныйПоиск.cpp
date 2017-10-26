
//ѕроходит последовательно по всему массиву,при нахождении ключа поиск прекращаетс€
#include <iostream>

int main()
{

    int ar[10]{3,4,5,6,7,9,11,22,5,67};
    int key=22;
    int from=0;
    int to=10;
    for (int i=0; i<10; i++)
        if(ar[i]==key)
    {
        std::cout<<"Number "<<i+1<<std::endl;
        break;
    }

}
