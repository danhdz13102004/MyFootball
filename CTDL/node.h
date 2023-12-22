#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H
template <typename T>

class node
{
public:
    T data;
    node *next;
    node *prev;
    node(T);
    ~node();
};
template <typename T>
node<T>::node(T t)
    : data(t), next(NULL), prev(NULL)
{
}
template <typename T>
node<T>::~node()
{
}
#endif
