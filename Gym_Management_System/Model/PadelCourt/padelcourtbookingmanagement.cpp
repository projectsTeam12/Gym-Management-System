#include "padelcourtbookingmanagement.h"
#include <iostream>

#include <vector>
#include <ctime>
#include <map>

using namespace std;

string PadelCourtBookingManagement::bookCourt(int memberId, int courtId, tm* bookingTime)
{
	try
	{
		courtBookings.insert({memberId, {courtId, bookingTime}});
		return "Booking successful";
	}
	catch (const std::exception&)
	{
		return "Oops! An error happened while booking the court";
	}
}

string PadelCourtBookingManagement::cancelBooking(int memberId, int courtId, tm* bookingTime)
{
	try
	{
		auto it = courtBookings.begin();
		for (; it != courtBookings.end(); ++it)
		{
			int key = it->first;
			while (it != courtBookings.end() && it->first == key)
			{
				if (it->first == memberId && it->second.first == courtId && it->second.second == bookingTime)
				{
					time_t convertedBookingTime = mktime(bookingTime);
					time_t currentTime = time(nullptr);
					if (difftime(convertedBookingTime, currentTime) < 3 * 60 * 60) // the difference is less than 3 hours
					{
						return "Booking cannot be canceled now as there is less than three hours to start the match.";
					}
					else
					{
						courtBookings.erase(it);
						return "Canceled booking successfully";
					}
				}
				it++;
			}
		}
		return "No booking found for the given information.";	
	}
	catch (const std::exception&)
	{
		return "Oops! An error happened while canceling the booking";
	}
}

vector<pair<int, tm*>> PadelCourtBookingManagement::getBookingByMember(int memberId) {
	vector<pair<int, tm*>> bookings;
	auto it = courtBookings.begin();
	for (; it != courtBookings.end(); ++it)
	{
		int key = it->first;
		while(it != courtBookings.end() && it->first == key)
		{
			if (it->first == memberId)
			{
				bookings.push_back({it->second.first, it->second.second});
			}
			it++;
		}	  
	}
	return bookings;
}

bool PadelCourtBookingManagement::reschedualingCourtBooking(int memberId, int courtId, tm* bookingTime, tm* newTime) {
	try
	{
		auto it = courtBookings.begin();
		for (; it != courtBookings.end(); ++it)
		{
			int key = it->first;
			while (it != courtBookings.end() && it->first == key)
			{
				if (it->first == memberId && it->second.first == courtId && it->second.second == bookingTime)
				{
					time_t convertedBookingTime = mktime(bookingTime);
					time_t currentTime = time(nullptr);
					if (difftime(convertedBookingTime, currentTime) < 3 * 60 * 60) // the difference is less than 3 hours
					{
						return "Booking cannot be rescheduled now as there is less than three hours to start the match.";
					}
					else
					{
						courtBookings.erase(it); // Remove the old booking
						courtBookings.insert({ memberId, {courtId, newTime} }); // Add the new booking
						return "Rescheduled booking successfully";
					}
				}
				it++;
			}
		}
		return "No booking found for the given information.";
	}
	catch (const std::exception&)
	{
		return "Oops! An error happened while reschedualing the booking";
	}
}


