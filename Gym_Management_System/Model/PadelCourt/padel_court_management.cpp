#include "padel_court_management.h"
#include "padel_court.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



PadelCourtManagement::PadelCourtManagement() {
	// Load courts from file
	ifstream file;
	file.open("courts.txt");
	if (file.is_open()) {
		string line;
		while (file >> line) {
			PadelCourt court = PadelCourt(line);
			courts.push_back(court);
		}
		file.close();
	}
}



string PadelCourtManagement::addCourt(bool isAvailable, string location, float price)
{
	fstream file;
	try
	{
		file.open("courts.txt", ios::out | ios::app);
		PadelCourt court = PadelCourt(isAvailable, location, price);
		courts.push_back(court);
		file << toLine(court);
		file.close();
		return "Court Added";
	}
	catch (const exception&)
	{
		file.close();
		return "an error happended while adding a court";
	}
	
}

string PadelCourtManagement::toLine(PadelCourt padelCourt)
{
	return to_string(padelCourt.getId()) + "," + to_string(padelCourt.getIsAvailable()) + "," + padelCourt.getLocation() + "," + to_string(padelCourt.getPrice()) + "\n";
}
