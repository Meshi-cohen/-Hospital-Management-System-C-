// PERSON.h
#ifndef PERSON_H
#define PERSON_H
using namespace std;

class Person
{
protected:

    string name;

public:

    Person(const string& name);
    Person(const Person& other);
    const Person& operator=(const Person& other) = delete;
    const string getName()      const { return name; };
    bool setName(const string& name);
    virtual ~Person();

};

#endif // PERSON_H
