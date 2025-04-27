#ifndef MANAGER_H
#define MANAGER_H

#pragma once
#include <iostream>
#include "Model/Stuff/Person.h"
class Manager : public Person
{
public:
    Manager(string Name, string Phone, stDate BirthDate, string UserName, string Password);
};


#endif // MANAGER_H
