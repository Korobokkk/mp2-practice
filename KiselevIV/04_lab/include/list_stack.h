#pragma once
#include "stack.h"
template <typename T>
class list_stack : public stack<T>
{
private:
    TList<T> elems;

public:
    list_stack() {};
    list_stack(const list_stack<T>& s)
    {
        elems = s.elems;
    }
    void push(const T& e)
    {
        if (is_full())
        {
            throw "stack is full!";
        }
        TNode<T>* newNode = new TNode<T>(e);
        elems.push_front(newNode);
        return;
    }
    T show_top()const
    {
        if (is_empty())
        {
            throw "EMPTY STACK";
        }
        return elems.get_first_data();
    }
    void pop()
    {
        if (is_empty())
        {
            throw "EMPTY STACK";
        }
        try
        {
            elems.remove(elems.first());
        }
        catch (...)
        {
            throw "EMPTY STACK";
        }
    }
    bool is_full()const
    {
        try
        {
            TNode<T>* newNode = new TNode<T>();
            if (newNode == nullptr)
            {
                return true;
            }
            delete newNode;
        }
        catch (...)
        {
            return true;
        }
        return false;

    }
    bool is_empty()const
    {
        return elems.empty();
    }
    const list_stack <T>& operator = (const list_stack <T>& s)
    {
        if (this == &s)
        {
            return *this;
        }
        elems = s.elems;
        return *this;
    }
    bool operator == (const list_stack <T>& s)const
    {
        return (elems == s.elems);
    }
    bool operator != (const list_stack <T>& s)const
    {
        return !(*this == s);
    }
};