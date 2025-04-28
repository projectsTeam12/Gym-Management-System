#pragma once
#pragma once
#include <bits/stdc++.h>
#include "Receptionist.h"
using namespace std;

class ReceptionistHandler
{
private:
    vector<Receptionist> receptionists; 
    string filename;                     

public:
    ReceptionistHandler(string file);

    void addReceptionist(Receptionist r);
    void saveToFile();
    void loadFromFile();

    vector<Receptionist> getAllReceptionists();
    void displayReceptionists();
};
