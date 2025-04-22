// DATE.h
#ifndef DATE_H
#define DATE_H

class Date
{
private:

    int day; 
    int month; 
    int year;

public:
    Date(int day, int month, int year);
    Date(const Date& other);
    const Date& operator=(const Date& other);
    int getYear()                const { return year; };
    int getMonth()               const { return month; };
    int getDay()                 const { return day; };
    bool setYear(const int year);
    bool setMonth(const int month);
    bool setDay(const int day);
    friend ostream& operator<<(ostream& os, const Date& d);
};

#endif // DATE_H
