// ARTICLE.h
#ifndef ARTICLE_H
#define ARTICLE_H
using namespace std;

#include "date.h"

class Article
{
private:

    string name;
    string magazine;
    Date date;


public:
    Article(const Date& d, const string& name, const string& magazine);
    Article(const Article& other);
    const Article& operator=(const Article& other);
    const string getName()      const { return name; };
    const string getMagazine() const { return magazine; };
    Date getDate()             const { return date; };
    bool setDate(Date date);
    bool setName(const string& name);
    bool setMagazine(const string& magazine);
    friend ostream& operator<<(ostream& os, const Article& a);

    friend class Researcher;
};

#endif // ARTICLE_H
