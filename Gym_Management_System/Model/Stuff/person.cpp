#include "person.h"
#include<iostream>
Person::Person(string name, string date, string phone, string username, string password) {
	this->Name = name;
	this->Date = date;
	this->Phone = phone;
	this->UserName = username;
	this->PassWord = password;
}
void Person::setName(string name) {
	Name = name;
}
void Person::setDate(string date) {
	Date = date;
}
void Person::setPhone(string phone) {
	Phone = phone;
}
void Person::setUserName(string username) {
	UserName = username;
}
void Person::setPassWord(string password) {
	PassWord = password;
}
string Person::getName() {
	return Name;
}
string Person::getDate() {
	return Date;
}
string Person::getPhone() {
	return Phone;
}
string Person::getUserName() {
	return UserName;
}
string Person::getPassWord() {
	return PassWord;
}
