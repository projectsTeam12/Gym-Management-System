#ifndef WORKOUT_H
#define WORKOUT_H

#pragma once
#include "Exercise.h"
#include <list>
using namespace std;

class Workout
{
private:
    int Id;
    static int nextId;
    string WorkoutType;
    int Duration;
    list<Exercise> Exercises; 

public:
    Workout();
    Workout(int Id, string WorkoutType, int Duration, list<Exercise> Exercises); 
    Workout(string WorkoutType, int Duration);
    Workout(const Workout& other);
    void setId(int Id);
    void setWorkoutType(string WorkoutType);
    void setDuration(int Duration);
    void setExercisesList(list<Exercise> Exercises);

    int getId() const;
    string getWorkoutType() const ;
    int getDuration()const;
    list<Exercise> getExercises() const; 

    void AddExercise(Exercise Ex);// file ??????

    // ------------------------------------
    string ToLine1() const;
    static void SaveToFile1(const string& filename, const list<string>& vData);
    static list<string> RecordtoLine1(const list<Workout>& Workouts);
    // ------------------------------------
    static void SaveWorkoutToFile(const string& filename, const list<Workout>& workouts);


};

#endif // WORKOUT_H
