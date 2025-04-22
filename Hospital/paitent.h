// PAITENT.h
#ifndef PAITENT_H
#define PAITENT_H
using namespace std;

#include "person.h"
#include "date.h"

class Paitent : public Person
{
public:
    enum eGender { Male, Female };
    static const string status[];

private:
    
    Date birthday;
    int ID;
    eGender gender;

public:
    Paitent(const Person& p,const Date& d,eGender gen,const int id);
    Paitent(const Paitent& other);
    const Paitent& operator=(const Paitent& other) = delete;
    int getID()                const { return ID; };
    const string getGender() const;
    Date getDate()             const { return birthday; };
    static void printGender();
    friend ostream& operator<<(ostream& os, const Paitent& p);

    friend class Hospital;

};

#endif // PAITENT_H
