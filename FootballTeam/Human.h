#include <iostream>
// #include <string>
#include <stdlib.h>
#include "../CTDL/String.h"
#include <ctime>

using namespace std;
#ifndef A_H
#define A_H
class Human
{
protected:
    String id, name, dateOfBirth, address;
    int age;

public:
    Human(String = "", String = "", String = "", String = "");
    ~Human();
    virtual void show();
    String getId();
    void setId(String);
    String getName();
    void setName(String);
    String getDateOfBirth();
    void setDateOfBirth(String);
    String getAddress();
    void setAddress(String);
    int getAge();
    void setAge(int);
    String standardizeName(String);
    int string_to_int(String);
    void setAgeByDateOfBirth(String);
};
#endif // A_H