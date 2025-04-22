#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "visit.h"

Visit::Visit(const Date& arrive, const string& purp): arrival(arrive)
{
    this->purpose = purp;
    this->mainStaffMember = nullptr;
    this->p = nullptr;
    this->dep = nullptr;
}

Visit::Visit(const Visit& other):arrival(other.arrival)
{
    this->p = other.p;
    this->mainStaffMember = other.mainStaffMember;
    this->purpose = other.purpose;
    this->dep = other.dep;
}


bool Visit::setPaitent(Paitent* ptn)
{
    this->p = ptn;
    return true;
}

bool Visit::setStaff(Employee* e)
{
    this->mainStaffMember = e;
    return true;
}

bool Visit::setDepartment(Department* d)
{
    this->dep = d;
    return true;
}