#include "Exercise.h"
#include<bits/stdc++.h>
#include <fstream>
int Exercise::nextId = 1;


// constructors
Exercise::Exercise(int Id, string ExerciseName, float Weight, int Repetition) {
    this->Id = nextId++;
    this->ExerciseName = ExerciseName;
    this->Weight = Weight;
    this->Repetition = Repetition;
}

Exercise::Exercise(string ExerciseName, float Weight, int Repetition) {
    this->Id = nextId++;
    this->ExerciseName = ExerciseName;
    this->Weight = Weight;
    this->Repetition = Repetition;
}

// setter
void Exercise::setExerciseName(string ExerciseName) {
    this->ExerciseName = ExerciseName;
}

void Exercise::setWeight(float Weight) {
    this->Weight = Weight;
}

void Exercise::setRepetition(int Repetition) {
    this->Repetition = Repetition;
}

// getter
int Exercise::getId() const {
    return Id;
}

string Exercise::getExerciseName() const {
    return ExerciseName;
}

float Exercise::getWeight() const {
    return Weight;
}

int Exercise::getRepetition() const {
    return Repetition;
}

// ================================================================


string Exercise::ToLine() const {
    return to_string(Id) + "," + ExerciseName + "," + to_string(Weight) + "," + to_string(Repetition);
}

vector<string> Exercise::RecordtoLine(const list<Exercise>& Exercises) {
    vector<string> vData;
    for (const Exercise& exercise : Exercises) {
        vData.push_back(exercise.ToLine());
    }
    return vData;
}

void Exercise::SaveToFile(const string& filename, const vector<string>& vData) {
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
        cerr << "ERROR --|> can't open file: " << endl;
    }


}
////---------------------------------------------------------------------------
