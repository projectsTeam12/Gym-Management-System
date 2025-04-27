#ifndef GYMCLASS_H
#define GYMCLASS_H

#pragma once
#include <iostream>
#include <ctime>
using namespace std;
enum enDays { Saturday, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday };
class GymClass
{
private:
    int Id;
    static int nextid;
    string Name;
    int Capacity;
    int EnrollmentMembers = 0;
    bool IsAvailable;
    tm* StartTime;
    enDays Day;
    float Price;
public:
    GymClass(int Id, string Name, int Capacity, bool IsAvailable, tm* StartTime, enDays Day, float Price);
    GymClass(string Name, int Capacity, float Price);
    void setName(string Name);
    void setCapacity(int Capacity);
    void setIsAvailable(bool IsAvailable);
    void setStartTime(tm* StartTime);
    void setDay(enDays Day);
    void setPrice(float Price);
    int getId()const;
    string getName()const;
    int getCapacity()const;
    int getEnrollmentMembers()const;
    bool getIsAvailable()const;
    tm* getStartTime()const;
    enDays getDay()const;
    float getPrice()const;
};


#endif // GYMCLASS_H
