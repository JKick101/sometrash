#include <iostream>
#include <forward_list>
#include <vector>
using std::cout;
using std::vector;
int main()
{
    //������� ������ �������� � ������� � �������� ���������

    vector<int> vec= {0,1,2,3,4,5,6,8,9};
    vector<int>::iterator beg=vec.begin();

    while (beg!=vec.end())
     if(*beg % 2)
     {
        beg=vec.insert(beg,*beg); //��������� �������  ����� ��������� �� ������� ��������� ��������
        //� ���������� �������� �� ���� �������
        beg+=2;//������� ��� �� ���������� 2 ����� ����������� ����� ����� ��� ������ �������
        }
        else
            beg=vec.erase(beg); //������� ������� � ���������� �������� �� ���������

for ( vector<int>::iterator it=vec.begin();it!=vec.end();it++)
    cout<<*it;
}
