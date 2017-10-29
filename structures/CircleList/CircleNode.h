#ifndef CIRCLENODE_H_INCLUDED
#define CIRCLENODE_H_INCLUDED


//Циклический список это тот же связный список из узлов,но
//последний элемент даннго списка указывает на первый
//создавая петлю.Так как указателя на Null тут вообще нет
//то пустой список состоит из одного узла который указывает
// на самого себя.
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
    //конструктор создает пустой список который состоит из
    // одного элемента.Этот элемент указывает на самого себя
    //поэтому указатель next указывает на этот же элемент
    nextNode = this;
    data = item;
}

//вставка узла р после текущего узла
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
    //сохрраняем указатель на удаляемый узел
    CNode<T>* tempPtr = nextNode;

    //Если список пуст(узел указывает сам на себя) то ошибка
    //иначе берем указатель на следующий узел после удаляемого
    //и присваеваем этот указатель next текущему
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
