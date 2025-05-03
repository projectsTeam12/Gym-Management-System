#ifndef PADELCOURTMANAGEMENT_H
#define PADELCOURTMANAGEMENT_H

#pragma once
#include <iostream>
#include <vector>
#include "padel_court.h" // Ensure this is included to resolve PadelCourt type

using namespace std;
class PadelCourtManagement
{
public:
	static vector<PadelCourt> courts;
	static const string courtsFilePath;
PadelCourtManagement();
~PadelCourtManagement();

	void addCourt(string location, float price);
   void DeleteCourt(int CourtId);
   vector<PadelCourt> SearchCourt(tm* time, string location);
   string toLine(PadelCourt padelCourt);
   vector<PadelCourt> getAllCourts();
   vector<string> loadDataFromFile();
   void saveDataToFile(vector<string> lines);
};

#endif // PADELCOURTMANAGEMENT_H
