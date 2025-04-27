#ifndef PADELCOURT_H
#define PADELCOURT_H

#pragma once
#include <iostream>
using namespace std;
class PadelCourt
{
private:
    int Id; // added automatically
    static int nextid;
    bool IsAvailable;
    //tm* StartTime;
    string Location;
    float Price;
public:
    PadelCourt(int Id, bool IsAvailable, string Location, float Price);
    PadelCourt(float Price);
    void setIsAvailable(bool IsAvailable);
    void setLocation(string Location);
    void setprice(float Price);
    int getId();
    bool getIsAvailable();
    string getLocation();
    float getPrice();
};


#endif // PADELCOURT_H
