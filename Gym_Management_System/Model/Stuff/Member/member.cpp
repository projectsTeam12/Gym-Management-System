#include "member.h"
#include "Model/GymClass/classesbookingmanagement.h"
#include "Model/PadelCourt/padelcourtbookingmanagement.h"

Member::Member(int Id, std::string Name, std::string Phone, stDate BirthDate, std::string UserName,
               std::string Password, Subscription subscription, std::vector<Workout> workouts)
    : Person(Name, Phone, BirthDate, UserName, Password)
{
    this->Id=Id;
    this->subscription = subscription;
    this->Workouts = workouts;
}

Member::Member(std::string Name, std::string Phone, stDate BirthDate, std::string UserName,
       std::string Password, Subscription subscription)
    : Person(Name, Phone, BirthDate, UserName, Password)
{
    this->subscription = subscription;

}

// Getter
int Member::getId() const {return this->Id;}
Subscription Member::getSubscription() const{return this->subscription;}
vector<Workout> Member::getWorkoutHistory() const {return this->Workouts;}

// Setter
void Member::setSubscription(Subscription subsctiption) {this->subscription =subsctiption;}
void Member::setWorkout(vector<Workout>workouts) {this->Workouts=workouts;}

void Member::AddWorkout(Workout workout){this->Workouts.push_back(workout) ;}

// Classes Management
void Member::BookClass(int ClassId){ClassesBookingManagement::BookClass(ClassId,this->Id);}
void Member::CancelBookClass(int ClassId){ClassesBookingManagement::CancelBook(ClassId,this->Id);}
vector<GymClass> Member::ViewClassBooks() const {return ClassesBookingManagement::getBookingByMember(this->Id);};
void Member::JoinToClassWaitlist(int ClassId) {ClassesBookingManagement::JoinToWaitlist(ClassId,this->Id);}
vector<GymClass> Member::ViewClassesWaitlist() const { return ClassesBookingManagement::getWaitlistsForMember(this->Id);}

// Court Management
void Member::BookCourt(int CourtId, tm*Time) {PadelCourtBookingManagement::BookCourt(this->Id ,CourtId ,Time);}
void Member::CancelBookCourt(int CourtId , tm*Time) {PadelCourtBookingManagement::CancelCourt(this->Id ,CourtId ,Time);}
vector<PadelCourt> Member::ViewCourtBooks(){return PadelCourtBookingManagement::GetBookingByMember(this->Id);}
void Member::ReschedualingCourtBooking(int CourtId , tm*Time){PadelCourtBookingManagement::ReschedualingCourtBooking(this->Id,CourtId,Time);}
