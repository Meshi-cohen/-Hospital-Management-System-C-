// RESEARCHCENTER.h
#ifndef RESEARCHCENTER_H
#define RESEARCHCENTER_H
using namespace std;
#include <vector>
#include "doctorResearcher.h"

class ResearchCenter
{
private:

    string name;
    vector <Researcher*> ResearchersInCenter;

public:

    ResearchCenter(const string& name);
    ResearchCenter(const ResearchCenter& other) = delete;
    const ResearchCenter& operator=(const ResearchCenter& other) = delete;
    const string getName()      const { return name; };
    bool setName(const string& name);
    bool ResearcherExist(int id)              const;
    bool addResearcher(Researcher& r);
    bool addArticle(const Article& art, int ResearcherID);
    void printArticlesOfResearcher(const int id) const;
    int getNumberOfResearchers() const{ return ResearchersInCenter.size(); }
    friend ostream& operator<<(ostream& os, const ResearchCenter& rs);

    friend class Hospital;
};

#endif // RESEARCHCENTER_H
