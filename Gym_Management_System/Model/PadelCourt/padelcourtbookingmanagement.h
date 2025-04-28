#ifndef PADELCOURTBOOKINGMANAGEMENT_H
#define PADELCOURTBOOKINGMANAGEMENT_H

#pragma once
#include <iostream>
#include "padel_court.h"
#include <vector>
#include <unordered_map>
using namespace std;
class PadelCourtBookingManagement
{
private:
    unordered_map<int, pair<int, tm*>>CourtBooking;
public:
    static void BookCourt(int MemberId, int CourtId, tm* Time);
    static void CancelCourt(int MemberId, int CourtId, tm* Time);
    static vector<PadelCourt> GetBookingByMember(int MemberId);
    static bool ReschedualingCourtBooking(int MemberId, int CourtId, tm* Time);
};

#endif // PADELCOURTBOOKINGMANAGEMENT_H
