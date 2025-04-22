// DOCTOR.h
#ifndef DOCTOR_H
#define DOCTOR_H
using namespace std;
#include "employee.h"

class Department;

class Doctor : virtual public Employee
{

protected:

    string expertise;
    Department* dep;

public:
    Doctor(const string& name, const string& expertise);
    Doctor(const Doctor& other);
    const Doctor& operator=(const Doctor& other) = delete;
    const string getExpertise() const { return expertise; };
    bool setExpertise(const string& expertise);
    bool setDepartment(Department* depart);
    virtual Employee* clone() const override { return new Doctor(*this); };
    friend ostream& operator<<(ostream& os, const Doctor& d);

    friend class Hospital;
};

#endif // DOCTOR_H
