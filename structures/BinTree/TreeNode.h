#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

#include "ListQueue.h"
template <class T>
class BinSTree;

template<typename T>
class TreeNode
{

private:
    TreeNode<T>* left;
    TreeNode<T>* right;
    T data;

public:
    TreeNode(const T& item, TreeNode<T>* lptr = nullptr,
                TreeNode<T>* rptr = nullptr);

    TreeNode<T>* Left() const;
    TreeNode<T>* Right() const;
    T GetData() const;

    friend class BinSTree<T>;

};


template<typename T>
TreeNode<T>::TreeNode(const T& item, TreeNode<T>* lptr,
            TreeNode<T>* rptr):data(item), left(lptr), right(rptr){};

template<typename T>
TreeNode<T>* TreeNode<T>::Left() const
{
    return left;
};

template<typename T>
TreeNode<T>* TreeNode<T>::Right() const
{
    return right;
};


 template<typename T>
 T TreeNode<T>::GetData() const
 {
     return data;
 };


 template<typename T>
 TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = nullptr,
                          TreeNode<T>* rptr = nullptr)
{
    TreeNode<T>* p;

     p = new TreeNode<T>(item,lptr,rptr);

     if(p == nullptr)
     {
         std::cout<<"Error of memory!"<<std::endl;

     }
    else
        return p;
}


template<typename T>
void FreeTreeNode(TreeNode<T>* p)
{
    delete p;
}

//������������ ���������� ������� � ������
template<typename T>
void  CountLeaf (TreeNode<T>* t,int &Count)
{
    if (t != nullptr)
    {
        //������ �� ������ �������������� �� ���� ��������
        CountLeaf(t->Left(), Count);
        CountLeaf(t->Right(), Count);
        //���� ������ � ����� ��������� ����� ������ ��� ����
        if (t->Left() == nullptr && t->Right() == nullptr)
            Count++;
    }

}

//������� ������� ������
template<typename T>
int Depth(TreeNode<T>* t)
{
    int depthLeft,depthRight,depthVal;
    if(t == nullptr)
        depthVal = -1;
    else
        {
            depthLeft = Depth(t->Left());
            depthRight = Depth(t->Right());
            depthVal = 1 + (depthLeft>depthRight?depthLeft:depthRight);

        }
    return depthVal;
}

template<typename T>
void PrintTree(TreeNode<T>* root,int level)
{
    const int IndentBlock = 6;
    if(root != nullptr)
    {

        PrintTree(root->Right(),level+1);
        for (int i = 0; i<6*level; i++)
        std::cout<<" ";
        std::cout<<root->GetData()<<std::endl;
        PrintTree(root->Left(),level+1);
    }

}


void IndentBlanks(int num)
{
    for (int i = 0; i<num; i++)
        std::cout<<" ";
}

//����������� ������
template<typename T>
TreeNode<T>* CopyTree(TreeNode<T>* t)
{


        //newnode ��� ��������� �� ����� ����,
        //newlptr newrptr ��������� �� ����� � ������ ����
        TreeNode<T>* newlptr;
        TreeNode<T>* newrptr;
        TreeNode<T>* newnode;

        //��������� ����������� ���� ��������� ����
        if(t == nullptr)
            return nullptr;


        //CopyTree ������ ����� ������ � �������� �����������
        //����� ������ t.� ������ ���� ����� ������ ����������
        //�������� ������ � ������� ����.���� �� ���� ��������� ��� �����
        //����� Null.� ���������� ���������� ������������ ������� � �����
        //������� �����
        if (t->Left() != nullptr)
            newlptr = CopyTree(t->Left());
        else
            newlptr = nullptr;

        if(t->Right() != nullptr)
            newrptr = CopyTree(t->Right());
            else
                newrptr = nullptr;

//��������� ����� ������ ����� �����, ������� ��������
//���� ������� � ����� �� ��������
            newnode = GetTreeNode(t->GetData(),newlptr,newrptr);
//������� ��������� �� ����� ��������� ������
        return newnode;
}

//�������� ������
template<typename T>
void DeleteTree(TreeNode<T>* t)
{
   //���������� � ����� ��� ������ � �������� ��������
   //� ������ ������ ����
    if(t != nullptr)
    {
        DeleteTree(t->Left());
        DeleteTree(t->Right());
        FreeTreeNode(t);
    }
}

template<typename T>
void ClearTree(TreeNode<T> &t)
{
    DeleteTree(t);
    t = nullptr;
    //������ ������ ����
}


template<typename T>
void LevelScan(TreeNode<T>* t)
{
    Queue<TreeNode<T>*> Q;
    TreeNode<T>* p;

    Q.QInsert(t);

    while(!Q.QEmpty())
    {
        //std::cout<<std::endl<<"-------------"<<std::endl;

        p = Q.QDelete();

        std::cout<<p->GetData()<<" ";

        if(p->Left() != nullptr)
            Q.QInsert(p->Left());
        if(p->Right() != nullptr)
            Q.QInsert(p->Right());

    }


}
#endif // TREENODE_H_INCLUDED
