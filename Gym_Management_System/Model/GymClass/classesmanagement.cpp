#include "classesmanagement.h"



void ClassesManagement::AddClass(GymClass Class)
{
	Classes.push_back(Class);
	auto it == --Classes.end();
	mp_Classes[Class.getId()] = it;
}


unordered_map<int, list<GymClass>::iterator>::iterator ClassesManagement::FindClassById(int ClassId) {
	return mp_Classes.find(ClassId);
}


void ClassesManagement::DeleteClass(int ClassId) {

	auto it = FindClassById(ClassId);
	if (it != mp_Classes.end()) 
	{
		Classes.erase(it->second);
		mp_Classes.erase(it);
	}
	
}


void ClassesManagement::ReschedualTime_Date(int ClassId, tm* Time, enDays Day) {

	auto it = FindClassById(ClassId); 
	if (it != mp_Classes.end()) 
	{
		GymClass& classToReschedule = it->second;
		classToReschedule.setStartTime(Time);
		classToReschedule.setDay(Day);
	}
}




GymClass* ClassesManagement::SearchClass(int ClassId) {

	auto it = FindClassById(ClassId);  
	if (it != mp_Classes.end()) 
	{
		return &(it->second);
	}

}

Coach* ClassesManagement::GetCoachById(int CoachId) {
	for (auto& coach : Coaches) {
		if (coach.Id == CoachId) {
			return &coach;  
		}
	}


vector<GymClass*> ClassesManagement::GetCoachClasses(int CoachId) 
{

	vector<GymClass*> coachClasses;

		Coach* coachPtr = GetCoachById(CoachId);

		if (coachPtr != nullptr) {
			coachClasses = coachPtr->GetClasses();
		}

	return coachClasses;
}


vector<GymClass*> ClassesManagement::GetAllClasses()
{
	vector<GymClass*> allClasses;

	for (auto& classItem : mp_Classes) {
		allClasses.push_back(&(classItem.second));
	}

	return allClasses;
}