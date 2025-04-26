#ifndef MEMBERSMANAGEMENT_H
#define MEMBERSMANAGEMENT_H

#pragma once
#include <iostream>
#include "Model/Stuff/Member/member.h"
using namespace std;
class MembersManagement
{
private:
    list<Member>Members;
public:
    void AddMember(Member member);
    bool RemoveMember(Member member);
    vector<Member*> SearchMemberInfo(int MemberId);
    vector<Member*> getExpiringMemberShipList();
};



#endif // MEMBERSMANAGEMENT_H
