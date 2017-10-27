#include <iostream>
#include <thread>

class bac
{
public:
    //int &i;
    //func (int& i): i(i){}
    void op()
    {
        for (unsigned j = 0;j < 10000000; j++)
        {
           std::cout<<j;
        }
    }
};


int main()
{
    //int some_local_state = 0;
    //func my_func(some_local_state);
    bac b;
    std::thread t{b}::bac;
    //std::cout<<"it's first thread";
    t.detach();

}
