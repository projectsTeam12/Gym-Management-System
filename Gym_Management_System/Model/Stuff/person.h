#ifndef PERSON_H
#define PERSON_H

#pragma once
#include <iostream>
#include "Model/Stuff/stDate.h"
using namespace std;
class Person
{
protected:
    string Name;
    string Phone;
    stDate BirthDate;
    string UserName;
    string Password;
public:
    Person(string Name, string Phone, stDate BirthDate, string UserName, string Password);

    //Getter
    string getName() const;
    string getPhone() const;
    stDate& getBirthDate() const;
    string getUserName() const;
    string getPassword() const;

    //Setter
    void setName(string Name);
    void setPhone(string Phone);
    void setBirthDate(stDate BirthDate);
    void setUserName(string UserName);
    void setPassword(string Password);

    
};



#endif // PERSON_H
