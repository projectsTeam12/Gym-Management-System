#include "padel_court.h"
#include "padel_court_management.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

PadelCourt::PadelCourt(bool IsAvailable, string Location, float Price)
{
	setAutomaticId();
    this->isAvailable = IsAvailable;
    this->location = Location;
    this->price = Price;
}
PadelCourt::PadelCourt(string line)
{
    size_t pos = 0;
    string token;
    int fieldIndex = 0;

    while ((pos = line.find(',')) != string::npos) {
        token = line.substr(0, pos);
        switch (fieldIndex) {
        case 0:
            id = stoi(token);
            break;
        case 1:
            isAvailable = (token == "true");
            break;
        case 2:
            location = token;
            break;
        }
        line.erase(0, pos + 1);
        fieldIndex++;
    }
   
    price = stof(line);
}	
void PadelCourt::setAutomaticId() {
	ifstream readFile;
    readFile.open("id.txt");
    if (readFile.is_open()) {
        readFile >> this->id;
        readFile.close();
		ofstream writeFile;
		writeFile.open("id.txt");
		writeFile << this->id + 1;
        writeFile.close();
    }
    else {
        return;
    }

}
void PadelCourt::setIsAvailable(bool IsAvailable)
{
	this->isAvailable = IsAvailable;
}

void PadelCourt::setLocation(string Location)
{
	this->location = Location;
}

void PadelCourt::setprice(float Price)
{
    this->price = Price;
}

int PadelCourt::getId()
{
	return this->id;
}
bool PadelCourt::getIsAvailable()
{
	return this->isAvailable;
}

string PadelCourt::getLocation()
{
	return this->location;
}

float PadelCourt::getPrice()
{
	return this->price;
}
