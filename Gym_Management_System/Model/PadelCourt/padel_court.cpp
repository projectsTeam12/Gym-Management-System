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

PadelCourt::setIsAvailable(bool IsAvailable)
{
	this->IsAvailable = IsAvailable;
}

PadelCourt::setLocation(string Location)
{
	this->Location = Location;
}

PadelCourt::setprice(float Price)
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
