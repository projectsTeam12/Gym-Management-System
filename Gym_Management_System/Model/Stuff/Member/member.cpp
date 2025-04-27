#include "member.h"

Member::Member(int Id, std::string Name, std::string Phone, stDate BirthDate, std::string UserName,
               std::string Password, Subscription subscription, std::vector<Workout> workouts)
    : Person(Name, Phone, BirthDate, UserName, Password)
{
    this->subscription = subscription;
    this->Workouts = workouts;
}
