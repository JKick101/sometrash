#ifndef STACKBYARRAY_H_INCLUDED
#define STACKBYARRAY_H_INCLUDED

template<typename T>
class myStack
{
private:
    int Size;
    int top;
    T* stackPtr;
public:
    myStack();
    myStack(int s);
    ~myStack();
    bool Push(const T& value);
     T Pop();
     bool isFull();
    bool isEmpty();
    void Show();
};

template<typename T>
myStack<T>::myStack()
    {
        Size=10;
        top=-1;
        stackPtr = new T[Size];
    };
template<typename T>
myStack<T>::myStack(int s):Size(s)
    {
        top=-1;
        stackPtr = new T[Size];
    };
template<typename T>
bool myStack<T>::Push(const T& value)
    {
        if(isFull())
        {
             std::cout<<"Stack is full"<<std::endl;
             return false;
        }
        else
        {
            stackPtr[++top] = value;
            return true;
        }

    };
template<typename T>
T myStack<T>::Pop()
    {
        if(isEmpty())
            std::cout<<"Stack is empty"<<std::endl;
        else
            return stackPtr[top--];
    };
template<typename T>
bool myStack<T>::isFull()
    {
        return top==Size-1;
    };
template<typename T>
bool myStack<T>::isEmpty()
    {
        return top==-1;
    };
template<typename T>
void myStack<T>::Show()
    {
        for(int i=top; i>-1; i--)
            std::cout<<stackPtr[i]<<std::endl;
    };
template<typename T>
myStack<T>::~myStack()
    {
        delete [] stackPtr;
    };

#endif // STACKBYARRAY_H_INCLUDED
