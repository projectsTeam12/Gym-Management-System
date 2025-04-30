#ifndef PADELCOURTBOOKINGMANAGEMENT_H
#define PADELCOURTBOOKINGMANAGEMENT_H

#pragma once
#include <iostream>
#include "padel_court.h"
#include <vector>
#include <map>
using namespace std;
class PadelCourtBookingManagement
{
private:
    multimap<int, pair<int, tm*>>courtBookings;
public:
    string bookCourt(int memberId, int courtId, tm* bookingTime);
    string cancelBooking(int memberId, int courtId, tm* bookingTime);
    vector<pair<int, tm*>> getBookingByMember(int memberId);
    bool reschedualingCourtBooking(int memberId, int courtId, tm* bookingTime, tm* newTime);
};

#endif // PADELCOURTBOOKINGMANAGEMENT_H
