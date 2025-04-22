#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "employee.h"

int Employee::IDcounter = 0;

Employee::Employee(const string& name) :Person(name), badgeID(++IDcounter)
{
}

Employee::Employee(const Employee& other):Person(other)
{
	this->badgeID = other.badgeID;
}

ostream& operator<<(ostream& os, const Employee& e)
{
	e.toOs(os);
	return os;
}
