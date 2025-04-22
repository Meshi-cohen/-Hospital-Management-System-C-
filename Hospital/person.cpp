#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "person.h"

Person::Person(const string& name)
{
    this->name = name;
}

Person::Person(const Person& other)
{
    name = other.name;
}

bool Person::setName(const string& name)
{
    this->name = name;
    return true;
}

Person::~Person() { }


