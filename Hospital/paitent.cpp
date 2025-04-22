#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "paitent.h"

const string Paitent::status[] = { "Male","Female" };

Paitent::Paitent(const Person& p,const Date& d,eGender gen,const int id):Person(p),birthday(d),ID(id)
{
	this->gender = gen;
}

Paitent::Paitent(const Paitent& other): Person(other),birthday(other.birthday)
{
	this->ID = other.ID;
	this->gender = other.gender;
}

const string Paitent::getGender() const
{
	return status[gender];
}

void Paitent::printGender()
{
	int numOfStatus = sizeof(status) / sizeof(status[0]);
	cout << "Enter the paitent gender: " << endl;
	for (int i = 0; i < numOfStatus; i++)
		cout << i + 1 << " " << status[i] << endl;
	cout << endl;
}

ostream& operator<<(ostream& os, const Paitent& p)
{
	os << "Paitent name: " << p.name << endl
		<< "Paitent ID: " << p.ID << endl
		<< "Paitent Gender: " << Paitent::status[p.gender] << endl;
	return os;
}
