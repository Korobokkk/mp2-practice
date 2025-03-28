#ifndef __TNODE_H__
#define __TNODE_H__

#include <iostream>

template <typename T>
class TNode
{
public:

    T Data;
    TNode* pNext;

    TNode() : data(), pNext(nullptr) {}
    TNode(const T& tmpdata, TNode* tmppNext = nullptr) : data(tmpdata), pNext(tmppNext) {};
};

#endif