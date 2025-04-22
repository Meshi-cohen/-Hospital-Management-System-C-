#pragma warning (disable: 4996)
#include <iostream>
using namespace std;


#include "surgeon.h"

Surgeon::Surgeon(const string& name, const string& expert, const int n) : Employee(name), Doctor(name, expert)
{
	number = n;
}

Surgeon::Surgeon(const Surgeon& other):Employee(other), Doctor(other)
{
	this->number = other.number;
}

Surgeon::Surgeon(const Doctor& other, const int numOfS): Employee(other), Doctor(other)
{
	this->number = numOfS;
}

bool Surgeon::setNumberofSurg(const int n)
{
	number = n;
	return true;
}

ostream& operator<<(ostream& os, const Surgeon& s)
{
	os << "Surgeon name: " << s.name << endl
		<< "Surgeon badgeID: " << s.badgeID << endl
		<< "Surgeon expertise: " << s.expertise << endl
		<< "Surgeon number of surgeries: " << s.number << endl;
	return os;
}
