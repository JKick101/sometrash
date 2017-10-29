#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

#include "DNode.h"
#include <iostream>


template<typename T>
class DoublyLinkedList
{
private:
    //��������� �� ������ � ����� ������
    DNode<T>* Front;
    DNode<T>* Rear;

    //������������ ��� ���������� ������� � ��������
    DNode<T>* prevPtr;//��������� �� ���������� ����
    DNode<T>* currPtr;//��������� �� ������� ����

    //����� ���������
    int Size;

    //��������� � ������.������������ Reset
    int Position;

    //�������� ������ �������� � �������� �����
   // Node<T>* GetNode(const T& item, Node<T>* ptrNext =nullptr);
    void FreeDNode(DNode<T>* p);


    //�������� ������ L � �������
    void DCopyList(const DoublyLinkedList<T>& L);


public:

        DoublyLinkedList(const T& item);//����������� �� ���������
        DoublyLinkedList( DoublyLinkedList<T>& L);//����������� �����

        //����������
        ~DoublyLinkedList();

        //�������� ������������
        DoublyLinkedList<T>& operator=( DoublyLinkedList &L);

        //�������� ��������� �����
        int DListSize() const;//������
        bool DListEmpty() const;//���� �� ������

        //������ ����������� ������
        void DReset(int pos=0);//������� �� �������
        void DNextRight();
        void DNextLeft();//������� � ����������
        bool EndOfDList() const;//��������� ��� �� ��������� �����
        int DCurrentPosition() const;//���������� ������� ���������

        //������ �������
        void InsertFrontDList(const T& item);//�  ������ ������
        void InsertRearDList(const T& item);//� �����
        void InsertAtD(const T& item);//� ������� �����
        void InsertAfterDList(const T& item);//����� ��������

        //������ ��������
        DNode<T>* DeleteFrontDList();//�������� �������
        void DeleteAtD();//������� �������

        //���������� ������
        T& Data();

        //������� ������
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
