#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::vector;
using std::string;
using namespace std;
int main()

{
       /* vector<int> v={0,10,10,10,30,30,43};
        cout<<accumulate(v.cbegin(),v.cend(),0)<<std::endl; //суммирует все элементы вектора начиная с итератора начала и до
        //итератора конца, начальное знаечние к которому прибавляется все равно 0
*/
       vector<string> mas1={"Hello ","me ","here"};
        cout<<accumulate(mas1.cbegin(),mas1.cend(),string(""));

       /* vector<string> mas2={"Hello ","me ","here","zzzz"};
        if (equal(mas1.cbegin(),mas1.cend(),mas2.cbegin())) //если вектор 2 содержит подвектор 1 то да инече нет
            cout<<"\nYes!";
        else
            cout<<"\nNo";

      /* fill(mas1.begin(),mas1.end(),string("zzz"));// меняет все элементы вектора на zzz
        for(vector<string>::iterator it=mas1.begin();it!=mas1.end();it++)
            cout<<*it<<" ";
      */  vector<int> vec(1);//обязательно должен быть не пустой вектор
        fill_n(vec.begin(),1,25);//иначе тут будет ошибка и крах программы(функция записывает значения начиная с определе
         //ленного места на определенное количество)
        for(vector<int>::iterator it=vec.begin();it!=vec.end();it++)
            cout<<*it<<"\n";


      /*  vector<int> vect;
        auto it=back_inserter(vec);
        *it=42;


        //copy()
        int a1[]={0,1,2,3,4,5,6,7,8,9};
        int a2[sizeof(a1)/sizeof(*a1)];
        std::copy(std::begin(a1),std::end(a1),a2); //копирует значения с итератора начала до итератора конца в массив а2
        for(auto it=std::begin(a2);it!=std::end(a2);it++)
            cout<<*it;
        replace(std::begin(a2),std::end(a2),6,000);//проходит по диапазону массива(первые 2 итератора) и заменяет все
        //значения в нем=6 на 000
        for(auto it=std::begin(a2);it!=std::end(a2);it++)
            cout<<*it;

            vector<string> mas11={"Hello ","me ","here"};
            sort(mas11.begin(),mas11.end());
            for(vector<string>::iterator it=mas11.begin();it!=mas11.end();it++)
            cout<<*it<<"\n";

*/
}
