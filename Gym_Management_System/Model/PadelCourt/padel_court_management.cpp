#include "padel_court_management.h"
#include "padel_court.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

const string PadelCourtManagement::courtsFilePath = "courts.txt";
 
vector<PadelCourt> PadelCourtManagement::courts = {};

PadelCourtManagement::PadelCourtManagement() {
	
}

PadelCourtManagement::~PadelCourtManagement() {

}

vector<string> PadelCourtManagement::loadDataFromFile() {
	// Load courts including reserved times from file
	vector<string> lines;
	ifstream file;
	file.open(courtsFilePath);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			lines.push_back(line);
			/*PadelCourt court = PadelCourt(line);
			courts.push_back(court);*/
		}
		file.close();
	}
	return lines;
}


void PadelCourtManagement::saveDataToFile(vector<string> lines) {
	// save courts including reserved times to file
		ofstream file;
		file.open(courtsFilePath);
		if (file.is_open()) {
			for (auto& line : lines)
			{
				//file << toLine(court) << endl;
				file << line << endl;
			}
			file.close();
		}
}






void PadelCourtManagement::addCourt(string location, float price)
{
	PadelCourt court = PadelCourt(location, price);
	courts.push_back(court);
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

vector<PadelCourt> PadelCourtManagement::SearchCourt(tm* time, string location)
{
	vector<PadelCourt> foundCourts;

	for (auto& court : courts)
	{
		if (court.getLocation() == location && court.isAvailableAt(time))
		{
			foundCourts.push_back(court);
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
