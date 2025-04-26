#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#pragma once
#include <iostream>
#include "Model/Stuff/Date.h"
#include "Model/Stuff/Person.h"
using namespace std;
class Receptionist : public Person
{
private:
    const int Id;
    static int nextId;
public:
    Receptionist(int Id, string Name, string Phone, Date BirthOfDate, string UserName, string Password);
    Receptionist(string Name, string Phone, Date BirthOfDate, string UserName, string Password);
};


#endif // RECEPTIONIST_H
