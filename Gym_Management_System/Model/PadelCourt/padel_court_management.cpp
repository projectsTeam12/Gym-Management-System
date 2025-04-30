#include "padel_court_management.h"
#include "padel_court.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


PadelCourtManagement::PadelCourtManagement() {
	
}

PadelCourtManagement::~PadelCourtManagement() {

}

string PadelCourtManagement::loadDataFromFile() {
	// Load courts including reserved times from file
	try
	{
		ifstream file;
		file.open("courts.txt");
		if (file.is_open()) {
			string line;
			while (file >> line) {
				PadelCourt court = PadelCourt(line);
				courts.push_back(court);
			}
			file.close();
			return "Courts Loaded";
		}
		else {
			return "Unable to open the file 'courts.txt'";
		}
	}
	catch (const std::exception&)
	{
		return "Oops! An error happended while loading the courts from 'courts.txt' file";
	}
	
}


string PadelCourtManagement::saveDataToFile() {
	// save courts including reserved times to file
	try
	{
		ofstream file;
		file.open("courts.txt");
		if (file.is_open()) {
			string line;
			for (auto& court : courts)
			{
				file << toLine(court) << endl;
			}
			file.close();
			return "Courts Loaded";
		}
		else {
			return "Unable to open the file 'courts.txt'";
		}
	}
	catch (const std::exception&)
	{
		return "Oops! An error happended while saving the courts to 'courts.txt' file";
	}
}






string PadelCourtManagement::addCourt(string location, float price)
{
	
	PadelCourt court = PadelCourt(location, price);
	courts.push_back(court);
	
	return "Court Added";
}

void PadelCourtManagement::DeleteCourt(int CourtId)
{
	for (auto it = courts.begin(); it != courts.end(); )
	{
		if (it->getId() == CourtId)
		{
			courts.erase(it);
			break;
		}
	}
}

vector<PadelCourt> PadelCourtManagement::getAllCourts()
{
	return courts;
}
vector<PadelCourt*> PadelCourtManagement::SearchCourt(tm* time, string location)
{
	vector<PadelCourt*> foundCourts;

	for (auto& court : courts)
	{
		if (court.getLocation() == location && court.isAvailableAt(time))
		{
			foundCourts.push_back(&court);
		}
	}
	return foundCourts;
}

string PadelCourtManagement::toLine(PadelCourt padelCourt)
{
	string reseredTimesLine = "";
	for (auto& resTime : padelCourt.getReservedTimes())
	{
		reseredTimesLine += to_string(resTime.tm_year) + "-" + to_string(resTime.tm_mon) + "-" + to_string(resTime.tm_mday) + " " +
			to_string(resTime.tm_hour);
	}
	return to_string(padelCourt.getId()) + "," + padelCourt.getLocation() + "," + to_string(padelCourt.getPrice()) +"," + reseredTimesLine;
}
