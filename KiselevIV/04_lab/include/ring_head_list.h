#pragma once
#ifndef RING_HEAD_LIST_H
#define RING_HEAD_LIST_H
#include "head_list.h"

template <typename T>
class TRingHeadList : public THeadList<T> {
public:
    TRingHeadList() : pStop = pHead{};
    TRingHeadList(const TRingHeadList<T>& list);
    ~TRingHeadList() {};
    const TRingHeadList& operator=(const TRingHeadList<T>& s);
    virtual void pushFront(int key, T val);
    virtual void pushBack(int key, T val);
    virtual void popFront();
    virtual void popBack();
};

template <typename T>
TRingHeadList<T>::TRingHeadList(const TRingHeadList<T>& list) : THeadList<T>(list) {
    if (pLast != nullptr)
        pLast->pNext = pHead;
    pStop = pHead;
};

#endif
