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
    void pushFront(TNode<T>* newNode);
    void pushBack(TNode<T>* newNode);
    /*void push_front(TNode<TKey>* newNode)
    {
        if (pFirst == nullptr)
        {
            pFirst = newNode;
            return;
        }
        newNode->pNext = pFirst;
        pFirst = newNode;
    }
    void push_back(TNode<TKey>* newNode)
    {
        if (newNode == nullptr)
        {
            throw "node is empty!";
        }
        TNode<TKey>* curr = pFirst;
        if (curr == nullptr)
        {
            pFirst = newNode;
            return;
        }
        while (curr->pNext != nullptr)
        {
            curr = curr->pNext;
        }
        curr->pNext = newNode;
    }
    void push_after(TNode<TKey>* newNode, TKey target_key)
    {
        TNode<TKey>* curr = this->search(target_key);
        if (curr == nullptr)
        {
            throw "no key found!";
        }
        newNode->pNext = curr->pNext;
        curr->pNext = newNode;
    }
    void push_before(TNode<TKey>* newNode, TKey target_key)
    {
        TNode<TKey>* curr = pFirst, * prev = nullptr;
        if (curr->key == target_key)
        {
            push_front(newNode);
            return;
        }
        while (curr != nullptr && curr->key != target_key)
        {
            prev = curr;
            curr = curr->pNext;
        }
        if (curr == nullptr && curr->key != target_key)
        {
            throw "no key found!";
        }
        TNode<TKey>* tmp = curr;
        prev->pNext = newNode;
        newNode->pNext = tmp;
    }
    void remove(TKey target_key)
    {
        TNode<TKey>* curr = pFirst, * prev = nullptr;
        if (search(target_key) == nullptr)
        {
            throw "no key found!";
        }
        if (pFirst->key == target_key)
        {
            pFirst = curr->pNext;
            return;
        }
        while (curr != nullptr && curr->key != target_key)
        {
            prev = curr;
            curr = curr->pNext;
        }
        prev->pNext = curr->pNext;

    }
    int size()const
    {
        TNode<TKey>* curr = pFirst;
        int sz = 1;
        while (curr->pNext != nullptr)
        {
            sz++;
            curr = curr->pNext;
        }
        return sz;
    }
    TKey first()const
    {
        if (pFirst == nullptr)
        {
            throw "list is empty";
        }
        return pFirst->key;
    }
    bool empty()const
    {
        return pFirst == nullptr;
    }
    const TList <TKey>& operator = (const TList <TKey>& list)
    {
        if (this == &list)
        {
            return *this;
        }
        if (list.pFirst == nullptr)
        {
            pFirst = nullptr;
            return *this;
        }
        pFirst = new TNode<TKey>(list.pFirst->key);
        TNode<TKey>* curr_origin = list.pFirst->pNext;
        TNode<TKey>* curr_copy = pFirst;

        while (curr_origin != nullptr)
        {
            curr_copy->pNext = new TNode<TKey>(curr_origin->key);
            curr_copy = curr_copy->pNext;
            curr_origin = curr_origin->pNext;
        }
        return *this;
    }
    bool operator == (const TList <TKey>& list)const
    {
        if (list.size() != size())
        {
            return false;
        }
        TNode<TKey>* curr_origin = list.pFirst;
        TNode<TKey>* curr = pFirst;
        if (curr_origin == nullptr && curr == nullptr)
        {
            return true;
        }
        while (curr_origin != nullptr && curr != nullptr)
        {
            if (curr->key != curr_origin->key)
            {
                return false;
            }
            curr = curr->pNext;
            curr_origin = curr_origin->pNext;
        }
        return true;
    }
    bool operator != (const TList <TKey>& list)const
    {
        return !(*this = list);
    }*/
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
    pPrev = nullptr;
    pStop = nullptr;
    if (pFirstSource == pStop) 
    {
        pPrev = nullptr;
        pFirst = nullptr;
        pCurr = nullptr;
        pLast = nullptr;
        return;
    }
    pFirst = new TNode<T>(pFirstSource->Data);
    pCurr = pFirst;
    pLast = pFirst;
    TNode<T>* tmp = pFirstSource->pNext;
    while (tmp != pStop)
    {
        pCurr->pNext = new TNode<T>(tmp->Data);
        pPrev = pCurr;
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
    pPrev = nullptr;
    if (list.pFirst == pStop)
    {
        pFirst = nullptr;
        pCurr = nullptr;
        pLast = nullptr;
        return;
    }

    pFirst = new TNode<T>(*list.pFirst);
    pLast = pFirst;
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
void TList<T>::pushFront(TNode<T>* newNode)
{
    if (newNode == nullptr)
    {
        return;
    }
    newNode->pNext = pFirst;
    pFirst = newNode;
    if (pLast = nullptr) {
        pLast = pFirst;
    }    
}

template<typename T>
void TList<T>::pushBack(TNode<T>* newNode)
{
    if (newNode == nullptr)
    {
        return;
    }
    if (pFirst = nullptr)
    {
        pFirst = newNode;
        pLast = pFirst;
        pCurr = pFirst;
        return;
    }
    pLast->pNext = newNode;
    pLast = newNode;
    pCurr = pFirst;
}

#endif