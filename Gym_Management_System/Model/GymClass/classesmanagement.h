#ifndef CLASSESMANAGEMENT_H
#define CLASSESMANAGEMENT_H

#pragma once
#include <iostream>
#include "Model/GymClass/gymclass.h"
#include "Model/Stuff/coach.h"
#include <vector>
#include <list>
#include <unordered_map>
class ClassesManagement
{
private:
    list<GymClass>Classes;
    list<Coach> Coaches;
    unordered_map<int, list<GymClass>::iterator> mp_Classes; // this is for the classId and an iterator
    unordered_map<int, vector<int>> CoachClasses;  // coachId and his classesID
   
public:

   void AddClass(GymClass Class);
   void DeleteClass(int ClassId);
   void ReschedualTime_Date(int ClassId , tm* Time, enDays Day);
   unordered_map<int, list<GymClass>::iterator>::iterator FindClassById(int ClassId);
   GymClass* SearchClass(int ClassId);
   Coach* GetCoachById(int CoachId);
   vector<GymClass*> GetCoachClasses(int CoachId);
   vector<GymClass*> GetAllClasses();
   



};

#endif // CLASSESMANAGEMENT_H
