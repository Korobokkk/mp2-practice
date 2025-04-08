#pragma once
#ifndef RING_HEAD_LIST_H
#define RING_HEAD_LIST_H
#include "head_list.h"

template <typename T>
class TRingHeadList : public THeadList<T> 
{
public:
    TRingHeadList() : pStop = pHead{};
    TRingHeadList(const TRingHeadList<T>& list);
    ~TRingHeadList() {};
    const TRingHeadList& operator=(const TRingHeadList<T>& s);
    virtual void push_front(int key, T val);
    virtual void push_back(int key, T val);
    virtual void push_after(int key, T val);
    virtual void push_before(int key, T val);


};

template <typename T>
TRingHeadList<T>::TRingHeadList(const TRingHeadList<T>& list) : THeadList<T>(list)
{
    if (pLast != nullptr)
        pLast->pNext = pHead;
    pStop = pHead;
};
template< typename T>
const TRingHeadList<T>& TRingHeadList<T>:: operator=(const TRingHeadList<T>& s)
{

}

template <typename T>
void TRingHeadList<T>::push_front(int key, T val)
{
    THeadList<T>::pushfront(key, val);
    pLast->pNext = pHead;
}

template <typename T>
void TRingHeadList<T>::push_back(int key, T val) 
{
    TList<T>::push_back(key, val);
    pLast->pNext = pHead;
    
}

template <typename T>
void TRingHeadList<T>::push_after(int key, T val)
{
    THeadList<T>::popFront();
    if (pLast != nullptr)
    {
        pLast->pNext = pHead;
    }
}
template <typename T>
void TRingHeadList<T>::push_before(int key, T val) 
{
    TList<T>::push_before();
    if (pLast != nullptr)
        pLast->pNext = pHead;
}

#endif
