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
    //TNode<T>* pStop;
public:
    TList()
    {
        pFirst = nullptr;
        pLast = nullptr;
        pPrev = nullptr;
        pCurr = nullptr;
    }
    TList(const TList& list)
    {
        pLast = nullptr;
        pPrev = nullptr;
        pCurr = nullptr;

        if (list.pFirst == nullptr)
        {
            pFirst = nullptr;
            return;
        }
        pFirst = new TNode<T>(list.pFirst->key);
        TNode<T>* curr_origin = pFirst->pNext;
        TNode<T>* curr_copy = pFirst;
        pCurr = pFirst;

        while (curr_origin != nullptr)
        {
            curr_copy->pNext= new TNode<T>(curr_origin->key);
            curr_copy = curr_copy->pNext;
            curr_origin = curr_origin->pNext;
        }
        pLast = curr_copy;
        pCurr = nullptr;
    }
    ~TList()
    {
        pCurr = pFirst;
        TNode<T>* tmp = nullptr;
        while (pCurr != nullptr)
        {      
            tmp = pCurr->pNext;
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
        return nullptr;
    }
    void push_front(TNode<T>* newNode)
    {
        if (newNode == nullptr)
        {
            throw "newNode is empty!";
        }

        if (empty())
        {
            pFirst = newNode;
            pLast = pFirst;
            return;
        }
        newNode->pNext = pFirst;
        pFirst = newNode;
    }
    void push_back(TNode<T>* newNode)
    {
        if (newNode == nullptr)
        {
            throw "newNode is empty!";
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
        pLast = newNode;
    }
    void push_after(TNode<T>* newNode, T target_key)
    {
        if (newNode == nullptr)
        {
            throw "newNode is empty!";
        }

        pCurr = this->search(target_key);
        if (pCurr== nullptr)
        {
            throw "no key found!";
        }

        newNode->pNext = pCurr->pNext;
        pCurr->pNext = newNode;
        if (newNode->pNext == nullptr) 
        {
            pLast = newNode;
        }
        pCurr = nullptr;
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
        while (pCurr != nullptr && pCurr->key != target_key)
        {
            pPrev = pCurr;
            pCurr = pCurr->pNext;
        }

        if (pCurr == nullptr)
        {
            throw "no key found!";
        }

        TNode<T>* tmp = pCurr;
        pPrev->pNext = newNode;
        newNode->pNext = tmp;
    }
    void remove(T target_key)
    {
        pCurr = pFirst;
        pPrev = nullptr;

        TNode<T>* node = search(target_key);
        if (node == nullptr) {
            throw "no key found!";
        }

        if (node == pFirst) {
            pop_front();  
            return;
        }

        pPrev = pFirst;
        while (pPrev->pNext != node) {
            pPrev = pPrev->pNext;
        }
        pPrev->pNext = node->pNext;
        if (node == pLast) {
            pLast = pPrev;
        }
        pCurr = nullptr;
        pPrev = nullptr;
        
    }
    int size()const
    {
        TNode<T>* curr = pFirst;
        int sz = 0;
        while (curr != nullptr)
        {
            sz++;
            curr = curr->pNext;
        }
        return sz;
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

        while (!empty())
        {
            pop_front();
        }

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
        pPrev = nullptr;
        pLast = curr_copy;

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
    void pop_front()
    {
        if (empty())
        {
            throw "STACK S EMPTY";
        }

        TNode<T>* tmp = pFirst;
        pFirst = pFirst->pNext;
        if (pFirst == nullptr)
        {
            pLast = nullptr;
        }
        delete tmp;

    }
    void pop_back()
    {
        if (empty())
        {
            throw "list is empty";
        }
        if (pFirst == pLast)
        {
            delete pFirst;
            pFirst = pLast = nullptr;
            return;
        }

        TNode<T>* prev = pFirst;
        while (prev->pNext != pLast) 
        {
            prev = prev->pNext;
        }

        delete pLast;
        pLast = prev;
        pLast->pNext = nullptr;
    }
    T get_first_key() const {
        if (empty())
        {
            throw "list is empty";
        }
        return pFirst->key;
    }
    T get_last_key() const {
        if (empty())
        {
            throw "list is empty";
        }
        return pLast->key;
    }
};
// в конце list.h или в тестовом .cpp
template class TList<int>;
template class TList<std::string>;
