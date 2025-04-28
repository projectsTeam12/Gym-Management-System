#pragma once
#include"person.h"
#include<vector>
class Manager : public Person
{private:
	double Revenue;
	string Role;
	vector<string> offers;

public:
	Manager(string name, string date, string phone, string username, string password);
	void View_Courts();
	void Viwe_classes();   
	void add_offers(string offer);
	double calc_rev();



};


