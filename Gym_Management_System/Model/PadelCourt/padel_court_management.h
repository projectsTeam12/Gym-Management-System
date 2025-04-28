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

   string addCourt(bool isAvailable, string location, float price);
   void DeleteCourt(int CourtId);
   vector<PadelCourt*> SearchCourt(tm* Time, string Location);
   string toLine(PadelCourt padelCourt); // Ensure the type PadelCourt is correctly declared here
};

#endif // PADELCOURTMANAGEMENT_H
