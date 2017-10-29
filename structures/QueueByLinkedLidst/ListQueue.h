#ifndef LISTQUEUE_H_INCLUDED
#define LISTQUEUE_H_INCLUDED

#include "linkedList.h"
#include <iostream>



//������� ���������� ������� �� ������ �������� ������


template<typename T>
class Queue
{
private:
    LinkedList<T> *queueList;

public:
    Queue();
    //����������
    void QInsert(const T& elt);
    T QDelete();
    //������ � ������� ��������
    T QFront();

    //������������
    int QLength() const;
    bool QEmpty() const;
    void QClear();
};

template<typename T>
Queue<T>::Queue(){queueList = new LinkedList<T>;};

template<typename T>
void Queue<T>::QInsert(const T& elt)
{
    queueList->InsertRearList(elt);
}


template<typename T>
T Queue<T>::QDelete()
{
    if(queueList->ListEmpty())
        std::cout<<"QDelete: List empty!"<<std::endl;
    else
        return queueList->DeleteFrontList()->GetData();
}

template<typename T>
T Queue<T>::QFront()
{
     if(queueList->ListEmpty())
        std::cout<<"QFront: List empty!"<<std::endl;
    else
    {
        queueList->Reset();
        return queueList->Data();
    }
};
template<typename T>
bool Queue<T>::QEmpty() const
{
    return queueList->ListEmpty();
}
#endif // LISTQUEUE_H_INCLUDED
