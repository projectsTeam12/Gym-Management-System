#include "Model/GymClass/classesbookingmanagement.h"

void ReceptionistController::Add_Member(Member member) {
    Member.push_back(member);
}



void ReceptionistController::delete_member(int Id) 
{
    for (auto it = Members.begin(); it != Members.end(); it++)
    {
        if (it->getId == Id)
            Member.erase(it);
    }

    return;
}



void ReceptionistController::edit_member(int Id) 
{
	for (Member& member : Menmbers) 
    {

		if (member.getId() == Id) 
        {
			int choice
             switch (choice)
             {
                case 1: {
                    string newName;
                    cin >> newName;
                    member.setName(newName);
                    break;
                }
                case 2: {
                    string newPhone;
                    cin >> newPhone;
                    member.setPhone(newPhone);
                    break;
                }
                case 3: {
                    string newUsername;
                    cin >> newUsername;
                    member.setUserName(newUsername);
                    break;
                }
                case 4: {
                    string newPassword;
                    cin >> newPassword;
                    member.setPassword(newPassword);
                    break;
                }
                case 5: {
                    stDate newBirthDate;
                    cin >> newBirthDate.Day;
                    cin >> newBirthDate.Month;
                    cin >> newBirthDate.Year;
                    member.setBirthDate(newBirthDate);
                    break;
                }
                default: {
                    /////////////////////////////////////
                }

             }
		}
	}
    return;

}




Member SearchMemberInfo(int Id) 
{
    for (Member& member : Members)
    {
        if (member.getId() == Id)
            return member;
    }

}



vector<Member*> getExpiringMemberShipList() {
    vector<Member*> expiring;
    for (Member& member : Members) {
        if (member.getSubscription().getStatus() == Expired) {
            expiring.push_back(&member);
        }
    }
    return expiring;

}

void ReceptionistController::Renew_sub(int Id)
{
    for (Member& member : Members) {
        if (member.getId() == Id)
        {
            Subscription newSubscription;
            member.setSubscription(newSubscription);
        }

}

