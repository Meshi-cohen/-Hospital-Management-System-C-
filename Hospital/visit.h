// VISIT.h
#ifndef VISIT_H
#define VISIT_H
using namespace std;

#include "date.h"

class Employee;
class Department;
class Paitent;

class Visit
{

protected:

    Paitent* p;
    Date arrival;
    string purpose;
    Employee* mainStaffMember;
    Department* dep;

public:
    Visit(const Date& arrive, const string& purp);
    Visit(const Visit& other);
    const Visit& operator=(const Visit& other) = delete;
    bool setPaitent(Paitent* ptn);
    bool setStaff(Employee* e);
    bool setDepartment(Department* d);
    Paitent* getPatient()         const { return p; };
    Date getArrival()             const { return arrival; };
    const string getPurpose()      const { return purpose; };
    Employee* getMainStaff()      const { return mainStaffMember; }
    Department* getDepartment()   const { return dep; };
    friend class Hospital;

};

#endif // VISIT_H
