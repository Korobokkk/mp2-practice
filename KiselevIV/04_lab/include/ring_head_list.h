#pragma once
#ifndef RING_HEAD_LIST_H
#define RING_HEAD_LIST_H
#include "head_list.h"

template <typename T>
class RingHeadList : public THeadList<T> 
{
protected:
    TNode<T>* pStop;
public:
    RingHeadList();
    RingHeadList(const RingHeadList<T>& list);
    ~RingHeadList();

    void push_front(TNode<T>* newNode) override;
    void push_back(TNode<T>* newNode) override;
    void push_after(TNode<T>* newNode, T data) override;
    void push_before(TNode<T>* newNode, T data) override;
    void remove(T target_key) override;

    const RingHeadList<T>& operator=(const RingHeadList<T>& list);
};

template <typename T>
RingHeadList<T>::RingHeadList() : THeadList<T>() {
    pHead->pNext = pHead;
    pFirst = pHead;
    pLast = pHead;
}
template <typename T>
RingHeadList<T>::RingHeadList(const RingHeadList<T>& list) : THeadList<T>(list) {
    pStop = pHead;
    pLast->pNext = pHead;
}

template <typename T>
RingHeadList<T>::~RingHeadList() {
    clear();
}

template< typename T>
const RingHeadList<T>& RingHeadList<T>:: operator=(const RingHeadList<T>& list)
{
    THeadList<T>::operator=(list);
    pStop = pHead;
    if (pLast != nullptr)
        pLast->pNext = pStop;
    return *this;
}

template <typename T>
void RingHeadList<T>::push_front(TNode<T>* node)
{
    THeadList<T>::pushfront(node);
    pStop = pHead;
    pLast->pNext = pStop;
}

template <typename T>
void RingHeadList<T>::push_back(TNode<T>* node) 
{
    TList<T>::push_back(node);
    pStop = pHead;
    pLast->pNext = pStop;
    
}

template <typename T>
void RingHeadList<T>::push_after(TNode<T>* node, T data)
{
    THeadList<T>::popFront(node);
    if (pLast != nullptr)
    {
        pLast->pNext = pHead;
    }
}
template <typename T>
void RingHeadList<T>::push_before(TNode<T>* node, T data) 
{
    TList<T>::push_before();
    if (pLast != nullptr)
        pLast->pNext = pHead;
}

#endif
