#ifndef EXERCISE_H
#define EXERCISE_H

#pragma once
#include <iostream>
using namespace std;
class Exercise
{
private:
    const int Id;
    static int nextId;
    string ExerciseName;
    float Weight;
    int Repetition;
public:
    Exercise(int Id, string ExerciseName, float Weight, int Repetition);
    Exercise(string ExerciseName, float Weight, int Repetition);
    void setExerciseName(string ExerciseName);
    void setWeight(float Weight);
    void setRepetition(int Repetition);

    int getId();
    string getExerciseName();
    float gerWeight();
    int gerRepetition();
};


#endif // EXERCISE_H
