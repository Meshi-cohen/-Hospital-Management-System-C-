// HOSPITAL.h
#ifndef HOSPITAL_H
#define HOSPITAL_H
using namespace std;

#include <vector>
#include "department.h"
#include "researchCenter.h"
#include "visit.h"
#include "paitent.h"

class Hospital
{
private:

    string name;
    ResearchCenter RS;
    vector <Employee*> EmployeesInHospital;
    vector <Department> DepartmentsInHospital;
    vector <Paitent> PaitentsInHospital;
    vector <Visit> VisitsInHospital;

public:
    Hospital(const string& n1 , const string& n2);
    Hospital(const Hospital& h) = delete;
    Hospital operator=(const Hospital& h) const = delete;
    int getNumberofPaitents()               const { return PaitentsInHospital.size(); };
    int getNumberofEmployees()              const { return EmployeesInHospital.size(); }
    int getNumberofDepartments()            const { return DepartmentsInHospital.size(); };
    int getNumberOfVisits()                 const { return VisitsInHospital.size(); };
    bool departmentExsist(const string& name) const;
    bool EmployeeExist(int id)        const;
    bool PatientExsit(int id)         const;
    bool setName(const string& name);
    bool addDeaprtment(const std::string& dep);
    bool addEmployeeoDepartment(const Employee& e, const string& dep);
    bool addResearcher(Researcher& r);
    bool addArticleToResearcher(const Article& art, const int ResearcherID);
    bool addPaitent(const Paitent& p);
    bool addVisit(const Visit& v, int PaitentID, int staffID, const string& dep);
    bool changeDoctorToSurgeon(int id, int numOfSurg);
    void printDepartment()                  const;
    void printResearchers()                 const;
    void printPaitentByID(const int id)     const;
    void printStaffbyID(const int id)       const;
    void printArticlesbyID(const int id)    const;
    void operator+=(const Employee& e);
    void printPaitentInDepartment(const string& dep)      const;
    bool ResearcherN1HasMoreArticles(int Researcher1ID, int Researcher2ID) const;
    friend ostream& operator<<(ostream& os, const Hospital& h);
    ~Hospital();
};

#endif // HOSPITAL_H