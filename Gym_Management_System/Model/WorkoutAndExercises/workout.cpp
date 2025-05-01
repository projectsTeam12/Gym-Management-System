#include "Workout.h"
#include "Exercise.h"
#include<bits/stdc++.h>
#include <fstream>
#include<string>
int Workout::nextId=1;

// constructors

Workout::Workout() {

}

Workout::Workout(int Id, string WorkoutType, int Duration, list<Exercise> Exercises) {
	this->Id = nextId++;
	this->WorkoutType = WorkoutType;
	this->Duration = Duration;
	this->Exercises = Exercises;
}

Workout::Workout(string WorkoutType, int Duration) {
	this->Id = nextId++;
	this->WorkoutType = WorkoutType;
	this->Duration = Duration;
}

Workout::Workout(const Workout& other)
{
	Id = other.Id;
	WorkoutType = other.WorkoutType;
	Duration = other.Duration;
	Exercises = other.Exercises; 
}

// setter
void Workout::setId(int Id) {
	this->Id=Id;
}

void Workout::setWorkoutType(string WorkoutType) {
	this->WorkoutType = WorkoutType;
}

void Workout::setDuration(int Duration) {
	this->Duration = Duration;
}

void Workout::setExercisesList(list<Exercise> Exercises) {
	this->Exercises = Exercises;
}

// getter 

int Workout::getId() const {
	return Id;
}

string Workout::getWorkoutType() const {
	return WorkoutType;
}

int Workout::getDuration() const {
	return Duration;
}

list<Exercise> Workout::getExercises() const {
	return Exercises;
}

// =================================================
// File operations
string Workout::ToLine1() const {
    stringstream ss;
    ss << Id << "," << WorkoutType << "," << Duration;

    for (const Exercise& ex : Exercises) {
        ss << "," << ex.getId();
    }

    return ss.str();
}

list<string> Workout::RecordtoLine1(const list<Workout>& Workouts) {
    list<string> vData;
    for (const Workout& workout : Workouts) {
        vData.push_back(workout.ToLine1());
    }
    return vData;
}

void Workout::SaveToFile1(const string& filename, const list<string>& vData) {
    fstream myfile(filename, ios::app);
    if (myfile.is_open()) {
        for (const auto& line : vData) {
            if (!line.empty()) {
                myfile << line << endl;
            }
        }
        myfile << "-------------------\n";
        myfile.close();
    }
    else {
        cerr << "ERROR --|> can't open file: " << filename << endl;
    }
}


void Workout::SaveWorkoutToFile(const string& filename, const list<Workout>& workouts) {
    fstream myfile(filename, ios::app);

    if (myfile.is_open()) {
        for (const auto& workout : workouts) {
            myfile << "WorkoutType -->> " << workout.getWorkoutType() << endl;
            myfile << "Duration -->> " << workout.getDuration() << endl;

            const auto& exercises = workout.getExercises();
            for (const auto& ex : exercises) {
                myfile << ex.getExerciseName() << ","
                    << ex.getWeight() << ","
                    << ex.getRepetition() << endl;
            }

            myfile << "-------------------" << endl;
        }
        myfile.close();
    }
    else {
        cerr << "ERROR --|> can't open file: " << filename << endl;
    }
}
