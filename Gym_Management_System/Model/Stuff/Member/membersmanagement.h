#ifndef MEMBERSMANAGEMENT_H
#define MEMBERSMANAGEMENT_H

#pragma once
#include <iostream>
#include "Model/Stuff/Member/member.h"
#include "bits/stdc++.h"
using namespace std;
class MembersManagement
{
private:
    list<Member>Members;
public:
	void Add_Member(Member member);
	void edit_member(int Id);
	void delete_member(int Id)
	Member SearchMemberInfo(int Id);
	vector<Member*> getExpiringMemberShipList();
	void Renew_sub((int Id);
};



#endif // MEMBERSMANAGEMENT_H
