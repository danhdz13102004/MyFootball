#ifndef V_H
#define V_H

template <typename T>
class Vector
{
private:
    T *p;

public:
    static int n;
    Vector();
    Vector(const Vector &);
    void operator=(const Vector &);
    ~Vector();
    int size();
    bool empty();
    T &operator[](int);
    void push_back(const T &);
    void pop_back();
    void clear();
    bool contains(const T &);
    void erase(int);
    template <typename U>
    static void sort(Vector &v, bool (*pFunc)(U t1, U t2))
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                if (!pFunc(v[i], v[j]))
                {
                    swap(v[i], v[j]);
                }
            }
        }
    }
    int find(const T &value)
    {
        for (int i = 0; i < this->n; i++)
        {
            if (this->p[i] == value)
            {
                return i;
            }
        }
        return -1;
    }
};

template <typename T>
int Vector<T>::n = 0;

template <typename T>
Vector<T>::Vector()
{
    this->p = new T[1];
    this->n = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T> &v)
{
    this->n = v.n;
    this->p = new T[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->p[i] = v.p[i];
    }
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] this->p;
}

template <typename T>
int Vector<T>::size()
{
    return this->n;
}

template <typename T>
bool Vector<T>::empty()
{
    return this->n == 0;
}

template <typename T>
T &Vector<T>::operator[](int i)
{
    static T defaultVal;
    if (i >= 0 && i < this->n)
        return this->p[i];
    return defaultVal;
}

template <typename T>
void Vector<T>::push_back(const T &t)
{
    T *p1 = new T[this->n + 1];
    for (int i = 0; i < this->n; i++)
    {
        p1[i] = this->p[i];
    }
    p1[this->n] = t;
    delete[] this->p;
    this->p = p1;
    this->n++;
}

template <typename T>
void Vector<T>::pop_back()
{
    if (this->n > 0)
    {
        this->n--;
        T *p1 = new T[this->n];
        for (int i = 0; i < this->n; i++)
        {
            p1[i] = this->p[i];
        }
        delete[] this->p;
        this->p = p1;
        this->n--;
    }
}

template <typename T>
void Vector<T>::clear()
{
    delete[] this->p;
    this->n = 0;
}

template <typename T>
void Vector<T>::erase(int index)
{
    if (index < 0 || index >= this->n)
        return;
    for (int i = index; i < this->n - 1; i++)
    {
        this->p[i] = this->p[i + 1];
    }
    this->n--;
}
template <typename T>
void Vector<T>::operator=(const Vector &v)
{
    this->n = v.n;
    this->p = new T[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->p[i] = v.p[i];
    }
}

#endif