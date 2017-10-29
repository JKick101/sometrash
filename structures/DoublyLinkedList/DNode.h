#ifndef DNODE_H_INCLUDED
#define DNODE_H_INCLUDED

template<typename T>
class DNode
{
   private:
       DNode<T>* left;
       DNode<T>* right;
       T data;

   public:

    DNode();
    DNode(const T& item, DNode<T>* leftNode = nullptr,DNode<T>* rightNode = nullptr);


    void InsertRight(DNode<T>* p);
    void InsertLeft(DNode<T>* p);
    DNode<T>* DeleteNode();

    DNode<T>* NextNodeRight() const;
    DNode<T>* NextNodeLeft() const;
    T GetData();


};

/*template<typename T>
DNode<T>::DNode()
{
    left = right = this;
    data = 0;
}*/


template<typename T>
DNode<T>::DNode(const T& item, DNode<T>* leftNode,DNode<T>* rightNode)
{
    //���� ��������� ������� ������ ������ �� �������� �����
    if(leftNode ==  nullptr || rightNode == nullptr)
    {
       left = this;
       right = this;
       data = item;
    }
    else
        {
    //����� ��������� �� ����� ���� �� ������� ����
    left = rightNode->left;
    //��������� �� ������ ���� �� ������
    right = leftNode->right;
    //����� � ������ ���� ������ ��������� �� �����
    leftNode->right = this;
    rightNode->left = this;
    data = item;
    }
}


//������� ���� ������ �� ��������
template<typename T>
void DNode<T>::InsertRight(DNode<T>* p)
{
    //�������� ��������� ������ �� �������� ���� � �����
    p->right = right;
    //��������� ������ ���� ������ ������ ��������� �� ����� ����
    right->left = p;

    //��������� ������ ������ ���� ������ ��������� �� �������
    p->left = this;
    //��������� ������� �������� ���� ������ ��������� �� �����
    right = p;

}


template<typename T>
void DNode<T>::InsertLeft(DNode<T>* p)
{
    p->left = left;
    left->right = p;

    p->right = this;
    left = p;

}

template<typename T>
DNode<T>* DNode<T>::DeleteNode()
{

    left->right = right;
    right->left = left;
    return this;
}


template<typename T>
DNode<T>* DNode<T>::NextNodeRight() const
{
    return right;
}


template<typename T>
DNode<T>* DNode<T>::NextNodeLeft() const
{
    return left;
}

template<typename T>
T DNode<T>::GetData()
{
    return data;
}

template<typename T>
DNode<T>* GetDNode(const T& item, DNode<T>* leftNode=nullptr, DNode<T>* rightNode=nullptr)
{
    DNode<T>* newNode;
    newNode = new DNode<T>(item,leftNode,rightNode);
    if(newNode == nullptr)
        std::cout<<"Can't create node"<<std::endl;
    else
        return newNode;
}

template<typename T>
void InsertDFront(DNode<T>* &Dhead, T item)
{
    Dhead = GetDNode(item,Dhead->NextNodeLeft(),Dhead);
    //DNode<T>* newNode = GetDNode(item);
    //newNode->left = Dhead->left;
    //newNode->right = Dhead;
    //Dhead->left->right = newNode;
    //Dhead->left = newNode;

}
template<typename T>
void InsertDRear(DNode<T>* head,T item)
{
    DNode<T>* newNode = GetDNode(item);
    DNode<T>* currPtr = head;
    while(currPtr->NextNodeRight() != head)
        currPtr = currPtr->NextNodeRight();
    currPtr->InsertRight(newNode);

}

template<typename T> ClearDNodes(DNode<T>* head)
{
    DNode<T>* currPtr = head->NextNodeRight();
    DNode<T>* prevPtr = head->NextNodeRight();
    DNode<T>* DelNode;
    while(currPtr != head)
    {
        currPtr = currPtr->NextNodeRight();
        DelNode = prevPtr->DeleteNode();
        delete DelNode;
        prevPtr = currPtr;
    }

}


template<typename T>
void PrintDNodes(DNode<T>* head)
{

    DNode<T>* start = head;
    while(start->NextNodeRight() != head)
    {
        std::cout<<start->GetData()<<" ";
        start = start->NextNodeRight();
    }
    std::cout<<start->GetData();
}


#endif // DNODE_H_INCLUDED
