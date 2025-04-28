#include "Person.h"
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
	cout << Name;
}
string Person::getDate() {
	cout << Date;
}
string Person::getPhone() {
	cout << Phone;
}
string Person::getUserName() {
	cout << UserName;
}
string Person::getPassWord() {
	cout<<PassWord;
}
