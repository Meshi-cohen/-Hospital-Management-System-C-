#pragma warning (disable: 4996)
#pragma warning (disable: 6386)
#pragma warning (disable: 6385)
#include <iostream>
using namespace std;
#include "researcher.h"

Researcher::Researcher(const Researcher& other): Employee(other)
{
	ArticlesOfResearcher = other.ArticlesOfResearcher; 
}

Researcher::Researcher(const string& name):Employee(name) { }

bool Researcher::ArticleExist(const string& name) const
{
	vector<Article>::const_iterator itr = ArticlesOfResearcher.begin();
	vector<Article>::const_iterator itrEnd = ArticlesOfResearcher.end();
	for (; itr != itrEnd; ++itr)
	{
		if (name == itr->name)
			return true;
	}
	return false;
}

bool Researcher::addArticle(const Article& a)
{
	if (ArticleExist(a.getName()))
		return false;

	ArticlesOfResearcher.push_back(a);
	return true;
}

void Researcher::printResearcherArticles() const
{
	vector<Article>::const_iterator itr = ArticlesOfResearcher.begin();
	vector<Article>::const_iterator itrEnd = ArticlesOfResearcher.end();
	for (; itr != itrEnd; ++itr)
		cout << *itr;
}

bool Researcher::operator > (const Researcher& other) const
{
	if (ArticlesOfResearcher.size() > other.getNumberOfArticles())
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Researcher& r)
{
	os << "Researcher name: " << r.name << endl
		<< "Researcher badgeID: " << r.badgeID << endl;
	return os;
}
