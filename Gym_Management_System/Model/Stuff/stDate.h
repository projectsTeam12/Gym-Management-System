#ifndef STDATE_H
#define STDATE_H
#pragma once

#include <ctime>

struct stDate
{
    int Day;
    int Month;
    int Year;

    // Constructor
    stDate(int d = 1, int m = 1, int y = 1900) : Day(d), Month(m), Year(y) {}



    // Method to set current date
    void SetToCurrentDate() {
        time_t t = time(0);
        tm* now = localtime(&t);
        Day = now->tm_mday;
        Month = now->tm_mon + 1;
        Year = now->tm_year + 1900;
    }
};

#endif // STDATE_H
