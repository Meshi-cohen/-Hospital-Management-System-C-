#pragma warning (disable: 4996)
#include <iostream>
using namespace std;


#include "doctorResearcher.h"

DoctorResearcher::DoctorResearcher(const string& name, const string& expert): Employee(name) ,Doctor(name, expert), Researcher(name) { }

DoctorResearcher::DoctorResearcher(const DoctorResearcher& other) : Employee(other), Doctor(other), Researcher(other) { }

