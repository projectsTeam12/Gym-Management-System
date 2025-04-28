#ifndef EXERCISE_H
#define EXERCISE_H

#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Exercise
{
private:
    int Id;
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

    int getId() const;
    string getExerciseName() const;
    float getWeight() const;
    int getRepetition() const;
    string ToLine() const;


    static void SaveToFile(const string& filename, const vector<string>& vData);
    static vector<string> RecordtoLine(const list<Exercise>& Exercises);

    /// ------------------------------
    /// static map<int, Exercise> LoadExercisesToMap(const string& filename);
    /// ------------------------------
    /// 
    /// 
    /// 
    /// 
    /// 
};

#endif
