#ifndef LISTTEMP_H_INCLUDED
#define LISTTEMP_H_INCLUDED

template <typename T>
class Node
{

private:
    Node<T> *nextNode;
    T data;
public:

    Node(const T& item,Node<T> *ptrNext=nullptr);
    void InsertAfter(Node<T>* p);

    Node<T> *DeleteAfter();

    Node<T> *NextNode() const;

    T& GetData();

};




template<typename T>
Node<T>::Node(const T& item,Node<T>* ptrNext)
{
    data = item;
    nextNode = ptrNext;
};


//вставить узел p после текущего узда
template<typename T>
void Node<T>::InsertAfter(Node<T>* p)
{
    p->nextNode = nextNode;
    nextNode = p;
};


template<typename T>
//удалить узел следующий за текущим и вернуть его адрес
Node<T>* Node<T>::DeleteAfter()
{
    //сохранить адрес удаляемого узла
    Node<T> *temp = nullptr;
    //если нет следующего узла возвратить Null
    if((temp = nextNode) == nullptr)
        return nullptr;
    //текущий узел указывает на узел,следующий за temp
    nextNode = temp->nextNode;
    //возвращаем указатель на отсоединенный узел
    return temp;
};

template<typename T>
Node<T>* Node<T>::NextNode() const
{
    return nextNode;
};
template<typename T>
T& Node<T>::GetData()
{
    return data;
};


//Функция создания узла(принимает значение узла и указатель на следующий за ним элемент(по умолчанию null))
//возвращает указатель на новый узел
template<typename T>
Node<T>* GetNode(const T& item,Node<T>* nextPtr=nullptr)
{
    Node<T>* newNode;//указатель на узел
    newNode = new Node<T>(item,nextPtr);//создание динамического узла
    if(newNode == nullptr)
        std::cout<<"Null  memory"<<std::endl;
    else
        return newNode;//возвращаем указатель на узел
};


//вставка элемента в начало списка(принимает указатель на первый узел и значение нового узла)
template<typename T>
void InsertFront(Node<T>* &head, T item)
{
    //Node<T>* &head - head сам по себе евляется указателем на Node а ссылка чтобы не возвращать его значение
    //создание нового узла, чтобы он указывал на
    //первоначальную голову списка
    //изменение головы списка
    head = GetNode(item,head);
};


//печать связанного списка
/*template<typename T>
void PrintList(Node<T>* head)
{
    Node<T>* currPtr = head;//начинаем с головы
    //проходим все узлы
    while(currPtr != nullptr)
    {
        std::cout<<currPtr->GetData()<<" kk";
        currPtr = currPtr->NextNode();//следующий узел
    }

};*/

//вставляет новый узел в конец списка(принимает начало списка и значение нового узла)
template<typename T>
void InsertRear(Node<T>* head,const T& item)
{
    Node<T>* newNode;
    Node<T>* currPtr = head;


    if (currPtr == nullptr )//если список изначально пуст то просто делаем новый узел начальным
        InsertFront(head,item);
    else
    {
        while(currPtr->NextNode() != nullptr)//проходим до последнего элемента списка
            currPtr=currPtr->NextNode();
        newNode = GetNode(item);//создаем новый узел
        currPtr->InsertAfter(newNode);//вставляем новый узел после последнего элемента
    }



}


//удаление первого узла в списке
template<typename T>
void DeleteFront(Node<T>* &head)
{
    if(head != nullptr)
    {
        Node<T>* p = head;//сохраняем указатель на гоолову
        head = head->NextNode();//сдвигаем голову к следующему узлу
        //delete p;//удаляем узел который был в голове
    }
}

//удаляет узел с соответствующим ключом
template<typename T>
void Delete(Node<T>* &head, T key)
{

    Node<T>* currptr = head;//указатель на текущий
    Node<T>* prevNode = nullptr;//на предыдущий узел

    //проходим по списку пока не найдем узел с заданным ключом или не достигнем конца
    while(currptr != nullptr && currptr->GetData() != key)
    {
        prevNode = currptr;
        currptr = currptr->NextNode();
    }

    //если указатель на текущий узел null значит в списке нет такого ключа
    if(currptr != nullptr )
    {
        //если предыдущий узел null значит значение с ключом в первом узле
        if(prevNode == nullptr)
            DeleteFront(head);//тогда просто удаляем узел в голове
        else
            {
                //если указатель на предущий узел не null значит следующий за ним узел
                //содержит ключ,поэтому удаляем узел следующий за prevNode
                prevNode->DeleteAfter();
            }
        //delete currptr;

    }
}


//функция удаляет список
template<typename T>
void ClearList(Node<T>* &head)
{
    Node<T>* currPtr;//текущий узел
    Node<T>* nextNode;//следующий узел

    currPtr=head;

    //проходим по списку
    //и удаляем узлы
    while(currPtr != nullptr)
    {
        nextNode = currPtr->NextNode();//сохраняем указатель на след узел
        delete currPtr;//удаляем текущий
        currPtr = nextNode;//переходим к следующему узлу
    }
    head=nullptr;

}

//вставить item в упорядоченный список
template<typename T>
void InsertOrder(Node<T>* &head, T& item)
{
   //currPtr пробегаает по списку
   Node<T>* currPtr;
   Node<T>* newNode;
   Node<T>* prevPtr;

   //prevPtr==Null указывает на совпадение в начале списка

   prevPtr = nullptr;
   currPtr = head;


   //цикл по списку и поиск точки вставки
   while(currPtr != nullptr)
   {
       //точка вставки найдена если item<data
       if(item<currPtr->GetData())
        break;

       prevPtr = currPtr;
       currPtr = currPtr->NextNode();
   }
   //вставка
   if(prevPtr == nullptr)
    InsertFront(head,item);
   else
   {
       //вставить новый узел после предыдущего
       newNode = GetNode(item);
       prevPtr->InsertAfter(newNode);
   }
}

//сортировка
template<typename T>
void LinkSort(T a[], int N)
{
    Node<T>* ordlist = nullptr;
    Node<T>* currPtr;


    //вставлять элементы из массива в список с упорядочиванием
    for(int i = 0;i<N;i++)
        InsertOrder(ordlist,a[i]);

    //сканировать список и копировать данные в массив
    currPtr = ordlist;
    int i = 0;
    //данные в узал отсортированны,теперь копируем их в массив
    while(currPtr != nullptr)
    {
        a[i++] = currPtr->GetData();
        currPtr = currPtr->NextNode();
    }

    //удалить все узлы, созданные в упорядоченном списке
    ClearList(ordlist);
}
#endif // LISTTEMP_H_INCLUDED
