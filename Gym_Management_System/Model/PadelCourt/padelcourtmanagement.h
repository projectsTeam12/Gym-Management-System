#ifndef PADELCOURTMANAGEMENT_H
#define PADELCOURTMANAGEMENT_H

#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "Model/PadelCourt/padelcourt.h"
using namespace std;
class PadelCourtManagement
{
private:
    static list<PadelCourt>Courts;
public:
    static void AddCourt(PadelCourt Court);
    static void DeleteCourt(int CourtId);
    static vector<PadelCourt*> SearchCourt(tm* Time, string Location);
};

#endif // PADELCOURTMANAGEMENT_H
