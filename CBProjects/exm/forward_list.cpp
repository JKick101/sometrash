#include <iostream>
#include <forward_list>
using std::cout;

int main()
{
    //создание итераторов на начало конец и элемент "перед началом"

    std::forward_list<int> fList= {0,1,2,3,4,5,6,8,9};
    std::forward_list<int>::iterator bBeg=fList.before_begin();
    std::forward_list<int>::iterator beg=fList.begin();
    std::forward_list<int>::iterator last=fList.end();

    while (beg!=last)
     if(*beg % 2)
            beg=fList.erase_after(bBeg); //удаление элемента после того на который указывает bBeg и передача итератора на него beg
        else
        {
            bBeg=beg;
        ++beg;
        }
for ( std::forward_list<int>::iterator it=fList.begin();it!=fList.end();it++)
    cout<<*it;
}
