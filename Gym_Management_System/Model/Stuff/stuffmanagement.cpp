#include "stuffmanagement.h"
void StuffManagement::AddCoach(Coach coach) {
	Coaches.push_back(coach);
}
void StuffManagement::AddReceptionist(Receptionist receptionist) {
	Receptionists.push_back(receptionist);
	}
bool StuffManagement::DeleteEmployee(int EmployeeId, enRole role)
{
    if (role == enRole::coach)
    {
        for (auto it = Coaches.begin(); it != Coaches.end(); ++it)
        {
            if (it->Getid() == EmployeeId)
            {
                Coaches.erase(it);
                return true;
            }
        }
    }
    else if (role == enRole::receptionist)
    {
        for (auto it = Receptionists.begin(); it != Receptionists.end(); ++it)
        {
            if (it->GetId() == EmployeeId)
            {
                Receptionists.erase(it);
                return true;
            }
        }
    }

    return false;
}
Coach StuffManagement::SearchCoach(int CoachId)
{
    for (auto it = Coaches.begin(); it != Coaches.end(); ++it)
    {
        if (it->GetId() == CoachId)
        {
            return *it;
        }
    }

    throw runtime_error("Coach not found!");
}
Receptionist StuffManagement::SearchReceptionist(int ReceptionistId)
{
    for (auto it = Receptionists.begin(); it != Receptionists.end(); ++it)
    {
        if (it->GetId() == ReceptionistId)
        {
            return *it;
        }
    }

    throw runtime_error("Receptionist not found!");
}





