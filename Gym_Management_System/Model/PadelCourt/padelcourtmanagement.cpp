#include "padelcourtmanagement.h"

list<PadelCourt> PadelCourtManagement::Courts;

void PadelCourtManagement::AddCourt(PadelCourt Court)
{
    Courts.push_back(Court);
}



void PadelCourtManagement::DeleteCourt(int CourtId)
{
    for (auto it = Courts.begin(); it != Courts.end(); ++it)
    {
        if (it->getId() == CourtId)
        {
            Courts.erase(it);
            break; 
        }
    }
}


vector<PadelCourt*> PadelCourtManagement::SearchCourt(tm* Time, string Location)
{
    vector<PadelCourt*> foundCourts;

    for (auto& court : Courts)
    {
        if (court.getLocation() == Location && court.isAvailableAt(Time))
        {
            foundCourts.push_back(&court);
        }
    }

    return foundCourts;
}