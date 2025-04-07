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
    ~THeadList();
    virtual void pushFront(int key, T val);
    virtual void popFront();
    virtual const THeadList<T>& operator=(const THeadList<T>&s);

};

template <typename T>
const THeadList <T>& THeadList<T>::operator = (const THeadList <T>&s)
{
    
}