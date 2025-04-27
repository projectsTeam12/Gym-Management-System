#ifndef COACH_H
#define COACH_H

#pragma once
#include <iostream>
#include "Model/Stuff/stDate.h"
#include "Model/Stuff/Person.h"
#include <vector>
#include "Model/GymClass/gymclass.h"
class Coach : public Person
{
private:
    const int Id;
    static int nextId;
public:
    Coach(int Id, string Name, string Phone, stDate BirthOfDate, string UserName, string Password);
    Coach(string Name, string Phone, stDate BirthOfDate, string UserName, string Password);
    static vector<GymClass*>GetClasses();
};



#endif // COACH_H
