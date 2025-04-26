#ifndef PERSON_H
#define PERSON_H

#pragma once
#include <iostream>
#include "Model/Stuff/Date.h"
using namespace std;
class Person
{
protected:
    string Name;
    string Phone;
    Date BirthOfDate;
    string UserName;
    string Password;
public:
    Person(string Name, string Phone, Date BirthOfDate, string UserName, string Password);

    void setName(string Name);
    void setPhone(string Phone);
    void setDateOfBirth(Date BithOfDate);
    void setUserName(string UserName);
    void setPassword(string Password);

    string getName();
    string getPhone();
    Date getBirthOfDate();
    string getUserName();
    string getPassword();
};



#endif // PERSON_H
