#pragma once
#include "List.h"

template <typename T>
class THeadList :public TList<T> 
{
protected:
    TNode<T>* pHead;

public:
    THeadList() {};
    THeadList(const THeadList<T>&s)
    {
        elems = s.elems;
    }
    ~THeadList()
    {
        //Возможно есть потеря памяти(не все Node удаляются) , подумать об этом. Think about it
        delete pHead;
        pHead = nullptr;
    }
    virtual void push_front(int key, T val);
    virtual void pop_front();
    virtual const THeadList<T>& operator=(const THeadList<T>&s);

};

template <typename T>
const THeadList <T>& THeadList<T>::operator = (const THeadList <T>&s)
{
    
}
template <typename T>
void THeadList<T>::push_front(int key, T Val)
{
    TList<T>::push_front(key, val);
    pHead->pNext = pFirst;
}
template <typename T>
void THeadList<T>::pop_front()
{
    TList<T>::pop_front();
}