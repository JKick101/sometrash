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
    ~myStack()
    {
        delete [] stackPtr;
    };
    void Push(const T& value);
     T Pop();
     bool isFull();
    bool isEmpty();
    void Show();
};

#endif // STACKBYARRAY_H_INCLUDED
