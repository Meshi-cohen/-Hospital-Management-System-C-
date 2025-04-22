#pragma warning (disable: 4996)
#pragma warning (disable: 6386)
#pragma warning (disable: 6385)
#include <iostream>
using namespace std;

#include "date.h"
#include "article.h"

Article::Article(const Date& d, const string& name, const string& magazine) :date(d)
{
	this->name = name;
	this->magazine = magazine;
}

Article::Article(const Article& other):date(other.date)
{
	*this = other;
}

const Article& Article::operator=(const Article& other)
{
	date = other.date;
	name = other.name;
	magazine = other.magazine;
	return *this;
}

bool Article::setDate(Date date)
{
	this->date = date;
	return true;
}

bool Article::setName(const string& name)
{
	this->name = name;
	return true;
}

bool Article::setMagazine(const string& magazine)
{
	this->magazine = magazine;
	return true;
}

ostream& operator<<(ostream& os, const Article& a)
{
	os << "Article: :" << a.name << ", Published at magazine: " << a.magazine << ", in: " << a.date;
	os << endl;
	return os;
}
