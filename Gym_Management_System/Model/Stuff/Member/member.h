#ifndef MEMBER_H
#define MEMBER_H

#pragma once
#include "Model/PadelCourt/padelcourt.h"
#include "Model/GymClass/gymclass.h"
#include "Model/Subscription/Subscription.h"
#include "Model/Stuff/stDate.h"
#include "Model/WorkoutAndExercises/Workout.h"
#include "Model/Stuff/Person.h"

#include "Model/Stuff/Person.h"
#include <vector>
class Member : public Person
{
private:
    int Id;
    static int nextId;
    Subscription subscription;
    vector<Workout>Workouts;
public:
    // Constructor For Load Data form file 

    Member(int Id , string Name, string Phone, stDate BirthDate,  string UserName,
        string Password, Subscription subsctiption , vector<Workout>workouts);

    // Constructor For Create New Member 

    Member(string Name, string Phone, stDate BirthDate, string UserName, string Password 
        ,Subscription subsctiption);
    
    // Getter
    int getId() const;
    Subscription getSubscription() const;
    vector<Workout> getWorkoutHistory() const;

    // Setter
    void setSubscription(Subscription subsctiption); 
    void setWorkout(vector<Workout>workouts);

    void AddWorkout(Workout workout);

    // Classes Management
    void BookClass(int ClassId);
    void CancelBookClass(int ClassId);
    vector<GymClass> ViewClassBooks() const;
    void JoinToClassWaitlist(int ClassId);
    vector<GymClass> ViewClassesWaitlist() const ;

    // Court Management
    void BookCourt(int CourtId ,tm*Time);
    void CancelBookCourt(int CourtId,tm*Time);
    vector<PadelCourt> ViewCourtBooks();
    void ReschedualingCourtBooking(int CourtId , tm*Time);
};


#endif // MEMBER_H
