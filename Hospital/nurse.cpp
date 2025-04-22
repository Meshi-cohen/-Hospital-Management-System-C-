#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "nurse.h"

Nurse::Nurse(const string& name, int exp):Employee(name), experience(exp)
{
    this->dep = nullptr;
}

Nurse::Nurse(const Nurse& other):Employee(other)
{
    experience = other.experience;
    dep = other.dep;
}

bool Nurse::setExperience(int exp)
{
    experience = exp;
    return true;
}

bool Nurse::setDepartment(Department* department)
{
    dep = department;
    return true;
}

ostream& operator<<(ostream& os, const Nurse& n)
{
    os << "Nurse name: " << n.name << endl
        << "Nurse badgeID: " << n.badgeID << endl
        << "Nurse experience (in years): " << n.experience << endl;
    return os;
}
