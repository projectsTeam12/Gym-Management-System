
#pragma once
#include <bits/stdc++.h>
#include "Model/Stuff/Date.h"
#include "Model/Stuff/Person.h"
using namespace std;

enum Shift {Moring , Afternoon , Night };
class Receptionist : public Person
{
private:
    const int receptionistID;
    Shift shift;


public:
    Receptionist(int Id, string Name,
        Shift shift, string Phone , date BirthDate , string UserName, string passwd);
    // getters
    string get_name();
    int get_phone();
    date get_BirthDate();
    string get_UserName();
    string get_passwd();
    int get_id();
    Shift get_shift();


    // setters

    void set_name(string name);
    void set_phone(int phone);
    void set_BirthDate(date BirthDate);
    void set_UserName(string UserName);
    void set_passwd(string passwd);
    void set_id(int id);
    Shift set_shift(Shift shift);

   

};


#endif // RECEPTIONIST_H
