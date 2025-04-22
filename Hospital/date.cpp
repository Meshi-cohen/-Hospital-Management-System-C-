#pragma warning (disable: 4996)
#pragma warning (disable: 6386)
#pragma warning (disable: 6385)
#include <iostream>
using namespace std;

#include "date.h"

Date::Date(int day, int month, int year):day(day),month(month),year(year) 
{
}

Date::Date(const Date& other)
{
	*this = other;
}

const Date& Date::operator=(const Date& other)
{
	year = other.year;
	month = other.month;
	day = other.day;
	return *this;
}

bool Date::setYear(const int year)
{
	this->year = year;
	return true;
}

bool Date::setMonth(const int month)
{
	this->month = month;
	return true;
}

bool Date::setDay(const int day)
{
	this->day = day;
	return true;
}

ostream& operator<<(ostream& os, const Date& d)
{
	os << "Date: " << d.day << "." << d.month << "." << d.year << endl;
	return os;
}
