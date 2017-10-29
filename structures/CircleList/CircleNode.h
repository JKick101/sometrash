#ifndef CIRCLENODE_H_INCLUDED
#define CIRCLENODE_H_INCLUDED


//����������� ������ ��� ��� �� ������� ������ �� �����,��
//��������� ������� ������ ������ ��������� �� ������
//�������� �����.��� ��� ��������� �� Null ��� ������ ���
//�� ������ ������ ������� �� ������ ���� ������� ���������
// �� ������ ����.
template<typename T>
class CNode
{
private:
    CNode<T>* nextNode;
public:
    T data;

    CNode();
    CNode(const T& item);

    void IsertAfter(CNode<T>* p);
    CNode<T>* DeleteAfter();

    CNode<T>* NextNode() const;


};



template<typename T>
CNode<T>::CNode(const T& item)
{
    //����������� ������� ������ ������ ������� ������� ��
    // ������ ��������.���� ������� ��������� �� ������ ����
    //������� ��������� next ��������� �� ���� �� �������
    nextNode = this;
    data = item;
}

//������� ���� � ����� �������� ����
template<typename T>
void CNode<T>::InsertAfter(CNode<T>* p)
{
    p->nextNode = nextNode;
    nextNode = p;
}


//
template<typename T>
CNode<T>* CNode<T>::DeleteAfter()
{
    //���������� ��������� �� ��������� ����
    CNode<T>* tempPtr = nextNode;

    //���� ������ ����(���� ��������� ��� �� ����) �� ������
    //����� ����� ��������� �� ��������� ���� ����� ����������
    //� ����������� ���� ��������� next ��������
    if (nextNode == this)
        std::cout<<"List is Empty"<<std::endl;
    else
    {
        nextNode = tempPtr->nextNode;
        return tempPtr;
    }
}

template<typename T>
CNode<T>* CNode<T>::NextNode() const
{
    return nextNode;
}

#endif // CIRCLENODE_H_INCLUDED
