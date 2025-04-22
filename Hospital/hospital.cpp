#pragma warning (disable: 4996)
#pragma warning (disable: 6385)
#pragma warning (disable: 6386)
#include <iostream>
using namespace std;

#include "hospital.h"

Hospital::Hospital(const string& n1, const string& n2): RS(n2)
{
	this->name = n1;
}

bool Hospital::EmployeeExist(const int id) const
{
	vector<Employee*>::const_iterator itr = EmployeesInHospital.begin();
	vector<Employee*>::const_iterator itrEnd = EmployeesInHospital.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getID() == id)
			return true;
	}
	return false;
}

bool Hospital::PatientExsit(const int id) const
{
	vector<Paitent>::const_iterator itr = PaitentsInHospital.begin();
	vector<Paitent>::const_iterator itrEnd = PaitentsInHospital.end();
	for (; itr != itrEnd; ++itr)
	{
		if (itr->ID == id)
			return true;
	}
	return false;
}

bool Hospital::setName(const string& name)
{
	this->name= name;
	return true;
}

bool Hospital::departmentExsist(const string& dep) const
{
	vector<Department>::const_iterator itr = DepartmentsInHospital.begin();
	vector<Department>::const_iterator itrEnd = DepartmentsInHospital.end();
	for (; itr != itrEnd; ++itr)
	{
		if (dep == itr->name)
			return true;
	}
	return false;
}

bool Hospital::addDeaprtment(const string& dep)
{
	if(departmentExsist(name))
		return false;

	DepartmentsInHospital.push_back(Department(dep));
	return true;
}
bool Hospital::addEmployeeoDepartment(const Employee& e, const string& dep)
{
	vector<Employee*>::iterator itr = EmployeesInHospital.begin();
	vector<Employee*>::iterator itrEnd = EmployeesInHospital.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->badgeID == e.badgeID)
		{
			vector<Department>::iterator itrDep = DepartmentsInHospital.begin();
			vector<Department>::iterator itrEndDep = DepartmentsInHospital.end();
			for (; itrDep != itrEndDep; ++itrDep)
					if (dep == itrDep->name)
					{
						Doctor* temp = dynamic_cast<Doctor*>(*itr);
						if (temp)
							(*itrDep).addDoctor(*temp);
						else if (typeid(e) == typeid(Nurse))
							(*itrDep).addNurse(*dynamic_cast<Nurse*>(*itr));
						return true;
					}
		 }
	}	
	return true;
}
bool Hospital::addResearcher(Researcher& r)
{
	
	if (typeid(r) == typeid(DoctorResearcher))
	{
		if (!EmployeeExist(r.getID()))
		{
			*this += r;
			DoctorResearcher* dr = dynamic_cast<DoctorResearcher*>(*--EmployeesInHospital.end());
			RS.addResearcher(*dr);
		}
	}
	else
		RS.addResearcher(r);
	return true;
}
bool Hospital::addArticleToResearcher(const Article& art, const int ResearcherID)
{
	RS.addArticle(art, ResearcherID);
	return true;
}
bool Hospital::addPaitent(const Paitent& p)
{
	if (PatientExsit(p.getID()))
		return false;
	PaitentsInHospital.push_back(p);
	return true;
}
bool Hospital::addVisit(const Visit& v, int PaitentID, int staffID, const string& dep)
{
	VisitsInHospital.push_back(v);
	vector <Visit>::iterator itrV = --VisitsInHospital.end();

	vector<Employee*>::iterator itrEm = EmployeesInHospital.begin();
	vector<Employee*>::iterator itrEmEnd = EmployeesInHospital.end();
	for (; itrEm != itrEmEnd; ++itrEm)
		if ((*itrEm)->badgeID == staffID)
			itrV->setStaff(*itrEm);

	vector<Paitent>::iterator itrPa = PaitentsInHospital.begin();
	vector<Paitent>::iterator itrPaEnd = PaitentsInHospital.end();
	for (; itrPa != itrPaEnd; ++itrPa)
		if (itrPa->ID == PaitentID)
			itrV->setPaitent(&*itrPa);

	vector<Department>::iterator itrDe = DepartmentsInHospital.begin();
	vector<Department>::iterator itrDeEnd = DepartmentsInHospital.end();
	for (; itrDe != itrDeEnd; ++itrDe)
		if (dep == itrDe->name)
		{
			itrV->setDepartment(&*itrDe);
			itrDe->addVisittoDepartment(*itrV);
		}
	return true;
}

bool Hospital::changeDoctorToSurgeon(int id, int numOfSurg)
{
	vector<Employee*>::iterator itr = EmployeesInHospital.begin();
	vector<Employee*>::iterator itrEnd = EmployeesInHospital.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->badgeID == id)
			if(typeid(*(*itr))==typeid(Doctor))
			{ 
				Doctor* doc = dynamic_cast<Doctor*>((*itr));
				Surgeon* S = new Surgeon(*doc, numOfSurg);
				(*itr) = S;
				return true;
		}
	}
	return true;
}
void Hospital::printDepartment() const
{
	int i = 1;
	vector<Department>::const_iterator itr = DepartmentsInHospital.begin();
	vector<Department>::const_iterator itrEnd = DepartmentsInHospital.end();
	for (; itr != itrEnd; ++itr)
		cout << (i++) + 1 << ":" << itr->name << endl;
}
void Hospital::printResearchers() const
{
	cout << RS;
}
void Hospital::printPaitentByID(const int id) const
{
	vector<Paitent>::const_iterator itr = PaitentsInHospital.begin();
	vector<Paitent>::const_iterator itrEnd = PaitentsInHospital.end();
	for (; itr != itrEnd; ++itr)
		if (id == itr->ID)
		{
			cout << *itr;
			cout << "Paitent visits are:" << endl;
			vector<Visit>::const_iterator itrV = VisitsInHospital.begin();
			vector<Visit>::const_iterator itrVEnd = VisitsInHospital.end();
			for (; itrV != itrVEnd; ++itrV)
			{
				if (itrV->getPatient()->ID == id)
				{
					cout << "In " << (itrV->arrival);
					cout << "At Department: " << itrV->getDepartment()->name << endl;
				}
			}
			break;
		}
}
void Hospital::printStaffbyID(const int id) const
{
	vector<Employee*>::const_iterator itr = EmployeesInHospital.begin();
	vector<Employee*>::const_iterator itrEnd = EmployeesInHospital.end();
	for (; itr != itrEnd; ++itr)
		if (id == (*itr)->badgeID)
		{
			if (typeid(**itr) == typeid(Doctor) || typeid(**itr) == typeid(DoctorResearcher))
				cout <<"This badge ID belong to a Doctor:" << endl << (*dynamic_cast<Doctor*>(*itr)) << endl;
			else if (typeid(**itr) == typeid(Nurse))
				cout << "This badge ID belong to a Nurse:" << endl << (*dynamic_cast<Nurse*>(*itr)) << endl;
			else if (typeid(**itr) == typeid(Surgeon))
				cout << "This badge ID belong to a Surgeon:" << endl << (*dynamic_cast<Surgeon*>((*itr))) << endl;
		}
}
void Hospital::printArticlesbyID(const int id) const
{
	RS.printArticlesOfResearcher(id);
}
void Hospital::operator+=(const Employee& e)
{
	if (!EmployeeExist(e.getID()));
		EmployeesInHospital.push_back(e.clone());
}

void Hospital::printPaitentInDepartment(const string& dep) const
{
	vector<Department>::const_iterator itr = DepartmentsInHospital.begin();
	vector<Department>::const_iterator itrEnd = DepartmentsInHospital.end();
	for (; itr != itrEnd; ++itr)
		if (dep == itr->name)
			cout << *itr;
}
bool Hospital::ResearcherN1HasMoreArticles(int Researcher1ID, int Researcher2ID) const
{
	for (int i = 0; i < RS.getNumberOfResearchers(); i++)
		if (RS.ResearchersInCenter[i]->getID() == Researcher1ID)
			for (int j = 0; j < RS.getNumberOfResearchers(); j++)
				if (RS.ResearchersInCenter[j]->getID() == Researcher2ID)
					return (RS.ResearchersInCenter[i] > RS.ResearchersInCenter[j]);
}

Hospital::~Hospital()
{
	vector<Employee*>::iterator itr = EmployeesInHospital.begin();
	vector<Employee*>::iterator itrEnd = EmployeesInHospital.end();
	for (; itr != itrEnd; ++itr)
		delete* itr;

	EmployeesInHospital.clear();
	DepartmentsInHospital.clear();
	PaitentsInHospital.clear();
	VisitsInHospital.clear();
}

ostream& operator<<(ostream& os, const Hospital& h)
{
	vector<Department>::const_iterator itrDe = h.DepartmentsInHospital.begin();
	vector<Department>::const_iterator itrDeEnd = h.DepartmentsInHospital.end();
	os << endl << "Hospital name: " << h.name << endl
	<< endl << "Departments: " <<endl;
	for (; itrDe!=itrDeEnd;++itrDe)
	{
		os << itrDe->getName() << endl;
	}
	vector<Employee*>::const_iterator itrEm = h.EmployeesInHospital.begin();
	vector<Employee*>::const_iterator itrEmEnd = h.EmployeesInHospital.end();
	os << endl << "Doctors: " << endl;
	for (; itrEm != itrEmEnd; ++itrEm)
	{
		if (typeid(**itrEm) == typeid(Doctor) || typeid(**itrEm) == typeid(DoctorResearcher))
			os << (*dynamic_cast<Doctor*>(*itrEm)) << endl;
	}
	itrEm = h.EmployeesInHospital.begin();
	os << "Nurses: " << endl;
	for (; itrEm != itrEmEnd; ++itrEm)
	{
		if (typeid(**itrEm) == typeid(Nurse))
			os << (*dynamic_cast<Nurse*>(*itrEm)) << endl;
	}
	itrEm = h.EmployeesInHospital.begin();
	os << "Surgeons: " << endl;
	for (; itrEm != itrEmEnd; ++itrEm)
	{
		if (typeid(**itrEm) == typeid(Surgeon))
			os << (*dynamic_cast<Surgeon*>((*itrEm))) << endl;
	}
	return os;
}
