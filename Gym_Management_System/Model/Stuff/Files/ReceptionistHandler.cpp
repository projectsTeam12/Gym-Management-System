#include "ReceptionistHandler.h"
#include "receptionist_Model.h"
#include "stDate.h"
ReceptionistHandler::ReceptionistHandler(string file)
{
    filename = file;
    loadFromFile();
}


void ReceptionistHandler::addReceptionist(Receptionist r)
{
    receptionists.push_back(r);
    saveToFile();
}


void ReceptionistHandler::saveToFile() {
    // 1
    fstream file("receptionist_file.txt", ios::out | ios::app);

    // 2
    if (file.is_open())
    {

        for (auto r : receptionists)
        {
            file << r.get_id() << " "
                << r.get_name() << " "
                << r.get_shift() << " "
                << r.get_phone() << " "
                << r.get_BirthDate().day << "-"
                << r.get_BirthDate().month << "-"
                << r.get_BirthDate().year << " "
                << r.get_UserName() << " "
                << r.get_passwd() << endl;
        }
    }
    else { cout << "Error opening file!" << endl; }

    // 3
    file.close();
}



#include <fstream>

void ReceptionistHandler::loadFromFile() {
    // 1
    fstream file(filename, ios::in);  

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    // 2
    receptionists.clear();

    // 3 
    int id, phone, day, month, year, shift;
    string name, username, password;
    char dash; 

    while (file >> id >> name >> shift >> phone >> day >> dash >> month >> dash >> year >> username >> password) {

        stDate birthDate = ( day, month, year );

     // 4
        Receptionist r(id, name, (Shift)shift, to_string(phone), birthDate, username, password);
        receptionists.push_back(r);
    }

    file.close();
}



vector<Receptionist> ReceptionistHandler::getAllReceptionists()
{
    return receptionists;
}


void  ReceptionistHandler::displayReceptionists()
{
    for (const auto& r : receptionists) 
    {
        cout << "ID: " << r.get_id() << ", Name: " << r.get_name()
             << ", Shift: " << r.get_shift() << ", Phone: " << r.get_phone()
             << ", Birth Date: " << r.get_BirthDate().Day << "/" << r.get_BirthDate().Month << "/" << r.get_BirthDate().Year
             << ", Username: " << r.get_UserName() << endl;
    }
}


