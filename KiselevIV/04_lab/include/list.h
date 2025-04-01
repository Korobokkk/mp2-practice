#ifndef __LIST_H__
#define __LIST_H__
#include <iostream>
#include "TNode.h"
using namespace std;

template <typename T>
class TList
{
protected:
    TNode<T>* pFirst;
    TNode<T>* pCurr;
    TNode<T>* pLast;
    TNode<T>* pStop;
    TNode<T>* pPrev;
public:
    TList();
    TList(TNode<T>* pFirstSource);
    TList(const TList& list);
    ~TList();

    TNode<T>* Search(const T& Data);
    void push_front(TNode<T>* newNode);
    void push_back(TNode<T>* newNode);
    void push_after(TNode<T>* newNode, T& Data);
    void push_before(TNode<T>* newNode, T& Data);

    bool IsEmpty() const;
    bool IsFull() const;
    int size()const;
    void remove(T& data);


    //перегрузки
  /* 
    TKey first()const
    {
        if (pFirst == nullptr)
        {
            throw "list is empty";
        }
        return pFirst->key;
    }*/
    const TList <T>& operator = (const TList <T>& list)
    {
        pStop = nullptr;
        if (this == &list)
        {
            return *this;
        }
        if (list.pFirst == nullptr)
        {
            pFirst = nullptr;
            return *this;
        }
        pFirst = new TNode<T>(list.pFirst->Data);
        TNode<TKey>* curr_origin = list.pFirst->pNext;
        pCurr = pFirst;

        while (curr_origin != pStop)
        {
            pCurr->pNext = new TNode<T>(curr_origin->Data);
            pCurr = pCurr->pNext;
            curr_origin = curr_origin->pNext;
        }
        pLast = list.pLast;
        return *this;
    }
    bool operator == (const TList <T>& list)const
    {
        if (list.size() != size())
        {
            return false;
        }
        TNode<T>* curr_origin = list.pFirst;
        pCurr = list.pFirst;
        if (curr_origin == nullptr && pCurr == nullptr)
        {
            return true;
        }
        while (curr_origin != nullptr && curr != nullptr)
        {
            if (pCurr->Data != curr_origin->Data)
            {
                return false;
            }
            pCurr = pCurr->pNext;
            curr_origin = curr_origin->pNext;
        }
        return true;
    }
    bool operator != (const TList <T>& list)const
    {
        return !(*this = list);
    }
};
template<typename T>
TList<T>::TList()
{
    pFirst = nullptr;
    pLast = nullptr;
    pPrev = nullptr;
    pCurr = nullptr;
    pStop = nullptr;
}
template<typename T>
TList<T>::TList(TNode<T>* pFirstSource)
{
    pStop = nullptr;
    if (pFirstSource == pStop) 
    {
        return;
    }
    pFirst = new TNode<T>(pFirstSource->Data);
    pCurr = pFirst;
    pLast = pFirst;
    TNode<T>* tmp = pFirstSource->pNext;
    while (tmp != pStop)
    {
        pCurr->pNext = new TNode<T>(tmp->Data);
        pCurr = pCurr->pNext;
        tmp = tmp->pNext;
    }
    pLast = pCurr;
    pCurr = pFirst;
}
template<typename T>
TList<T>::TList(const TList<T>& list) 
{
    //pFirst = nullptr;
    pStop = nullptr;
    if (list.pFirst == pStop)
    {
        pFirst = nullptr;
        pCurr = nullptr;
        pLast = nullptr;
        return;
    }

    pFirst = new TNode<T>(*list.pFirst);
    pCurr = pFirst;
    TNode<T>* curr_copy = pFirst;
    TNode<T>* tmp = list.pFirst->pNext;

    while (tmp != pStop)
    {
        curr_copy->pNext = new TNode<T>(tmp->Data);
        curr_copy = curr_copy->pNext;
        tmp = tmp->pNext;
    }
    pLast = list.pLast;
    pCurr = pFirst;
}

template<typename T>
TList<T>::~TList()
{
    pCurr = pFirst;
    if (pFirst == pStop) {
        return;
    }

    while (pCurr != pStop)
    {
        TNode<T>* tmp = pCurr;
        pCurr = pCurr->pNext;
        delete tmp;
    }
    pLast = nullptr;
    pPrev = nullptr;
    pCurr = nullptr;
    pFirst = nullptr;
    pStop = nullptr;
}
template<typename T>
TNode<T>* TList<T>::Search(const T& Data)
{
    TNode<T>* curr = pFirst;
    while (curr != pStop) {
        if (curr->Data == Data)
        {
            return curr;
        }
    }
    return nullptr;
}

template<typename T>
void TList<T>::push_front(TNode<T>* newNode)
{
    if (IsEmpty()) {
        throw "List is empty";
    }
    if (IsFull()) {
        throw "List is full";
    }
    newNode->pNext = pFirst;
    pFirst = newNode;
}

template<typename T>
void TList<T>::push_back(TNode<T>* newNode)
{
    if (IsEmpty()) {
        throw "List is empty";
    }
    if (IsFull()) {
        throw "List is full";
    }
    pLast->pNext = newNode;
    pLast = newNode;
    pCurr = pFirst;
}

template<typename T>
void TList<T>::push_after(TNode<T>* newNode, T& data)
{
    if (IsEmpty()) {
        throw "List is empty";
    }
    if (IsFull()) {
        throw "List is full";
    }
    TNode<T>* curr = this->search(data);
    if (curr == nullptr)
    {
        throw "no key found!";
    }
    newNode->pNext = curr->pNext;
    curr->pNext = newNode;
}

template<typename T>
void TList<T>::push_before(TNode<T>* newNode, T& data)
{
    if (IsEmpty()) {
        throw "List is empty";
    }
    if (IsFull()) {
        throw "List is full";
    }
    pCurr = pFirst;
    if (pCurr->Data == data)
    {
        push_front(newNode);
        return;
    }
    while (pCurr != pStop && pCurr->Data != data)
    {
        pPrev = pCurr;
        pCurr = pCurr->pNext;
    }
    if (pCurr == pStop && pCurr->Data != data)
    {
        throw "no key found!";
    }

    pPrev->pNext = newNode;
    newNode->pNext = tmp;
}

template<typename T>
bool TList<T>::IsEmpty() const
{
    if (pFirst == nullprt)
    {
        return true;
    }
    return false;
}
template<typename T>
bool TList<T>::IsFull() const
{
    TNode <T>* tmp = new TNode<T>();
    if (tmp == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
template<typename T>
int TList<T>::size() const
{
    int sz = 0;
    if (IsEmpty() == true) 
    {
        return 0;
    }
    pCurr = pFirst;
    while (pCurr != pStop)
    {
        sz++;
        pCurr = pCurr->pNext;
    }
    return sz;
}
template <typename T>
void TList<T>::remove(T& data)
{
    pCurr = pFirst;
    pPrev = nullptr;

    if (search(&data) == nullptr)
    {
        throw "no key found!";
    }
    if (pFirst->Data ==data)
    {
        pFirst = pCurr->pNext;
        return;
    }
    while (curr != nullptr && pCurr->Data != data)
    {
        pPrev = pCurr;
        pCurr = pCurr->pNext;
    }
    pPrev->pNext = curr->pNext;

}

#endif