#ifndef MEMBER_H
#define MEMBER_H

#pragma once
#include <iostream>
#include "Model/PadelCourt/padelcourt.h"
#include "Model/GymClass/gymclass.h"
#include "Model/Subscription/Subscription.h"
#include "Model/Stuff/Person.h"
#include "Model/Workout&Exercises/Workout.h"
#include <list>
#include <vector>
using namespace std;
class Member : public Person
{
private:
    const int Id;
    static int nextId;
    Subscription subscription;
    list<Workout>Workouts;
public:
    Member(int Id , Subscription subsctiption , list<Workout>workouts ,
           string Name, string Phone, Date BirthOfDate, string UserName, string Password );
    Member(string Name, string Phone, Date BirthOfDate, string UserName, string Password);

    void setSubscription(Subscription subsctiption); // why do it
    void setWorkout(list<Workout>workouts);

    int getId();
    Subscription getSubscription();
    list<Workout> getworkouts();

    vector<Workout> WorkoutHistory();
    void AddWorkout(Workout workout);

    bool BookClass(int ClassId);
    void CancelBookClass(int ClassId);
    vector<GymClass*> ViewClassBooks();
    void JoinToClassWaitlist(int ClassId);
    vector<GymClass*> ViewClassesWaitlist();

    void BookCourt(int CourtId);
    void CancelBookCourt(int CourtId);
    vector<PadelCourt*> ViewCourtBooks();
    bool ReschedualingCourtBooking(int CourtId , tm*Time);
};


#endif // MEMBER_H
