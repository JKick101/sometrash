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


//�������� ���� p ����� �������� ����
template<typename T>
void Node<T>::InsertAfter(Node<T>* p)
{
    p->nextNode = nextNode;
    nextNode = p;
};


template<typename T>
//������� ���� ��������� �� ������� � ������� ��� �����
Node<T>* Node<T>::DeleteAfter()
{
    //��������� ����� ���������� ����
    Node<T> *temp = nullptr;
    //���� ��� ���������� ���� ���������� Null
    if((temp = nextNode) == nullptr)
        return nullptr;
    //������� ���� ��������� �� ����,��������� �� temp
    nextNode = temp->nextNode;
    //���������� ��������� �� ������������� ����
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


//������� �������� ����(��������� �������� ���� � ��������� �� ��������� �� ��� �������(�� ��������� null))
//���������� ��������� �� ����� ����
template<typename T>
Node<T>* GetNode(const T& item,Node<T>* nextPtr=nullptr)
{
    Node<T>* newNode;//��������� �� ����
    newNode = new Node<T>(item,nextPtr);//�������� ������������� ����
    if(newNode == nullptr)
        std::cout<<"Null  memory"<<std::endl;
    else
        return newNode;//���������� ��������� �� ����
};


//������� �������� � ������ ������(��������� ��������� �� ������ ���� � �������� ������ ����)
template<typename T>
void InsertFront(Node<T>* &head, T item)
{
    //Node<T>* &head - head ��� �� ���� �������� ���������� �� Node � ������ ����� �� ���������� ��� ��������
    //�������� ������ ����, ����� �� �������� ��
    //�������������� ������ ������
    //��������� ������ ������
    head = GetNode(item,head);
};


//������ ���������� ������
/*template<typename T>
void PrintList(Node<T>* head)
{
    Node<T>* currPtr = head;//�������� � ������
    //�������� ��� ����
    while(currPtr != nullptr)
    {
        std::cout<<currPtr->GetData()<<" kk";
        currPtr = currPtr->NextNode();//��������� ����
    }

};*/

//��������� ����� ���� � ����� ������(��������� ������ ������ � �������� ������ ����)
template<typename T>
void InsertRear(Node<T>* head,const T& item)
{
    Node<T>* newNode;
    Node<T>* currPtr = head;


    if (currPtr == nullptr )//���� ������ ���������� ���� �� ������ ������ ����� ���� ���������
        InsertFront(head,item);
    else
    {
        while(currPtr->NextNode() != nullptr)//�������� �� ���������� �������� ������
            currPtr=currPtr->NextNode();
        newNode = GetNode(item);//������� ����� ����
        currPtr->InsertAfter(newNode);//��������� ����� ���� ����� ���������� ��������
    }



}


//�������� ������� ���� � ������
template<typename T>
void DeleteFront(Node<T>* &head)
{
    if(head != nullptr)
    {
        Node<T>* p = head;//��������� ��������� �� �������
        head = head->NextNode();//�������� ������ � ���������� ����
        //delete p;//������� ���� ������� ��� � ������
    }
}

//������� ���� � ��������������� ������
template<typename T>
void Delete(Node<T>* &head, T key)
{

    Node<T>* currptr = head;//��������� �� �������
    Node<T>* prevNode = nullptr;//�� ���������� ����

    //�������� �� ������ ���� �� ������ ���� � �������� ������ ��� �� ��������� �����
    while(currptr != nullptr && currptr->GetData() != key)
    {
        prevNode = currptr;
        currptr = currptr->NextNode();
    }

    //���� ��������� �� ������� ���� null ������ � ������ ��� ������ �����
    if(currptr != nullptr )
    {
        //���� ���������� ���� null ������ �������� � ������ � ������ ����
        if(prevNode == nullptr)
            DeleteFront(head);//����� ������ ������� ���� � ������
        else
            {
                //���� ��������� �� �������� ���� �� null ������ ��������� �� ��� ����
                //�������� ����,������� ������� ���� ��������� �� prevNode
                prevNode->DeleteAfter();
            }
        //delete currptr;

    }
}


//������� ������� ������
template<typename T>
void ClearList(Node<T>* &head)
{
    Node<T>* currPtr;//������� ����
    Node<T>* nextNode;//��������� ����

    currPtr=head;

    //�������� �� ������
    //� ������� ����
    while(currPtr != nullptr)
    {
        nextNode = currPtr->NextNode();//��������� ��������� �� ���� ����
        delete currPtr;//������� �������
        currPtr = nextNode;//��������� � ���������� ����
    }
    head=nullptr;

}

//�������� item � ������������� ������
template<typename T>
void InsertOrder(Node<T>* &head, T& item)
{
   //currPtr ���������� �� ������
   Node<T>* currPtr;
   Node<T>* newNode;
   Node<T>* prevPtr;

   //prevPtr==Null ��������� �� ���������� � ������ ������

   prevPtr = nullptr;
   currPtr = head;


   //���� �� ������ � ����� ����� �������
   while(currPtr != nullptr)
   {
       //����� ������� ������� ���� item<data
       if(item<currPtr->GetData())
        break;

       prevPtr = currPtr;
       currPtr = currPtr->NextNode();
   }
   //�������
   if(prevPtr == nullptr)
    InsertFront(head,item);
   else
   {
       //�������� ����� ���� ����� �����������
       newNode = GetNode(item);
       prevPtr->InsertAfter(newNode);
   }
}

//����������
template<typename T>
void LinkSort(T a[], int N)
{
    Node<T>* ordlist = nullptr;
    Node<T>* currPtr;


    //��������� �������� �� ������� � ������ � ���������������
    for(int i = 0;i<N;i++)
        InsertOrder(ordlist,a[i]);

    //����������� ������ � ���������� ������ � ������
    currPtr = ordlist;
    int i = 0;
    //������ � ���� ��������������,������ �������� �� � ������
    while(currPtr != nullptr)
    {
        a[i++] = currPtr->GetData();
        currPtr = currPtr->NextNode();
    }

    //������� ��� ����, ��������� � ������������� ������
    ClearList(ordlist);
}
#endif // LISTTEMP_H_INCLUDED
