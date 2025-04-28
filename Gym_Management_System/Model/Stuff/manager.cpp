#include "Manager.h"
#include"stuffmanagement.h"
#include"membersmanegement.h"
#include <unordered_map>
#include<iostream>

void Manager::Add_emp(string name, string date, string phone, string username, string password, double salary,string role) {
	Person(name, date, phone, username, password);
	this->salary = salary;
	this->Role = role;
	id_emp++;
	employrs.insert(make_pair(id_emp, name));
}
void Manager::Delete_emp(int id) {
	employrs.erase(id);
}
void Manager::add_offers(string offer) {
	offers.push_back(offer);
}
void Manager::calc_rev() { 
	node<int>* current = Members->head;
	double Toal_sal_sub=0;
}while (current != nullptr) {
	Total_sal_sub += current->value;
	current = curent->next;
}

Revenue=Total_sal_sub-()
}
void Manager::find_emp(int id) {
	auto it = employrs.find(id);
	if (it != employrs.end()) {
		cout << it->second;
	}
	else
		cout << "emplyed with id " << id << "  not found" << endl;
}

