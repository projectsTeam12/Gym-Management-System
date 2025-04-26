#ifndef WORKOUT_H
#define WORKOUT_H

#pragma once
#include <iostream>
#include "Model/Stuff/Date.h"
#include "Model/Workout&Exercises/Exercise.h"
#include <list>
using namespace std;
class Workout
{
private:
    const int Id;
    static int nextId;
    string WorkoutType;
    Date date;
    int Duration;
    list<Exercise>Exercises;
public:
    Workout(int Id, string WorkoutType, Date date, int Duration, list<Workout>Workouts);
    Workout(string WorkoutType, Date date, int Duration);
    void setWorkoutType(string WorkoutType);
    void setDate(Date date);
    void setDuration(int Duration);
    void setWorkoutslist(list<Workout>Workouts);

    int getId();
    string getWorkoutType();
    Date getDate();
    int getDuration();
    list<Workout> getWorkouts();

    void AddExercise(Exercise Ex);
};



#endif // WORKOUT_H
