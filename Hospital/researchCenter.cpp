#pragma warning (disable: 4996)
#pragma warning (disable: 6386)
#include <iostream>
using namespace std;

#include "researchCenter.h"

ResearchCenter::ResearchCenter(const string& name)
{
	this->name = name;
}

bool ResearchCenter::setName(const string& name)
{
    this->name =name;
    return true;
}

bool ResearchCenter::ResearcherExist(int id) const
{
	vector<Researcher*>::const_iterator itr = ResearchersInCenter.begin();
	vector<Researcher*>::const_iterator itrEnd = ResearchersInCenter.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->badgeID == id)
			return true;
	}
		return false;
}
bool ResearchCenter::addResearcher(Researcher& r)
{
	if (ResearcherExist(r.getID()))
		return false;
	else
		if (typeid(r) == typeid(DoctorResearcher))
			ResearchersInCenter.push_back(&r);
		else
			ResearchersInCenter.push_back(dynamic_cast<Researcher*>(r.clone()));
	return true;
}
bool ResearchCenter::addArticle(const Article& art, int ResearcherID)
{
	vector<Researcher*>::iterator itr = ResearchersInCenter.begin();
	vector<Researcher*>::iterator itrEnd = ResearchersInCenter.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->badgeID == ResearcherID)
		{
			(*itr)->addArticle(art);
			return true;
		}
	}
	return true;
}

void ResearchCenter::printArticlesOfResearcher(const int id) const
{
	vector<Researcher*>::const_iterator itr = ResearchersInCenter.begin();
	vector<Researcher*>::const_iterator itrEnd = ResearchersInCenter.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->badgeID == id)
		{
			(*itr)->printResearcherArticles();
		}
	}
}

ostream& operator<<(ostream& os, const ResearchCenter& rs)
{

    os << endl << "Research Center name is: " << rs.name << endl;
	vector<Researcher*>::const_iterator itr = rs.ResearchersInCenter.begin();
	vector<Researcher*>::const_iterator itrEnd = rs.ResearchersInCenter.end();
	for (; itr != itrEnd; ++itr)
	{
        os << (**itr) << endl;
    }
    return os;
}