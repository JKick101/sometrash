#include <iostream>
#include <forward_list>
#include <vector>
using std::cout;
using std::vector;
int main()
{
    //удаляет четные элементы в векторе а нечетные дублирует

    vector<int> vec= {0,1,2,3,4,5,6,8,9};
    vector<int>::iterator beg=vec.begin();

    while (beg!=vec.end())
     if(*beg % 2)
     {
        beg=vec.insert(beg,*beg); //вставляет элемент  ПЕРЕД элементом на который указывает итератор
        //и возвращает итератор на этот элемент
        beg+=2;//поэтому тут мы прибавляем 2 чтобы перескочить через через наш старый элемент
        }
        else
            beg=vec.erase(beg); //удаляет элемент и возвращает итератор на следующий

for ( vector<int>::iterator it=vec.begin();it!=vec.end();it++)
    cout<<*it;
}
