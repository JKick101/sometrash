#include <iostream>

int * foo(){
    int a[5]{ 1, 2, 3, 4, 5 }; //в данном случае необходимо использовать кучу а не стек,т.к при
    //выходе из функции стек поменяется и значения будут рандомными
    int* ptr = a;
    return ptr;
}

int main(){
    int *ptr = foo();
    for (int i = 0; i < 5; i++)
        std::cout << ptr[i];
    return 0;
}
