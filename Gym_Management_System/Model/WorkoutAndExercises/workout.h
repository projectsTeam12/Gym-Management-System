#ifndef WORKOUT_H
#define WORKOUT_H

#pragma once
#include "Model/Stuff/stDate.h"
#include "Model/WorkoutAndExercises/Exercise.h"
#include <list>
using namespace std;
class Workout
{
private:
    int Id;
    static int nextId;
    string WorkoutType;
    stDate date;
    int Duration;
    list<Exercise>Exercises;
public:
    Workout();
    Workout(int Id, string WorkoutType, stDate date, int Duration, list<Workout>Workouts);
    Workout(string WorkoutType, stDate date, int Duration);
    Workout(const Workout& other);

    void setWorkoutType(string WorkoutType);
    void setDate(stDate date);
    void setDuration(int Duration);
    void setWorkoutslist(list<Workout>Workouts);

    int getId();
    string getWorkoutType();
    stDate getDate();
    int getDuration();
    list<Workout> getWorkouts();

    void AddExercise(Exercise Ex);
};



#endif // WORKOUT_H
