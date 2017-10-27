#include <iostream>
#include <forward_list>
#include <string>

using std::cout;
using std::cin;
using std::forward_list;
using std::string;

void func(forward_list<string>&,const string&,const string&);

int main()
{
    string str1,str2;
    cout<<"Enter two strings\n";
    cin>>str1>>str2;
    forward_list<string> mylist={"Hello","i","am","Ilya","am"};
    func(mylist,str1,str2);
    for(forward_list<string>::iterator it=mylist.begin();it!=mylist.end();it++)
        cout<<*it<<" ";

}

void func(forward_list<string>& newList,const string& str1,const string& str2)
{
    for(forward_list<string>::iterator it=newList.begin();it!=newList.end();it++)
        if(*it==str1)
            newList.insert_after(it,str2);

}
