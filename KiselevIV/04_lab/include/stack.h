#pragma once
#include "list.h"
#include <iostream>
using namespace std;

template <typename T>
class stack
{
public:
    virtual void push(const T& e) = 0;
    virtual T show_top()const = 0;
    virtual void pop() = 0;
    virtual bool is_full()const = 0;
    virtual bool is_empty()const = 0;
};