#ifndef __TNODE_H__
#define __TNODE_H__

#include <iostream>

template <typename T>
class TNode
{
public:

    T Data;
    TNode* pNext;

    TNode() : Data(T()), pNext(nullptr) {}
    TNode(const T& tmpdata, TNode* tmppNext = nullptr) : Data(tmpdata), pNext(tmppNext) {};
};

#endif