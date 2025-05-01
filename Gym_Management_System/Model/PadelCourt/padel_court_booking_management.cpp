#include "padel_court_booking_management.h"
#include "padel_court_management.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <map>
#include <string>

using namespace std;

const string PadelCourtBookingManagement::courtBookingsFilePath = "courtBookings.txt";

multimap<int, pair<int, tm*>> PadelCourtBookingManagement::courtBookings = {};


string PadelCourtBookingManagement::bookCourt(int memberId, int courtId, tm* bookingTime)
{
	try
	{
		auto it = courtBookings.begin();
		for (; it != courtBookings.end(); ++it)
		{
			if (it->second.first == courtId && it->second.second == bookingTime)
			{
				return "Court is already booked at this time.";
			}
		}
		courtBookings.insert({memberId, {courtId, bookingTime}});
		for (auto& court : PadelCourtManagement::courts)
		{
			if (court.getId() == courtId) {
				court.reservedTimes.push_back(*bookingTime);
				break;
			}
		}
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
						// iterate through the courts to find the court with the given id
						auto courtsIt = PadelCourtManagement::courts.begin();
						for (; courtsIt != PadelCourtManagement::courts.end(); ++courtsIt)
						{
							if (courtsIt->getId() == courtId) {
								// iterate through the reserved times and remove the booking time
								auto timesIt = courtsIt->reservedTimes.begin();
								for (;timesIt != courtsIt->reservedTimes.end(); ++timesIt)
								{
									if (timesIt->tm_wday == bookingTime->tm_wday && timesIt->tm_mon == bookingTime->tm_mon &&
										timesIt->tm_hour == bookingTime->tm_hour && timesIt->tm_year == bookingTime->tm_year) {
										courtsIt->reservedTimes.erase(timesIt);
									}
								}
								break;
							}
						}
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

string PadelCourtBookingManagement::reschedualingCourtBooking(int memberId, int courtId, tm* bookingTime, tm* newTime) {
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
						// iterate through the courts to find the court with the given id
						auto courtsIt = PadelCourtManagement::courts.begin();
						for (; courtsIt != PadelCourtManagement::courts.end(); ++courtsIt)
						{
							if (courtsIt->getId() == courtId) {
								// iterate through the reserved times and remove the booking time
								auto timesIt = courtsIt->reservedTimes.begin();
								for (; timesIt != courtsIt->reservedTimes.end(); ++timesIt)
								{
									if (timesIt->tm_wday == bookingTime->tm_wday && timesIt->tm_mon == bookingTime->tm_mon &&
										timesIt->tm_hour == bookingTime->tm_hour && timesIt->tm_year == bookingTime->tm_year) {
										courtsIt->reservedTimes.erase(timesIt); // Remove the old booking time
										courtsIt->reservedTimes.push_back(*newTime); // Add the new booking time
									}
								}
								break;
							}
						}
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

string PadelCourtBookingManagement::toLine(pair<int, pair<int, tm*>> booking) {
	int memberId = booking.first;
	int courtId = booking.second.first;
	tm* timeStruct = booking.second.second;	

	string line = to_string(memberId) + "," + to_string(courtId) + "," +
		to_string(timeStruct->tm_year) + "-" + to_string(timeStruct->tm_mon) + "-" +
		to_string(timeStruct->tm_mday) + " " + to_string(timeStruct->tm_hour);
	return line;
}


string PadelCourtBookingManagement::loadDataFromFile() {

	try {
		ifstream file(courtBookingsFilePath);
		if (!file.is_open()) {
			return "Unable to open the file " + courtBookingsFilePath;
		}

		string line;
		while (getline(file, line)) {

			size_t firstComma = line.find(',');
			size_t secondComma = line.find(',', firstComma + 1);
			size_t spacePos = line.find(' ', secondComma + 1);

			if (firstComma == string::npos || secondComma == string::npos || spacePos == string::npos)
				continue;
			string dateStr = line.substr(secondComma + 1, spacePos - secondComma - 1);

			// Convert to integers
			int memberId = stoi(line.substr(0, firstComma));
			int courtId = stoi(line.substr(firstComma + 1, secondComma - firstComma - 1));
			int year, month, day;
			sscanf(dateStr.c_str(), "%d-%d-%d", &year, &month, &day);
			int hour = stoi(line.substr(spacePos + 1));

			tm* timeStruct = new tm();
			timeStruct->tm_year = year;
			timeStruct->tm_mon = month;
			timeStruct->tm_wday = day;
			timeStruct->tm_hour = hour;
			timeStruct->tm_min = 0;
			timeStruct->tm_sec = 0;

			courtBookings.insert({ memberId, { courtId, timeStruct } });
		}

		file.close();
		return "Court bookings loaded successfully.";
	}
	catch (const std::exception&) {
		return "Oops! An error happened while loading the court bookings from  file.";
	}
}



string PadelCourtBookingManagement::saveDataToFile() {
	// save court bookings to file
	try
	{
		ofstream file;
		file.open(courtBookingsFilePath);
		if (file.is_open()) {
			for (auto& booking : courtBookings)
			{
				file << toLine(booking) << endl;
			}
			file.close();
			return "Court Bookings Saved";
		}
		else {
			return "Unable to open the file " + courtBookingsFilePath;
		}
	}
	catch (const std::exception&)
	{
		return "Oops! An error happended while saving the court bookings to " + courtBookingsFilePath +" file";
	}
}




