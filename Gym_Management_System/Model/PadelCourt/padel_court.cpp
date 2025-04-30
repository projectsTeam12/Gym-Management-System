#include "padel_court.h"
#include "padel_court_management.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string PadelCourt::idFilePath = "id.txt";

PadelCourt::PadelCourt(string Location, float Price)
{
	setAutomaticId();
	this->reservedTimes = {};
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
            location = token;
            break;
        case 2:
            price = stof(line);
            break;
        }
        line.erase(0, pos + 1);
        fieldIndex++;
    }
    int  pos1 = line.find('_');
    int pos2 = line.find('_', pos1 + 1);
    int spacePos = line.find(' ');
	tm date = {};
	date.tm_year = stoi(line.substr(0, pos1)); 
	date.tm_mon = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1)); 
	date.tm_wday = stoi(line.substr(pos2 + 1, spacePos - pos2 - 1)); 
	date.tm_hour = stoi(line.substr(spacePos + 1));
	reservedTimes.push_back(date);
   
    
}	
void PadelCourt::setAutomaticId() {
    ifstream readFile;
    readFile.open(idFilePath);
    if (readFile.is_open()) {
        readFile >> this->id;
        readFile.close();
        ofstream writeFile;
        writeFile.open(idFilePath);
        writeFile << this->id + 1;
        writeFile.close();
    }
    else {
        return;
    }
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


string PadelCourt::getLocation()
{
	return this->location;
}

float PadelCourt::getPrice()
{
	return this->price;
}
 
bool PadelCourt::isAvailableAt(tm* time)  
{
	for (auto& reserved : reservedTimes)
	{
		if (reserved.tm_year == time->tm_year &&
			reserved.tm_mon == time->tm_mon &&
			reserved.tm_mday == time->tm_mday &&
			reserved.tm_hour == time->tm_hour)
		{
			return false; 
		}
	}
	return true; 
}
vector<tm> PadelCourt::getReservedTimes() {
    return reservedTimes;
}
