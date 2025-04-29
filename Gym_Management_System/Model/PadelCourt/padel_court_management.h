#ifndef PADELCOURTMANAGEMENT_H
#define PADELCOURTMANAGEMENT_H

#pragma once
#include <iostream>
#include <vector>
#include "padel_court.h" // Ensure this is included to resolve PadelCourt type

using namespace std;
class PadelCourtManagement
{
private:
  vector<PadelCourt> courts;
public:
PadelCourtManagement();
~PadelCourtManagement();

   string addCourt(string location, float price);
   void DeleteCourt(int CourtId);
   vector<PadelCourt*> SearchCourt(tm* time, string location);
   string toLine(PadelCourt padelCourt);
   vector<PadelCourt> getAllCourts();
   string loadDataFromFile();
   string saveDataToFile();
};

#endif // PADELCOURTMANAGEMENT_H
