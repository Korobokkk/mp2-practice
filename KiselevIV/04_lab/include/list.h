#pragma once
#include <iostream>
using namespace std;

template <typename T>
class TNode
{
public:

    T key;
    TNode* pNext;

    TNode() : key(T()), pNext(nullptr) {}
    TNode(const T& tmpdata, TNode* tmppNext = nullptr) : key(tmpdata), pNext(tmppNext) {};
};

template <typename T>
class TList
{
protected:
    TNode<T>* pFirst;
    TNode<T>* pLast;
    TNode<T>* pCurr;
    TNode<T>* pPrev;
    TNode<T>* pStop;
public:
    TList()
    {
        pStop = nullptr;
        pFirst = nullptr;
        pLast = nullptr;
        pPrev = nullptr;
        pCurr = nullptr;
    }
    TList(const TList& list)
    {
        if (list.pFirst == list.pStop)
        {
            pFirst = nullptr;
            return;
        }
        pFirst = new TNode<T>(list.pFirst->key);
        TNode<T>* curr_origin = list.pFirst->pNext;
        pCurr = pFirst;

        while (curr_origin != nullptr)
        {
            pCurr->pNext = new TNode<T>(curr_origin->key);
            pCurr = pCurr->pNext;
            curr_origin = curr_origin->pNext;
        }
        pLast = list.pLast;
        pCurr = nullptr;
        pStop = list.pStop;
    }
    ~TList()
    {
        pCurr = pFirst;
        while (pCurr != nullptr)
        {
            TNode<T>* tmp = pCurr->pNext;
            delete pCurr;
            pCurr = tmp;
        }
        pFirst = nullptr;
        pLast = nullptr;
        pPrev = nullptr;
        pCurr = nullptr;
    }

    TNode<T>* search(T target_key)
    {
        pCurr = pFirst;
        while (pCurr != nullptr)
        {
            if (pCurr->key == target_key)
            {
                return pCurr;
            }
            pCurr = pCurr->pNext;
        }
        pCurr = pStop;
        return nullptr;
    }
    void push_front(TNode<T>* newNode)
    {
        if (empty())
        {
            pFirst = newNode;
            pLast = pStop;
            return;
        }
        newNode->pNext = pFirst;
        pFirst = newNode;
    }
    void push_back(TNode<T>* newNode)
    {
        if (newNode == nullptr)
        {
            throw "node is empty!";
        }
        pCurr = pFirst;
        if (empty())
        {
            pFirst = newNode;
            pLast = pFirst;
            return;
        }
        while (pCurr->pNext != nullptr)
        {
            pCurr = pCurr->pNext;
        }
        pCurr->pNext = newNode;
        pLast = pCurr->pNext;
    }
    void push_after(TNode<T>* newNode, T target_key)
    {

        pCurr = this->search(target_key);
        if (pCurr== pStop)
        {
            throw "no key found!";
        }
        newNode->pNext = pCurr->pNext;
        pCurr->pNext = newNode;
        if (pCurr == pLast) 
        {
            pLast = pCurr;
        }
        pCurr = pStop;
    }
    void push_before(TNode<T>* newNode, T target_key)
    {
        if (empty()) {
            throw "List is Empty";
        }
        if (pFirst->key == target_key)
        {
            push_front(newNode);
            return;
        }
        pCurr = pFirst->pNext;
        pPrev = nullptr;
        while (pCurr != pStop && pCurr->key != target_key)
        {
            pPrev = pCurr;
            pCurr = pCurr->pNext;
        }
        if (pCurr == pStop && pCurr->key != target_key)
        {
            throw "no key found!";
        }
        TNode<T>* tmp = pCurr;
        pPrev->pNext = newNode;
        newNode->pNext = tmp;
    }
    void remove(T target_key)
    {
        TNode<T>* current = pFirst;
        TNode<T>* previous = nullptr;

        while (current != nullptr && current->key != target_key) {
            previous = current;
            current = current->pNext;
        }
        if (current == nullptr) {
            throw "no key found!";
        }
        if (previous == nullptr) {
            pFirst = current->pNext;
        }
        else {
            previous->pNext = current->pNext;
        }

        delete current;
    }
    int size()const
    {
        TNode<T>* curr = pFirst;
        int sz = 0;
        while (curr != pStop)
        {
            sz++;
            curr = curr->pNext;
        }
        return sz;
    }
    T first()const
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
    const TList <T>& operator = (const TList <T>& list)
    {
        if (this == &list)
        {
            return *this;
        }

        this->~TList();

        if (list.pFirst == nullptr)
        {
            pFirst = nullptr;
            pLast = nullptr;
            return *this;
        }
        pFirst = new TNode<T>(list.pFirst->key);
        TNode<T>* curr_origin = list.pFirst->pNext;
        TNode<T>* curr_copy = pFirst;

        while (curr_origin != nullptr)
        {
            curr_copy->pNext = new TNode<T>(curr_origin->key);
            curr_copy = curr_copy->pNext;
            curr_origin = curr_origin->pNext;
        }
        return *this;
    }
    bool operator == (const TList <T>& list)const
    {
        if (list.size() != size())
        {
            return false;
        }
        TNode<T>* curr_origin = list.pFirst;
        TNode<T>* curr = pFirst;
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
    bool operator != (const TList <T>& list)const
    {
        return !(*this == list);
    }

    T get_first_data() const {
        return pFirst->key;
    }
    /*T get_last_key() const {
        return pLast->Key;
    }*/

    T get_last_data() const {
        return pLast->Data;
    }
};