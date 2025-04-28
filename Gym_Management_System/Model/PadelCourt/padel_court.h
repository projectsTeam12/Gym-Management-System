#ifndef PADELCOURT_H
#define PADELCOURT_H

#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class PadelCourt
{
private:
    int id; // added automatically
    bool isAvailable;
    //tm* StartTime;
    string location;
    float price;
    vector<tm> ReservedTimes;
public:
    PadelCourt(bool IsAvailable, string Location, float Price);
    PadelCourt(string line);
    PadelCourt toLine(PadelCourt padelCourt);
    void setAutomaticId();
    void setIsAvailable(bool IsAvailable);
    void setLocation(string Location);
    void setprice(float Price);

    int getId();
    bool getIsAvailable();
    string getLocation();
    float getPrice();
    bool isAvailableAt(tm* Time);   // new by sw
};


#endif // PADELCOURT_H
