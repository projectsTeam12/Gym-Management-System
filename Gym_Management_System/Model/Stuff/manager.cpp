#include "Manager.h"
#include"stuffmanagement.h"
#include"membersmanegement.h"
#include"classesmanagement.h"
#include"padel_court_management.h"
#include<iostream>


void Manager::add_offers(string offer) {
	offers.push_back(offer);
}

void Manager::calc_rev() { }
vector<padelcourt> Manager :: getAllCourts(){
	return PadelCourtManagement.getAllCourts();
}

vector<GymClass*> Manager :: GetAllClasses(){
	retrun ClassesManagement.GetAllClasses();
}

 void Manager::AddCoach(Coach coach) {
        stuffManagement.AddCoach(coach);
    }
void Manager::AddReceptionist(Receptionist receptionist){
	stuffManagement.AddReceptionist(receptionist);
}
    bool Manager::DeleteEmployee(int EmployeeId, enRole role) {
        return stuffManagement.DeleteEmployee(EmployeeId, role);
    }
    Coach Manager::SearchCoach(int CoachId) {
        return stuffManagement.SearchCoach(CoachId);
    }
    Receptionist Manager:: SearchReceptionist(int ReceptionistId){
return stuffManagement.SearchReceptionist(ReceptinistId);
    }

};
