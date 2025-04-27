#include "receptionist_Model.h"

Receptionist(int Id, string Name, Shift shift, string Phone, date BirthDate, string UserName, string passwd)
	: receptionistID(Id), Name(Name), shift(shift), Phone(Phone), BirthDate(BirthDate), UserName(UserName), passwd(passwd) {
}

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
	return receptionistID;
}

Shift Receptionist::get_shift() {
	return shift;
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
	receptionistID = id;
}
void set_shift(Shift shift) {
	this->shift = shift;
}

