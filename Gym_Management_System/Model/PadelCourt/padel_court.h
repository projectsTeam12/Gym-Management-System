#ifndef PADELCOURT_H
#define PADELCOURT_H

#pragma once
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
class PadelCourt
{
private:
    int id; // added automatically
    string location;
    float price;
    vector<tm> reservedTimes;
public:
    PadelCourt( string Location, float Price);
    PadelCourt(string line);
    
    void setAutomaticId();

    void setLocation(string Location);
    void setprice(float Price);

    int getId();
   
    string getLocation();
    float getPrice();
	vector<tm> getReservedTimes();
    bool isAvailableAt(tm* time);  
};


#endif // PADELCOURT_H
