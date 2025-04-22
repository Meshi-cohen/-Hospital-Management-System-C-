// RESEARCHER_H
#ifndef RESEARCHER_H
#define RESEARCHER_H
#include <vector>
#include "article.h"
#include "employee.h"

class Researcher : virtual public Employee
{
protected:

    vector <Article> ArticlesOfResearcher;
    Researcher(const Researcher& other);

public:

    Researcher(const string& name);
    const Researcher& operator=(const Researcher& other) = delete;
    bool ArticleExist(const string& name) const;
    bool addArticle(const Article& a);
    int getNumberOfArticles()  const { return ArticlesOfResearcher.size(); }
    void printResearcherArticles()          const;
    bool operator > (const Researcher& other) const;
    friend ostream& operator<<(ostream& os, const Researcher& r);
    virtual Employee* clone() const override { return new Researcher(*this); }

    friend class ResearchCenter;
};


#endif // RESEARCHER_H

