#include "receptionist_Model.h"


// getters
string  Receptionist::get_name() {
	retrun Name;
}
int  Receptionist::get_phone() {
	return Phone;
}
date  Receptionist::get_BirthDate() {
	return BirthOfDate;
}
string  Receptionist::get_UserName() {
	return UserName;
}
string  Receptionist::get_passwd() {
	return Password;
}
int  Receptionist::get_id() {
	return Id;
}


// setters

void  Receptionist::set_name(string name)
{
	Name = name;
}
void  Receptionist::set_phone(int phone) {
	Phone=phone ;
}
void  Receptionist::set_BirthDate(date BirthDate) {
	BirthOfDate = BirthDate;
}
void  Receptionist::set_UserName(string UserName) {
	this->UserName = UserName;
}
void  Receptionist::set_passwd(string passwd) {
	Password= passwd;
}
void  Receptionist::set_id(int id) {
     Id = id;
}


