#include "Manager.h"
#include"stuffmanagement.h"
#include"membersmanegement.h"
#include"classesmanagement.h"
#include"padel_court_management.h"
#include<iostream>


Manager::Manager(string name, string date, string phone, string username, string password) {
    this->setName(name);
    this->setDate(date);
    this->setPhone(phone);
    this->setUserName(username);
    this->setPassWord(password);
}
void Manager::add_offers(string offer) {
	offers.push_back(offer);
}

    float Manager :: calculateTotalSubscriptions() {
        float total = 0.0f;
        for (const auto& member : Members) {
            total += member.getSubscription().getPrice();
        }
        return total;
    }
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
