// NURSE.h
#ifndef NURSE_H
#define NURSE_H

#include "employee.h"

class Department;

class Nurse : public Employee
{
private:
    
    int experience;
    Department* dep;

public:
    Nurse(const string& name, int exp);
    Nurse(const Nurse& other);
    const Nurse& operator=(const Nurse& other) = delete;
    int getExperience()        const { return experience; };
    bool setExperience(int exp);
    bool setDepartment(Department* department);
    friend ostream& operator<<(ostream& os, const Nurse& n);
    virtual Employee* clone() const override { return new Nurse(*this); };
    friend class Hospital;
};

#endif // NURSE_H

