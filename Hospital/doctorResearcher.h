// DOCTORRESEARCHER_H
#ifndef DOCTORRESEARCHER_H
#define DOCTORRESEARCHER_H

#include "doctor.h"
#include "researcher.h"

class DoctorResearcher :public Doctor, public Researcher
{
private:

public:

    DoctorResearcher(const string& name, const string& expert);
    DoctorResearcher(const DoctorResearcher& other);
    virtual Employee* clone() const override { return new DoctorResearcher(*this); };

};


#endif // DOCTORRESEARCHER_H

