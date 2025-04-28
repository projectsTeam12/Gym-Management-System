#pragma once
#include"string"
using namespace std;
class Person
{
private:
	string Name;
	string Date;
	string Phone;
	string UserName;
	string PassWord;
public:
	Person(string name, string date, string phone, string username, string password);
	void setName(string  name);
	void setPhone(string  prhone);
	void setUserName(string  username);
	void setPassWord(string  password);
	void setDate(string  date);
    string getName();
	string getPhone();
	string getUserName();
	string getPassWord();
	string getDate();

};


