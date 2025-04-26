#ifndef CLASSESBOOKINGMANAGEMENT_H
#define CLASSESBOOKINGMANAGEMENT_H

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include "Model/GymClass/gymclass.h"
class ClassesBookingManagement
{
private:
    static unordered_map<int, vector<int>>BookingClasses; // <ClassId , MembersId>
    static unordered_map<int, deque<int>>WaitlistClasses; // <ClassId , MembersId>
public:
    static bool BookClass(int ClassId, int MemberId);
    static bool CancelBook(int ClassId, int MemberId);
    static void JoinToWaitlist(int ClassId, int MemberId);
    static vector<GymClass*> getBookingByMember(int MemberId);
    static vector<GymClass*> getWaitlistsForMember(int MemberId);
};

#endif // CLASSESBOOKINGMANAGEMENT_H
