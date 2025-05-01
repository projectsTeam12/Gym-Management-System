#pragma once
#include"person.h"
#include"stuffmanagement.h"
#include"membersmanegement.h"
#include"classesmanagement.h"
#include"padel_court_management.h"
#include<vector>
class Manager : public Person
{private:
	vector<string> offers;

public:
	Manager(string name, string date, string phone, string username, string password);
	vector<padelcourt> getAllCourts();
	void add_offers(string offer);
        float calculateTotalSubscriptions()
        void AddCoach(Coach coach);
        void AddReceptionist(Receptionist receptionist);
        bool DeleteEmployee(int EmployeeId, enRole role);
        Coach SearchCoach(int CoachId);
        Receptionist SearchReceptionist(int ReceptionistId);
        vector<GymClass*> GetAllClasses();





};


