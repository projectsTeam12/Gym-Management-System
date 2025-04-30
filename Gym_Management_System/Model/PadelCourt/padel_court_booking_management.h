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
   static multimap<int, pair<int, tm*>>courtBookings;
public:
	static const string courtBookingsFilePath;
    string bookCourt(int memberId, int courtId, tm* bookingTime);
    string cancelBooking(int memberId, int courtId, tm* bookingTime);
    vector<pair<int, tm*>> getBookingByMember(int memberId);
    string reschedualingCourtBooking(int memberId, int courtId, tm* bookingTime, tm* newTime);
    string toLine(pair<int, pair<int, tm*>> booking);

    string loadDataFromFile();
    string saveDataToFile();
};

#endif // PADELCOURTBOOKINGMANAGEMENT_H
