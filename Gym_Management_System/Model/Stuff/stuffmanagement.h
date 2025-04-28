#ifndef STUFFMANAGEMENT_H
#define STUFFMANAGEMENT_H

#pragma once
#include <iostream>
#include "Model/Stuff/receptionist.h"
#include "Model/Stuff/coach.h"
#include "Model/Stuff/enRole.h"
#include <list>
class StuffManagement
{
private:
    list<Coach>Coaches;
    list<Receptionist>Receptionists;
public:
    void AddCoach(Coach coach);
    void AddReceptionist(Receptionist receptionist);
    void DeleteEmployee(int EmployeeId, enRole role);
    Receptionist SearchReceptionist(int ReceptionistId);
};


#endif // STUFFMANAGEMENT_H
