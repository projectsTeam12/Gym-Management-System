#pragma once
#include"person.h"
#include<vector>
class Manager : public Person
{private:
	double Revenue;
	vector<string> offers;

public:
	Manager(string name, string date, string phone, string username, string password);
	void View_Courts();  
	void add_offers(string offer);
	double calc_rev();
        void AddCoach(Coach coach);
        void AddReceptionist(Receptionist receptionist);
        void DeleteEmployee(int EmployeeId, enRole role);
        Coach SearchCoach(int CoachId);
        Receptionist SearchReceptionist(int ReceptionistId);
        vector<GymClass*> GetAllClasses();





};


