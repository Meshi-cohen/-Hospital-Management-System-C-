// SURGEON.h
#ifndef SURGEON_H
#define SURGEON_H

#include "Doctor.h"


class Surgeon : public Doctor
{

protected:

    int number;

public:
    Surgeon(const string& name, const string& expert,const int n);
    Surgeon(const Surgeon& other);
    Surgeon(const Doctor& other, const int numOfS);
    const Surgeon& operator=(const Doctor& other) = delete;
    const int getNumberofSurg() const { return number; };
    bool setNumberofSurg(const int n);
    virtual Employee* clone() const override { return new Surgeon(*this); };
    friend ostream& operator<<(ostream& os, const Surgeon& s);
    friend class Hospital;
};

#endif // SURGEON_H

