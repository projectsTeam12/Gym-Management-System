#ifndef CLASSESMANAGEMENT_H
#define CLASSESMANAGEMENT_H

#pragma once
#include <iostream>
#include "Model/GymClass/gymclass.h"
#include <vector>
#include <list>
#include <unordered_map>
class ClassesManagement
{
private:
    static list<GymClass>Classes;
    static unordered_map<int, list<GymClass>::iterator>mp_Classes;
    static unordered_map<int, vector<int>>CoachClasses;
    static unordered_map<int, list<GymClass>::iterator>::iterator FindClassById(int ClassId);
public:
    static void AddClass(GymClass Class);
    static void DeleteClass(int ClassId);
    static void ReschedualTime_Date(int ClassId , tm* Time, enDays Day);
    static GymClass* SearchClass(int ClassId);
    static vector<GymClass*> GetCoachClasses(int CoachId);
    static vector<GymClass*> GetAllClasses();
};

#endif // CLASSESMANAGEMENT_H
