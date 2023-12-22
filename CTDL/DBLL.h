#include <iostream>
#include "node.h"
using namespace std;
#ifndef LLDB_H
#define LLDB_H
template <typename T>

class DBLL
{
private:
    node<T> *head = NULL;
    node<T> *tail = NULL;

public:
    DBLL();
    ~DBLL();
    node<T> *makenode(T); // tao node
    int size();           // kich thuoc danh sach
    void push_fr(T);      // them node vao dau
    void push_back(T);    // them node vao cuoi
    void insert(int, T);  // them node vao vi tri bat ky
    void delete_fr();     // xoa node dau
    void delete_b();      // xoa node cuoi
    void erase(int);      // xoa node o vi tri bat ky
    void duyetxuoi();     // duyet danh sach theo chieu xuoi
    void duyetnguoc();
    T &operator[](int);
};
template <typename T>
DBLL<T>::DBLL()
{
}
template <typename T>
DBLL<T>::~DBLL()
{
}

template <typename T>
T &DBLL<T>::operator[](int index)
{
    node<T> *tmp = head;
    int i = 0;
    while (tmp != NULL)
    {
        if (i == index)
            return tmp->data;
        i++;
        tmp = tmp->next;
    }
    return tmp->data;
}

template <typename T>
node<T> *DBLL<T>::makenode(T x)
{
    node<T> *new_node = new node<T>(x);
    return new_node;
}

template <typename T>
int DBLL<T>::size()
{
    int cnt = 0;
    node<T> *tmp = head;
    while (tmp != NULL)
    {
        ++cnt;
        tmp = tmp->next;
    }
    return cnt;
}

template <typename T>
void DBLL<T>::push_fr(T x)
{
    node<T> *new_node = makenode(x);
    new_node->next = head;
    if (head != NULL)
        head->prev = new_node;
    head = new_node;
}

template <typename T>
void DBLL<T>::push_back(T x)
{
    node<T> *new_node = makenode(x);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    node<T> *tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
    new_node->prev = tmp;
}

template <typename T>
void DBLL<T>::insert(int k, T x)
{
    int n = DBLL::size(head);
    if (k < 1 || k > n + 1)
        return;
    if (k == 1)
        DBLL::push_fr(head, x);
    else if (k == n + 1)
        DBLL::push_b(head, x);
    else
    {
        node<T> *tmp = head;
        for (int i = 1; i < k - 1; i++)
            tmp = tmp->next;
        node<T> *new_node = makenode(x);
        new_node->next = tmp->next;
        tmp->next->prev = new_node;
        tmp->next = new_node;
        new_node->prev = tmp;
    }
}

template <typename T>
void DBLL<T>::delete_fr()
{
    if (head == NULL)
        return;
    node<T> *tmp = head;
    head = (head)->next;
    if (head != NULL)
        head->prev = NULL;
    delete (tmp);
}

template <typename T>
void DBLL<T>::delete_b()
{
    if (head == NULL)
        return;
    node<T> *tmp = head;
    if (tmp->next == NULL)
    {
        head = NULL;
        delete (tmp);
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->prev->next = NULL;
    delete (tmp);
}

template <typename T>
void DBLL<T>::erase(int k)
{
    int n = DBLL<T>::size(head);
    if (k < 1 || k > n)
        return;
    if (k == 1)
        delete_fr(head);
    else
    {
        node<T> *tmp = head;
        for (int i = 1; i <= k - 1; i++)
            tmp = tmp->next;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete (tmp);
    }
}

template <typename T>
void DBLL<T>::duyetxuoi()
{
    node<T> *tmp = this->head;
    while (tmp != NULL)
    {
        cout << tmp->data;
        tmp = tmp->next;
    }
}

template <typename T>
void DBLL<T>::duyetnguoc()
{
    node<T> *tmp = this->head;
    if (tmp == NULL)
        return;
    while (tmp->next != NULL)
        tmp = tmp->next;
    while (tmp != NULL)
    {
        cout << tmp->data;
        tmp = tmp->prev;
    }
}

#endif