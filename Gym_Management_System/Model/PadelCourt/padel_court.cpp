#include "padelcourt.h"
#include<iostream>
using namespace std;

PadelCourt::PadelCourt(int Id, bool IsAvailable, string Location, float Price)
{
	this->Id = Id;
	this->IsAvailable = IsAvailable;
	this->Location = Location;
	this->Price = Price;
}
PadelCourt::PadelCourt(float Price)
{
	this->Id = nextid++;
	this->IsAvailable = true;	
	this->Location = "Unknown";
	this->Price = Price;
}	

void PadelCourt::setIsAvailable(bool IsAvailable)
{
	this->IsAvailable = IsAvailable;
}

void PadelCourt::setLocation(string Location)
{
	this->Location = Location;
}

void PadelCourt::setprice(float Price)
{
	this->Price = Price;
}

int PadelCourt::getId()
{
	return this->Id;
}
bool PadelCourt::getIsAvailable()
{
	return this->IsAvailable;
}

string PadelCourt::getLocation()
{
	return this->Location;
}

float PadelCourt::getPrice()
{
	return this->Price;
}
 
bool PadelCourt::isAvailableAt(tm* Time)     //added by sw;
{
	if (!this->IsAvailable) return false; 

	for (auto& reserved : ReservedTimes)
	{
		if (reserved.tm_year == Time->tm_year &&
			reserved.tm_mon == Time->tm_mon &&
			reserved.tm_mday == Time->tm_mday &&
			reserved.tm_hour == Time->tm_hour)
		{
			return false; 
		}
	}
	return true; 
}
