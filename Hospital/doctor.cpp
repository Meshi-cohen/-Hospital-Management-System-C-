#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "doctor.h"


Doctor::Doctor(const string& name, const string& expert):Employee(name)
{
    this->expertise = expert;
    this->dep = nullptr;
}

Doctor::Doctor(const Doctor& other):Employee(other)
{
    this->expertise = other.expertise;
    dep = other.dep;
}

bool Doctor::setExpertise(const string& expert)
{
    expertise = expert;
    return true;
}

bool Doctor::setDepartment(Department* depart)
{
    dep = depart;
    return true;
}

ostream& operator<<(ostream& os, const Doctor& d)
{
    os << "Doctor name: " << d.name << endl
       << "Doctor badgeID: " << d.badgeID << endl
       << "Doctor expertise: " << d.expertise << endl;
    return os;
}
