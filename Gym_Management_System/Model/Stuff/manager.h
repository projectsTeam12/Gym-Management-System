#pragma once
#include<unordered_map>
#include"person.h"
#include<vector>
class Manager : public Person
{private:
	double Revenue;
	int id_emp=0;
	double salary;
	string Role;
	unordered_map<int, string>employrs;
	vector<string> offers;

public:
	//Manager(string name, string date, string phone, string username, string password);
	void Add_emp(string name, string date, string phone, string username, string password,double salary,string role);
	void find_emp(int id);
	void Delete_emp(int id);
	void View_Courts();
	void Viwe_classes();   
	void add_offers(string offer);
	double calc_rev();



};


