#ifndef S_H
#define S_H

#include <iostream>
using namespace std;
#include <algorithm>
#include <cstring>

class String
{
private:
    char *m;
    size_t s;
    size_t max;

public:
    String() : m(new char[1]), s(0)
    {
        *m = '\0';
    }
    String(char c)
    {
        m = new char[1];
        char *p = &c;
        strcpy(m, p);
        this->s = 1;
        this->max = 1;
    }
    String(const char *str) : s(strlen(str))
    {
        m = new char[s + 1];
        strcpy(m, str);
    }

    String(const String &other) : s(other.s)
    {
        m = new char[s + 1];
        strcpy(m, other.m);
    }

    ~String()
    {
        delete[] m;
    }

    bool empty() const
    {
        return s == 0;
    }

    void push_back(char c)
    {
        if (s + 1 >= max)
        {
            max = s + 1;
            char *tmp = new char[max];
            strcpy(tmp, m);
            delete[] m;
            m = tmp;
        }
        m[s] = c;
        m[s + 1] = '\0';
        ++s;
    }
    void insert(size_t pos, const String &str)
    {
        if (pos > s)
            pos = s; // Neu vi tri chen lon hon kich thuoc cua chuoi thi chen vo cuoi
        size_t newLen = s + str.s;
        char *newStr = new char[newLen + 1];
        strncpy(newStr, m, pos);               // Copy all ky tu tu m den pos vo chuoi moi
        strncpy(newStr + pos, str.m, str.s);   // Copy all ky tu tu str.m vao chuoi moi
        strcpy(newStr + pos + str.s, m + pos); // Copy all ky tu con lai
        delete[] m;
        m = newStr;
        s = newLen;
    }

    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] m;
            s = other.s;
            m = new char[s + 1];
            strcpy(m, other.m);
        }
        return *this;
    }

    size_t size() const
    {
        return s;
    }

    // template<typename T>
    String operator+(const String &other) const
    {
        String newString;
        newString.s = s + other.s;
        delete[] newString.m;
        newString.m = new char[newString.s + 1];
        strcpy(newString.m, m);
        strcat(newString.m, other.m);
        return newString;
    }

    const char &operator[](size_t index) const
    {
        return m[index];
    }

    friend ostream &operator<<(ostream &o, const String &str)
    {
        o << str.m;
        return o;
    }
    bool operator==(const String &other)
    {
        if (this->s != other.s)
            return false;
        else
        {
            for (int i = 0; i < this->s; i++)
            {
                if (this->m[i] != other[i])
                    return false;
            }
        }
        return true;
    }
    bool operator!=(const String &other)
    {
        if (this->s != other.s)
            return true;
        else
        {
            for (int i = 0; i < this->s; i++)
            {
                if (this->m[i] != other[i])
                    return true;
            }
        }
        return false;
    }
    static void getline(istream &i, String &str, char delim = '\n')
    {
        char buffer[256];
        i.getline(buffer, 256, delim);
        str = buffer;
    }

    static String tostring(int num)
    {
        String result;
        bool isNegative = false; // check so am
        if (num < 0)
        {
            isNegative = true;
            num = -num;
        }
        if (num == 0)
            return "0";
        while (num > 0)
        {
            char digit = '0' + (num % 10); // chuyen so thanh ky tu tuong ung
            result.push_back(digit);
            num /= 10;
        }
        if (isNegative)
            result.push_back('-');                   // them dau am vao cuoi chuoi neu la so am
        reverse(result.m, result.m + result.size()); // dao nguoc chuoi de dung thu tu
        return result;
    }

    static int toint(const String &s)
    {
        int result = 0;
        int sign = 1;
        int i = 0;
        if (s[0] == '-')
        {
            sign = -1;
            i = 1;
        }
        for (; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                result = result * 10 + (s[i] - '0');
        }
        return result * sign;
    }
    static String standadizeDay(String d)
    {
        String tmp("0");
        if (d[1] == '/')
            d = tmp + d;
        if (d[4] == '/')
            d.insert(3, "0");
        return d;
    }
    static String standadizeString(String s)
    {
        String tmp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0)
                tmp = tmp + toupper(s[0]);
            else
            {
                if (s[i - 1] == ' ')
                    tmp = tmp + toupper(s[i]);
                else
                    tmp = tmp + tolower(s[i]);
            }
        }
        return tmp;
    }
    void toCharArray(char a[])
    {
        for (int i = 0; i < this->size(); i++)
        {
            a[i] = this->m[i];
        }
    }
};

#endif