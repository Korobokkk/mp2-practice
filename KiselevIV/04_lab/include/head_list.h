#pragma once
#include "List.h"

template <typename T>
class THeadList :public TList<T> 
{
protected:
    TNode<T>* pHead;

public:
    THeadList():TList<T>()
    {
        pHead = new TNode<T>();
        pHead->pNext = pFirst;
    };
    THeadList(const THeadList<T>&list):TList<T>(list)
    {
        pHead = new TNode<T>();
        pHead->pNext = pFirst;
    }
    virtual ~THeadList()
    {

        /*while (!this->empty())
        {
            this->pop_front();
        }*/
        //Мейби есть потеря памяти 
        delete pHead;
        pHead = nullptr;
    }
    virtual void push_front(TNode<T>* node);
    virtual void pop_front();
    virtual void pop_back();
    virtual const THeadList<T>& operator=(const THeadList<T>&s);
    virtual void push_after(TNode<T>* node, T data);
    virtual void push_before(TNode<T>* node, T data);
    virtual void remove(T data);
};

template <typename T>
const THeadList <T>& THeadList<T>::operator = (const THeadList <T>&list)
{
    if (this == &list)
    {
        return *this;
    }
    TList<T>::operator=(list);
    pHead->pNext = pFirst;
    return *this;

}
template <typename T>
void THeadList<T>::push_front(TNode<T>*node)
{
    TList<T>::push_front(node);
    pHead->pNext = pFirst;
}
template <typename T>
void THeadList<T>::pop_front()
{
    TList<T>::pop_front();
    pHead->pNext = pFirst;
}
template <typename T>
void THeadList<T>::pop_back()
{
    TList<T>::pop_back();
    pHead->pNext = pFirst;//мейби не надо (случайpFirst==plast)
}
template <typename T>
void THeadList<T>::push_after(TNode<T>* node, T data)
{
    TList<T>::push_after(node, data);
    pHead->pNext = pFirst;
}
template <typename T>
void THeadList<T>::push_before(TNode<T>* node, T data)
{
    TList<T>::push_before(node, data);
    pHead->pNext = pFirst;
}

template<typename T>
void THeadList<T>::remove(T data)
{
    TList<T>::remove(data);
    pHead->pNext = pFirst;
}

////чек на ошибки компиляции без запуска
template class THeadList<int>;
template class THeadList<std::string>;

