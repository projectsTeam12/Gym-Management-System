#include<bits/stdc++.h>
#include "Workout.h"
#include "Exercise.h"
using namespace std;

int main() {
    
    list<Exercise> exercises = {
        Exercise("Push Up", 20, 122),
        Exercise("Lat Pulldown", 50, 1002),
        Exercise("Squats", 180, 80)
    };

    list<Exercise> exercises1 = {
        Exercise("Push Up", 20, 10),
        Exercise("Lat Pulldown", 50, 12),
        Exercise("Squats", 180, 8)
    };

    
    vector<string> data = Exercise::RecordtoLine(exercises);
    Exercise::SaveToFile("exercises.txt", data);

    vector<string> data1 = Exercise::RecordtoLine(exercises1);
    Exercise::SaveToFile("exercises.txt", data1);

   
    Workout test1(1, "push", 60, exercises);
    Workout test2(2, "pull", 45, exercises1);

    
    list<string> workoutData;
    workoutData.push_back(test1.ToLine1());
    workoutData.push_back(test2.ToLine1());
    Workout::SaveToFile1("workouts.txt", workoutData);

    
    list<Workout> allWorkouts = { test1, test2 };
    Workout::SaveWorkoutToFile("combined.txt", allWorkouts);

    cout << "succ\n";

 
    return 0;
}
