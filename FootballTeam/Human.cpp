#include "Human.h"
String Human::standardizeName(String s)
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

Human::Human(String m, String t, String ns, String ad)
    : id(m), dateOfBirth(ns), address(ad)
{
    this->name = this->standardizeName(t);
    this->setAgeByDateOfBirth(ns);
}

Human::~Human()
{
}

void Human::show()
{
    cout << this->id << ", " << this->name << ", " << this->dateOfBirth << ", " << this->address << ", " << this->age << endl;
}

String Human::getId()
{
    return this->id;
}

void Human::setId(String id)
{
    this->id = id;
}

String Human::getName()
{
    return this->name;
}

void Human::setName(String name)
{
    this->name = name;
}

String Human::getDateOfBirth()
{
    return this->dateOfBirth;
}

void Human::setDateOfBirth(String dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

String Human::getAddress()
{
    return this->address;
}

void Human::setAddress(String address)
{
    this->address = address;
}

int Human::getAge()
{
    return this->age;
}

void Human::setAge(int age)
{
    this->age = age;
}

// int Human::string_to_int(String x)
//{
//     char a[x.size()];
//     for (int i = 0; i < x.size(); i++)
//     {
//         a[i] = x[i];
//     }
//     return atoi(a);
// }
//  13/10/2004

void Human::setAgeByDateOfBirth(String date)
{
    int d = 0, m = 0, y = 0;
    for (int i = 0; i < date.size(); i++)
    {
        if (date[i] == '/')
            continue;
        if (i <= 2)
            d = d * 10 + String::toint(date[i]);
        else if (i <= 4)
            m = m * 10 + String::toint(date[i]);
        else if (i <= 9)
            y = y * 10 + String::toint(date[i]);
    }
    time_t t = time(0);
    tm *now = localtime(&t);
    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;
    int day = now->tm_mday;
    if (month > m)
    {
        this->age = year - y;
    }
    else if (month < m)
    {
        this->age = year - y - 1;
    }
    else
    {
        if (day >= d)
        {
            this->age = year - y;
        }
        else
        {
            this->age = year - y - 1;
        }
    }
}
