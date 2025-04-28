#include "Manager.h"
#include"stuffmanagement.h"
#include"membersmanegement.h"
#include"classesmanagement.h"
#include<iostream>


void Manager::add_offers(string offer) {
	offers.push_back(offer);
}

void Manager::calc_rev() { }

vector<GymClass> GetAllClasses(){
	retrun ClassesManagement::GetAllClasses();
}

 void Manager::AddCoach(Coach coach) {
        staffManagement.AddCoach(coach);
    }
    bool Manager::DeleteEmployee(int EmployeeId, enRole role) {
        return staffManagement.DeleteEmployee(EmployeeId, role);
    }
    Coach Manager::SearchCoach(int CoachId) {
        return staffManagement.SearchCoach(CoachId);
    }
};
