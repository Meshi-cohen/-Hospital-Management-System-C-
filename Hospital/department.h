// DEPARTMENT.h
#ifndef DEPARTMENT_H
#define DEPARTMENT_H
using namespace std;
#include <vector>
#include "surgeon.h"
#include "nurse.h"
#include "visit.h"

class Department
{
private:

    string name;
    vector <Doctor*> DoctorsInDepartment;
    vector <Nurse*> NursesInDepartment;
    vector <Visit*> VisitInDepartment;

public:
    Department(const string& name);
    Department(const Department&) = delete;
    Department& operator=(const Department&) = delete;
    Department(Department&& other) noexcept;
    Department& operator=(Department&& other) noexcept;
    const string getName()              const { return name; };
    bool addDoctor(Doctor& d);
    bool addNurse(Nurse& n);
    bool addVisittoDepartment(Visit& v);
    friend ostream& operator<<(ostream& os, const Department& d);

    friend class Hospital;
};

#endif // DEPARTMENT_H