#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "listTemp.h"
#include <iostream>

template<typename T>
class LinkedList
{
private:
    //указатели на начало и конец списка
    Node<T> *Front;
    Node<T>* Rear;

    //используются для извлечения вставки и удаления
    Node<T>* prevPtr;//указатель на предыдущий узел
    Node<T>* currPtr;//указатель на текущий узед

    //число элементов
    int Size;

    //положение в списке.Используется Reset
    int Position;

    //закрытые методы создания и удаления узлов
   // Node<T>* GetNode(const T& item, Node<T>* ptrNext =nullptr);
    void FreeNode(Node<T>* p);


    //копирует список L в текущий
    void CopyList(const LinkedList<T>& L);


public:

        LinkedList();//конструктор по умолчанию
        LinkedList( LinkedList<T>& L);//конструктор копий

        //деструктор
        ~LinkedList();

        //оператор присваивания
        LinkedList<T>& operator=( LinkedList &L);

        //проверка состояния спика
        int ListSize() const;//размер
        bool ListEmpty() const;//пуст ли список

        //методы прохождения списка
        void Reset(int pos=0);//переход по индексу
        void Next();//переход к следующему
        bool EndOfList() const;//указывает был ли достигнут конец
        int CurrentPosition() const;//возвращает текущее положение

        //методы вставки
        void InsertFrontList(const T& item);//в  голову списка
        void InsertRearList(const T& item);//в конец
        void InsertAt(const T& item);//в текущее место
        void InsertAfterList(const T& item);//после текущего

        //методы удаления
        Node<T>* DeleteFrontList();//головной элемент
        void DeleteAt();//текущий элемент

        //возвратить данные
        T& Data();

        //очистка списка
        void ClearList();

};

//создать пустой список
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

//копировать L в текущий список
template<typename T>
void LinkedList<T>::CopyList(const LinkedList<T>& L)
{
    //p указатель на L
    Node<T>* p = L.Front;
    int pos;

    //вставлять каждый элемент из L в конец текущего объекта
    while(p != nullptr)
    {

        InsertRear(p->GetData());
        p = p->NextNode();
    }

    //выход,если список пуст
    if(Position == -1)
        return;

    //переустановить prevPtr currPtr в новом списке
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
        //получаем адрес след узла и удаляем текущий
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

    //если список пуст то выход
    if(Front == nullptr)
        return;

    //если положение задано неверно
    if(pos < 0 || pos > Size-1)
    {
        std::cout<<"RESEt: Wrong pos"<<std::endl;
        return;
    }

    //если позиция ноль это начало
    if(pos == 0)
    {

        //переходим в начало списка
        prevPtr = nullptr;//указатель на предыдущей узел будет нулевой
        currPtr = Front;//указатель на текущий узел
        Position = 0;//позиция у первого узла ноль
    }
    else
        //иначе начинаем  искать со второго узла
    {
        currPtr = Front->NextNode();//переходим ко второму узлу
        prevPtr = Front;//предыдущий узел
        startPos = 1;//позиция второго узла 1
        //
        for(Position = startPos; Position != pos; Position++)
        {
            //передвигаем указатели пока не будет достигнута нужная позиция
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

//вставка item в текущую позицию списка
template<typename T>
void LinkedList<T>::InsertAt(const T& item)
{
    Node<T>* newNode;

    //вставляем либо в начало либо внутрь списка
    if(prevPtr == nullptr)
    {
        //вставляем в начало списка.помещает также
        //узел в пустой список
        newNode = GetNode(item,Front);
        Front = newNode;
    }

        else
            {
            //вставка внутрь списка.помещает сразу после
            //prevPtr
                newNode = GetNode(item);
                prevPtr->InsertAfter(newNode);
            }
    //если prevPtr == Rear то список пуст или
        //хвост непустого списка
    if(prevPtr == Rear)
        {
            Rear = newNode;
            Position = Size;
        }
    //обновить currPtr и увеличить size
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

    //ошибка, если список пустой или конец списка
    if(currPtr == nullptr)
    {
        std::cout<<"Delete Error"<<std::endl;
        return;
    }

    //удалять можно только в начале и в внутри списка
    if(prevPtr == nullptr)
    {
        //сохранить адрес начала но не связывать его
        //если последний узел,присвоить Front значение null
        p = Front;
        Front = Front->NextNode();

    }
    else
        //не свзяывать внутренний узел после prevPtr
        //запомнить адрес
        p = prevPtr->DeleteAfter();

    //если хвост удален,адрес нового хвоста в prevptr
    //а posotoon уменьшается на 1
    if(p == Rear)
    {
        Rear = prevPtr;
        Position--;
    }

    //установить currPtr на последний удаленный узел
    //если р- последний узел в списке
    //currPtr становится равным null
    currPtr = p->NextNode();

    //освободить узел и уменьшить значение Size
    FreeNode(p);
    Size--;

}


//конкатенация двух списков
template<typename T>
void ConcatLists(LinkedList<T>& L1, LinkedList<T>& L2)
{
    //устанавливаем оба списка в начало
    L1.Reset();
    L2.Reset();
    //проходим L2.вставляем его значения в хвост L1
    //
    while(!L2.EndOfList())
    {
        L1.InsertRear(L2.Data());
        L2.next();
    }
}

//поиск максимального элемента в списке
template<typename T>
void FindMax(LinkedList<T> &L)
{
    if(L.ListEmpty())
    {
        std::cout<<"Find Max:List is empty!"<<std::endl;
        return;
    }

    //перемещаемся в начало
    L.Reset();

    //Пускай начальный элемент будет максимумом
    //
    T Max = L.Data();
    int maxLoc = 0;//позиция максимального элемента

    //проходим по списку в поисках большего числа
    for (L.Next(); !L.EndOfList(); L.Next())
        if(L.Data() > Max)
        {
                //если нашли то
                //сохраняем его и его позицию
                Max = L.Data();
                maxLoc = L.CurrentPosition();
        }

        L.Reset(maxLoc);//переходим к максимуму
}

//печать списка L
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


//удаление дубликатов из списка
template<typename T>
void RemoveDuplicates(LinkedList<T>& L)
{
    //текущее положение в списке и значение данных
    int currPos, currValue;

    //перейти к началу списка
    L.Reset();

    //цикл по списку
    while(!L.EndOfList())
    {
        //записать данные текущего положения в списке
        //и это положение
        currValue = L.Data();
        currPos = L.CurrentPosition();

        //перейти к узлу справа
        L.Next();

        //двигаться вперед до конца списка, удаляявсе появления currvalue
        while(!L.EndOfList())
            //если узел удален,текущее положение-следующий узел
        if(L.Data() == currValue)
            L.DeleteAt();
        else
            L.Next();

        //перейти к первому узлу со значением currValue
        //идти вперед
        L.Reset(currPos);
        L.Next();
    }

}





#endif // LINKEDLIST_H_INCLUDED
