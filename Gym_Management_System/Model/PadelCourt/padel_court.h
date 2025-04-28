#ifndef PADELCOURT_H
#define PADELCOURT_H

#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class PadelCourt
{
private:
    int Id; 
    static int nextid;
    bool IsAvailable;
    string Location;
    float Price;
    vector<tm> ReservedTimes; // added by saif wa!

public:
    PadelCourt(int Id, bool IsAvailable, string Location, float Price);
    PadelCourt(float Price);
    void setIsAvailable(bool IsAvailable);
    void setLocation(string Location);
    void setprice(float Price);
    int getId();
    bool getIsAvailable();
    bool isAvailableAt(tm* Time);   // new by sw
    string getLocation();
    float getPrice();
};


#endif // PADELCOURT_H
