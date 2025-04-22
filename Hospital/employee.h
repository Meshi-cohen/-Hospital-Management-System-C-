// EMPLOYEE.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include "person.h"

class Employee : public Person
{
protected:

    static int IDcounter;
    int badgeID;

public:
    Employee(const string& name);
    Employee(const Employee& other);
    const Employee& operator=(const Employee& other) = delete;
    int getID()                const { return badgeID; };
    virtual Employee* clone() const = 0;
    virtual void toOs(ostream& os) const {};
    friend ostream& operator<<(ostream& os, const Employee& e);
    friend class Hospital;
    friend class ResearchCenter;
};

#endif // EMPLOYEE.H
