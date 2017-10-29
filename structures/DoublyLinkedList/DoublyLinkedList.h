#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

#include "DNode.h"
#include <iostream>


template<typename T>
class DoublyLinkedList
{
private:
    //указатели на начало и конец списка
    DNode<T>* Front;
    DNode<T>* Rear;

    //используются для извлечения вставки и удаления
    DNode<T>* prevPtr;//указатель на предыдущий узел
    DNode<T>* currPtr;//указатель на текущий узед

    //число элементов
    int Size;

    //положение в списке.Используется Reset
    int Position;

    //закрытые методы создания и удаления узлов
   // Node<T>* GetNode(const T& item, Node<T>* ptrNext =nullptr);
    void FreeDNode(DNode<T>* p);


    //копирует список L в текущий
    void DCopyList(const DoublyLinkedList<T>& L);


public:

        DoublyLinkedList(const T& item);//конструктор по умолчанию
        DoublyLinkedList( DoublyLinkedList<T>& L);//конструктор копий

        //деструктор
        ~DoublyLinkedList();

        //оператор присваивания
        DoublyLinkedList<T>& operator=( DoublyLinkedList &L);

        //проверка состояния спика
        int DListSize() const;//размер
        bool DListEmpty() const;//пуст ли список

        //методы прохождения списка
        void DReset(int pos=0);//переход по индексу
        void DNextRight();
        void DNextLeft();//переход к следующему
        bool EndOfDList() const;//указывает был ли достигнут конец
        int DCurrentPosition() const;//возвращает текущее положение

        //методы вставки
        void InsertFrontDList(const T& item);//в  голову списка
        void InsertRearDList(const T& item);//в конец
        void InsertAtD(const T& item);//в текущее место
        void InsertAfterDList(const T& item);//после текущего

        //методы удаления
        DNode<T>* DeleteFrontDList();//головной элемент
        void DeleteAtD();//текущий элемент

        //возвратить данные
        T& Data();

        //очистка списка
        void ClearDList();

};


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const T& item)
{
    Front = Rear = new DNode<T>(item);
    prevPtr = currPtr = nullptr;
    Size = 1;
    Position = 0;
};

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{

}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList( DoublyLinkedList<T>& L)
{


}


template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=( DoublyLinkedList &L)
{


}


template<typename T>
int DoublyLinkedList<T>::DListSize() const
{
    return Size;
}


template<typename T>
bool DoublyLinkedList<T>::DListEmpty() const
{
       return Front == Rear && Front->NextNodeRight() == Front && Front->NextNodeLeft()  == Front;
}


template<typename T>
 void DoublyLinkedList<T>::DReset(int pos=0)
 {
     if(DListEmpty())
     {
        std::cout<<"Reset:List is empty!"<<std::endl;
        return;
     }
     if(pos<0 || pos > Size-1)
     {
         std::cout<<"Reset:Wrong Position"<<std::endl;
         return;
     }
     if(pos == 0)
     {
        currPtr = Front;
        prevPtr = Front;
        Position = 0;
     }
     else
     {
         currPtr = Front;
         prevPtr = Front->NextNodeLeft();
     if(pos<(Size-1)/2)
     for(Position = 0;Position < pos; Position++)
     {
        prevPtr = currPtr;
        currPtr = currPtr->NextNodeRight();
     }
     else
        for(Position = Size; Position>pos; Position-- )
        {
            prevPtr = prevPtr->NextNodeLeft();
            currPtr =currPtr->NextNodeLeft();
        }
     }
 };


 template<typename T>
 void DoublyLinkedList<T>::DNextRight()
 {
     if(currPtr != nullptr && prevPtr != nullptr)
     {
         prevPtr = currPtr;
         currPtr = currPtr->NextNodeRight();
         Position++;
     }
     if(Position == Size)
        Position = 0;
 }


 template<typename T>
  void DoublyLinkedList<T>::DNextLeft()
 {
     if(currPtr != nullptr && prevPtr != nullptr)
     {
         prevPtr = currPtr;
         currPtr = currPtr->NextNodeLeft();
         Position--;
     }
     if(Position < 0)
        Position = Size-1;
 }



 template<typename T>
 bool DoublyLinkedList<T>::EndOfDList() const
 {
    if(currPtr)

 }



template<typename T>
 int DoublyLinkedList<T>::DCurrentPosition() const
 {

     return Position;
 }



 template<typename T>
  void DoublyLinkedList<T>::InsertFrontDList(const T& item)
  {
      Front = GetDNode(item,Front->NextNodeLeft(),Front->NextNodeRight());
  }


 template<typename T>
 T& DoublyLinkedList<T>::Data()
 {
     if(DListEmpty())
        std::cout<<"Data:List is empty"<<std::endl;
     else
        return currPtr->GetData();
 }
template<typename T>
void PrintDList( DoublyLinkedList<T>& List )
{
    for(List.DReset();!List.EndOfDList();List.DNextRight())
        std::cout<<List.Data()<<" ";

}
#endif // DOUBLYLINKEDLIST_H_INCLUDED
