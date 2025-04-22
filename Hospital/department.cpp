#pragma warning (disable: 4996)
#pragma warning (disable: 6386)
#pragma warning (disable: 6385)
#include <iostream>
using namespace std;

#include "department.h"
#include "paitent.h"

Department::Department(const string& name)
{
    this->name = name;
}

Department::Department(Department&& other) noexcept
{
    *this = move(other);

}

Department& Department::operator=(Department&& other) noexcept
{
    if (this != &other) 
    {
        name = move(other.name);
        DoctorsInDepartment = move(other.DoctorsInDepartment);
        NursesInDepartment = move(other.NursesInDepartment);
        VisitInDepartment = move(other.VisitInDepartment);
    }
    return *this;
}

bool Department::addDoctor(Doctor& d)
{
    DoctorsInDepartment.push_back(&d);
    vector<Doctor*>::iterator itrEnd = --DoctorsInDepartment.end();
    (*itrEnd)->setDepartment(this);
    return true;
}

bool Department::addNurse(Nurse& n)
{
    NursesInDepartment.push_back(&n);
    vector<Nurse*>::iterator itrEnd = --NursesInDepartment.end();
    (*itrEnd)->setDepartment(this);
    return true;
}

bool Department::addVisittoDepartment(Visit& v)
{
    VisitInDepartment.push_back(&v);
    vector<Visit*>::iterator itrEnd = --VisitInDepartment.end();
    (*itrEnd)->setDepartment(this);
    return true;
}

ostream& operator<<(ostream& os, const Department& d)
{
    vector<Visit*>::const_iterator itr = d.VisitInDepartment.begin();
    vector<Visit*>::const_iterator itrEnd = d.VisitInDepartment.end();
    os << "The Paitent in the department are: " << endl;
    for (; itr != itrEnd; ++itr)
        os << *((*itr)->getPatient());
    return os;
}
