#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "listTemp.h"
#include <iostream>

template<typename T>
class LinkedList
{
private:
    //��������� �� ������ � ����� ������
    Node<T> *Front;
    Node<T>* Rear;

    //������������ ��� ���������� ������� � ��������
    Node<T>* prevPtr;//��������� �� ���������� ����
    Node<T>* currPtr;//��������� �� ������� ����

    //����� ���������
    int Size;

    //��������� � ������.������������ Reset
    int Position;

    //�������� ������ �������� � �������� �����
   // Node<T>* GetNode(const T& item, Node<T>* ptrNext =nullptr);
    void FreeNode(Node<T>* p);


    //�������� ������ L � �������
    void CopyList(const LinkedList<T>& L);


public:

        LinkedList();//����������� �� ���������
        LinkedList( LinkedList<T>& L);//����������� �����

        //����������
        ~LinkedList();

        //�������� ������������
        LinkedList<T>& operator=( LinkedList &L);

        //�������� ��������� �����
        int ListSize() const;//������
        bool ListEmpty() const;//���� �� ������

        //������ ����������� ������
        void Reset(int pos=0);//������� �� �������
        void Next();//������� � ����������
        bool EndOfList() const;//��������� ��� �� ��������� �����
        int CurrentPosition() const;//���������� ������� ���������

        //������ �������
        void InsertFrontList(const T& item);//�  ������ ������
        void InsertRearList(const T& item);//� �����
        void InsertAt(const T& item);//� ������� �����
        void InsertAfterList(const T& item);//����� ��������

        //������ ��������
        Node<T>* DeleteFrontList();//�������� �������
        void DeleteAt();//������� �������

        //���������� ������
        T& Data();

        //������� ������
        void ClearList();

};

//������� ������ ������
template<typename T>
LinkedList<T>::LinkedList():Front(nullptr),Rear(nullptr),
        prevPtr(nullptr),currPtr(nullptr),Size(0),Position(-1){};


template<typename T>
LinkedList<T>::LinkedList( LinkedList<T>& L)
{
    Front = nullptr;
    Rear = nullptr;
    prevPtr = nullptr;
    currPtr = nullptr;
    Size =0;
    Position = -1;

    LinkedList<T> List;

    for(L.Reset();!L.EndOfList();L.Next())
        {
            if(List.Front==nullptr)
            {
                   InsertFront(List.Front,L.Data());
                    List.Rear = List.Front;
                    List.Size++;
            }
            else
               {
                   List.Size++;
                   List.Front = GetNode(L.Data(),List.Front);
               }
        }


        for(List.Reset();!List.EndOfList();List.Next())
        {
            if(Front==nullptr)
            {
                   InsertFront(Front,List.Data());
                    Rear = Front;
                    Size++;
            }
            else
               {
                   Size++;
                   Front = GetNode(List.Data(),Front);
               }
        }

}

template<typename T>
LinkedList<T>::~LinkedList()
{
    currPtr = Front;
    prevPtr = nullptr;
    for(this->Reset();!this->EndOfList();this->Next())
    {

        prevPtr = currPtr;
        currPtr = currPtr->NextNode();
        delete prevPtr;
    }
    Front=Rear=nullptr;
    Size = 0;
    Position = -1;
    //std::cout<<"Bye";
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=( LinkedList &L)
{
    LinkedList<T> List;

    for(L.Reset();!L.EndOfList();L.Next())
        {
            if(List.Front==nullptr)
            {
                   InsertFront(List.Front,L.Data());
                    List.Rear = List.Front;
                    List.Size++;
            }
            else
               {
                   List.Size++;
                   List.Front = GetNode(L.Data(),List.Front);
               }
        }


        for(List.Reset();!List.EndOfList();List.Next())
        {
            if(Front==nullptr)
            {
                   InsertFront(Front,List.Data());
                    Rear = Front;
                    Size++;
            }
            else
               {
                   Size++;
                   Front = GetNode(List.Data(),Front);
               }
        }


}

template<typename T>
 int LinkedList<T>::CurrentPosition() const
 {
     return Position;
 }

template<typename T>
bool LinkedList<T>::ListEmpty() const
{
    return Front==Rear && Front==nullptr;
}

template<typename T>
int LinkedList<T>::ListSize() const
{
    return Size;
}


template<typename T>
bool LinkedList<T>::EndOfList() const
{
    if((Front != Rear) && (currPtr == nullptr) && (prevPtr != nullptr))
        return true;
    else
        return false;
}

template<typename T>
void LinkedList<T>::InsertFrontList(const T& item)
{
    if(ListEmpty())
        {std::cout<<"List is Empty<inserting firs element...";
        Front = GetNode(item,Front);}
    else
        Front = GetNode(item,Front);
        Size++;

}
template<typename T>
void LinkedList<T>::InsertRearList(const T& item)
{
   Node<T> *newNode=GetNode(item);
   currPtr = Front;
   prevPtr = nullptr;
   if(ListEmpty())
    Front = GetNode(item,Front);
   else
   {
   while(currPtr != nullptr)
   {
        prevPtr = currPtr;
        currPtr = currPtr->NextNode();
   }
   prevPtr->InsertAfter(newNode);
   Rear = newNode;
   }
   Size++;
}

/*template<typename T>
void LinkedList<T>::InsertAtList(const T& item)
{
   Node<T>* newNode = GetNode(item);
   if(ListEmpty())
        Front==Rear==newNode;
   else
   {
    if(currPtr == nullptr || prevPtr == nullptr)
        {Front == newNode;
        newNode->NextNode() = currPtr;}
        else
        {
            prevPtr->NextNode() = newNode;
            newNode->NextNode() = currPtr;
        }
   }
   Size++;

}*/

template<typename T>
void LinkedList<T>::InsertAfterList(const T& item)
{
    Node <T>* newNode = GetNode(item);
    if(ListEmpty())
        Front = Rear = newNode;
    else
        if(currPtr == nullptr)
        {
            Front->InsertAfter(newNode);
        }
        else
        {
            //Node<T>* temp = currPtr->NextNode();
            currPtr->InsertAfter(newNode);
            //newNode->NextNode() = temp->NextNode();
        }
        Size++;

}

//���������� L � ������� ������
template<typename T>
void LinkedList<T>::CopyList(const LinkedList<T>& L)
{
    //p ��������� �� L
    Node<T>* p = L.Front;
    int pos;

    //��������� ������ ������� �� L � ����� �������� �������
    while(p != nullptr)
    {

        InsertRear(p->GetData());
        p = p->NextNode();
    }

    //�����,���� ������ ����
    if(Position == -1)
        return;

    //�������������� prevPtr currPtr � ����� ������
    prevPtr = nullptr;
    currPtr = Front;
    for ( pos = 0; pos != Position; pos++)
    {
        prevPtr = currPtr;
        currPtr = currPtr->NextNode();
    }
}

template<typename T>
void LinkedList<T>::ClearList()
{
    Node<T>* currPosition;
    Node<T>* nextPosition;

    currPosition = Front;
    while(currPosition != nullptr)
    {
        //�������� ����� ���� ���� � ������� �������
        nextPosition = currPosition->NextNode();
        FreeNode(currPosition);
        currPosition = nextPosition;
    }
    Front = Rear = nullptr;
    prevPtr = currPtr =nullptr;
    Size = 0;
    Position = -1;
}

template<typename T>
void LinkedList<T>::Reset(int pos)
{
    int startPos;

    //���� ������ ���� �� �����
    if(Front == nullptr)
        return;

    //���� ��������� ������ �������
    if(pos < 0 || pos > Size-1)
    {
        std::cout<<"RESEt: Wrong pos"<<std::endl;
        return;
    }

    //���� ������� ���� ��� ������
    if(pos == 0)
    {

        //��������� � ������ ������
        prevPtr = nullptr;//��������� �� ���������� ���� ����� �������
        currPtr = Front;//��������� �� ������� ����
        Position = 0;//������� � ������� ���� ����
    }
    else
        //����� ��������  ������ �� ������� ����
    {
        currPtr = Front->NextNode();//��������� �� ������� ����
        prevPtr = Front;//���������� ����
        startPos = 1;//������� ������� ���� 1
        //
        for(Position = startPos; Position != pos; Position++)
        {
            //����������� ��������� ���� �� ����� ���������� ������ �������
            prevPtr = currPtr;
            currPtr = currPtr->NextNode();
        }
    }
}

template<typename T>
void LinkedList<T>::Next()
{

    if(currPtr != nullptr)
    {
        prevPtr = currPtr;
        currPtr = currPtr->NextNode();
        Position++;
    }

}

//
template<typename T>
 T& LinkedList<T>::Data()
{
    //
    if(Size == 0 || currPtr == nullptr)
    {
        std::cout<<"Data:Wrong link"<<std::endl;
        //return;
    }
    return currPtr->GetData();
}

//������� item � ������� ������� ������
template<typename T>
void LinkedList<T>::InsertAt(const T& item)
{
    Node<T>* newNode;

    //��������� ���� � ������ ���� ������ ������
    if(prevPtr == nullptr)
    {
        //��������� � ������ ������.�������� �����
        //���� � ������ ������
        newNode = GetNode(item,Front);
        Front = newNode;
    }

        else
            {
            //������� ������ ������.�������� ����� �����
            //prevPtr
                newNode = GetNode(item);
                prevPtr->InsertAfter(newNode);
            }
    //���� prevPtr == Rear �� ������ ���� ���
        //����� ��������� ������
    if(prevPtr == Rear)
        {
            Rear = newNode;
            Position = Size;
        }
    //�������� currPtr � ��������� size
    currPtr = newNode;
    Size++;

}

template<typename T>
Node<T>* LinkedList<T>::DeleteFrontList()
{
    Node<T>* DeleteNode = Front;
    DeleteFront(Front);
    return DeleteNode;

}

template<typename T>
void LinkedList<T>::FreeNode(Node<T>* p)
{
    delete p;
}
//
template<typename T>
void LinkedList<T>::DeleteAt()
{
    Node<T>* p;

    //������, ���� ������ ������ ��� ����� ������
    if(currPtr == nullptr)
    {
        std::cout<<"Delete Error"<<std::endl;
        return;
    }

    //������� ����� ������ � ������ � � ������ ������
    if(prevPtr == nullptr)
    {
        //��������� ����� ������ �� �� ��������� ���
        //���� ��������� ����,��������� Front �������� null
        p = Front;
        Front = Front->NextNode();

    }
    else
        //�� ��������� ���������� ���� ����� prevPtr
        //��������� �����
        p = prevPtr->DeleteAfter();

    //���� ����� ������,����� ������ ������ � prevptr
    //� posotoon ����������� �� 1
    if(p == Rear)
    {
        Rear = prevPtr;
        Position--;
    }

    //���������� currPtr �� ��������� ��������� ����
    //���� �- ��������� ���� � ������
    //currPtr ���������� ������ null
    currPtr = p->NextNode();

    //���������� ���� � ��������� �������� Size
    FreeNode(p);
    Size--;

}


//������������ ���� �������
template<typename T>
void ConcatLists(LinkedList<T>& L1, LinkedList<T>& L2)
{
    //������������� ��� ������ � ������
    L1.Reset();
    L2.Reset();
    //�������� L2.��������� ��� �������� � ����� L1
    //
    while(!L2.EndOfList())
    {
        L1.InsertRear(L2.Data());
        L2.next();
    }
}

//����� ������������� �������� � ������
template<typename T>
void FindMax(LinkedList<T> &L)
{
    if(L.ListEmpty())
    {
        std::cout<<"Find Max:List is empty!"<<std::endl;
        return;
    }

    //������������ � ������
    L.Reset();

    //������ ��������� ������� ����� ����������
    //
    T Max = L.Data();
    int maxLoc = 0;//������� ������������� ��������

    //�������� �� ������ � ������� �������� �����
    for (L.Next(); !L.EndOfList(); L.Next())
        if(L.Data() > Max)
        {
                //���� ����� ��
                //��������� ��� � ��� �������
                Max = L.Data();
                maxLoc = L.CurrentPosition();
        }

        L.Reset(maxLoc);//��������� � ���������
}

//������ ������ L
template<typename T>
void PrintList(LinkedList<T>& L)
{
       // L.Reset();
        for(/*int i = 0*/L.Reset();/*i !=*/! L.EndOfList();L.Next())
        {
            std::cout<<L.Data()<<" ";
            //L.Next();
        }

}


//�������� ���������� �� ������
template<typename T>
void RemoveDuplicates(LinkedList<T>& L)
{
    //������� ��������� � ������ � �������� ������
    int currPos, currValue;

    //������� � ������ ������
    L.Reset();

    //���� �� ������
    while(!L.EndOfList())
    {
        //�������� ������ �������� ��������� � ������
        //� ��� ���������
        currValue = L.Data();
        currPos = L.CurrentPosition();

        //������� � ���� ������
        L.Next();

        //��������� ������ �� ����� ������, ��������� ��������� currvalue
        while(!L.EndOfList())
            //���� ���� ������,������� ���������-��������� ����
        if(L.Data() == currValue)
            L.DeleteAt();
        else
            L.Next();

        //������� � ������� ���� �� ��������� currValue
        //���� ������
        L.Reset(currPos);
        L.Next();
    }

}





#endif // LINKEDLIST_H_INCLUDED
