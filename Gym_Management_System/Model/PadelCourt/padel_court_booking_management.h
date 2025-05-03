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
   static multimap<int, pair<int, tm*>> courtBookings;
public:
	static const string courtBookingsFilePath;
    void bookCourt(int memberId, int courtId, tm* bookingTime);
    void cancelBooking(int memberId, int courtId, tm* bookingTime);
    vector<pair<int, tm*>> getBookingByMember(int memberId);
    void reschedualingCourtBooking(int memberId, int courtId, tm* bookingTime, tm* newTime);
    string toLine(pair<int, pair<int, tm*>> booking);

    vector<string> loadDataFromFile();
    void saveDataToFile(vector<string> lines);
};

#endif // PADELCOURTBOOKINGMANAGEMENT_H
