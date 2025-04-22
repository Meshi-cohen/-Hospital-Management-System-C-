
//Omer Vetcher 316591346
//Meshi Cohen  211868302
#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "hospital.h"

void NewDepartment(Hospital& H);
void NewDoctor(Hospital& H);
void NewNurse(Hospital& H);
void NewResearcher(Hospital& H);
void NewArticle(Hospital& H);
void NewVisit(Hospital& H);
void PrintPaitentInDep(Hospital& H);
void PrintPaitentByID(Hospital& H);
void CompareAtricles(Hospital& H);
void ChangeDocToSurg(Hospital& H);
void PrintStaffByID(Hospital& H);
void PrintResearcherArticles(Hospital& H);

int main()
{
	Hospital H("Shiba", "ShibaRS");
	int choise;

	do
	{
		cout << endl << "Menu" << endl
			<< "1.Add Departmnet" << endl
			<< "2.Add Doctor" << endl
			<< "3.Add Nurse" << endl
			<< "4.Add Researcher" << endl
			<< "5.Add Article to Researcher" << endl
			<< "6.Add Paitent Visit" << endl
			<< "7.Print All Medical Staff" << endl
			<< "8.Print All Paitents in Department" << endl
			<< "9.Print	All Researchers" << endl
			<< "10.Search Paitent by ID" << endl
			<< "11.Search Staff member by badgeID" << endl
			<< "12.Print Articels of researcher by badgeID" << endl
			<< "13.Compare two researchers articles (by badge ID number)" << endl
			<< "14.Change Doctor to Surgeon" << endl
			<< "15.Exit" << endl
			<< "Choose your option: ";
		cin >> choise;
		switch (choise)
		{
			case 1:
			{
				NewDepartment(H);
				break;
			}
			case 2:
			{
				NewDoctor(H);
				break;
			}
			case 3:
			{
				NewNurse(H);
				break;
			}
			case 4:
			{
				NewResearcher(H);
				break;
			}
			case 5:
			{
				NewArticle(H);
				break;
			}
			case 6:
			{
				NewVisit(H);
				break;
			}
			case 7:
			{
				cout << H;
				break;
			}
			case 8:
			{
				PrintPaitentInDep(H);
				break;
			}
			case 9:
			{
				H.printResearchers();
				break;
			}
			case 10:
			{
				PrintPaitentByID(H);
				break;
			}
			case 11:
			{
				PrintStaffByID(H);
				break;
			}
			case 12:
			{
				PrintResearcherArticles(H);
				break;
			}
			case 13:
			{
				CompareAtricles(H);
				break;
			}
			case 14:
			{
				ChangeDocToSurg(H);
				break;
			}
			case 15:
			{
				break;
			}
			default:
			{
				cout << endl << "Wrong Option " << endl;
				break;
			}
		}
	} while (choise != 15);
}

void NewDepartment(Hospital& H)
{
	string name;
	//H.addDeaprtment("AKG");
	//H.addDeaprtment("MRI");
	cout << "Department name: " << endl;
	cin >> name;
	H.addDeaprtment(name);
	cout << endl;
}

void NewDoctor(Hospital& H)
{
	string name;
	string expet;
	string dep;
	int numOfSurg;
	char surg;
	/*
	Surgeon s1("dodo", "knee", 0);
	Doctor d1("koko", "sholder");
	Doctor d2("momo", "Heart");
	H += s1;
	H += d1;
	H += d2;
	H.addEmployeeoDepartment(s1, "MRI");
	H.addEmployeeoDepartment(d1, "MRI");
	H.addEmployeeoDepartment(d2, "AKG");
	*/
	cout << "Doctor name: " << endl;
	cin >> name;
	cout << "Doctor expertise: " << endl;
	cin >> expet;
	cout << "Surgeon? (y/n): " <<endl;
	cin >> surg;
	if(surg == 'y')
	{
	cout << "How many Medical surgeris: " <<endl;
	cin >> numOfSurg;
	Surgeon s(name, expet ,numOfSurg);
	cout << "Surgeon department: " << endl;
	cin >> dep;
	H += s;
	H.addEmployeeoDepartment(s,dep);
	}
	else
	{
	cout << "Doctor department: " << endl;
	cin >> dep;
	Doctor d(name, expet);
	H += d;
	H.addEmployeeoDepartment(d,dep);
	}
}

void NewNurse(Hospital& H)
{
	string name;
	string dep;
	int exp;
	/*
	Nurse n1("kiki", 5);
	Nurse n2("zipi", 2);
	Nurse n3("niri", 4);
	H += n1;
	H += n2;
	H += n3;
	H.addEmployeeoDepartment(n1, "AKG");
	H.addEmployeeoDepartment(n2, "AKG");
	H.addEmployeeoDepartment(n3, "MRI");
	*/
	cout << "Nurse name: " << endl;
	cin >> name;
	cout << "Nurse experience (in years): " << endl;
	cin >> exp;
	cout << "Nurse department: " << endl;
	cin >> dep;
	Nurse n(name , exp);
	H += n;
	H.addEmployeeoDepartment(n, dep);
}

void NewResearcher(Hospital& H)
{
	string name;
	string expet;
	string dep;
	string purpose;
	int id, day, month, year, id2, choise;
	int exp, gender;
	char doctor;
	/*
	Researcher r1("jojo");
	Researcher r2("kolo");
	DoctorResearcher dR("lolo", "Back");
	H.addResearcher(r1);
	H.addResearcher(r2);
	H.addResearcher(dR);
	H.addEmployeeoDepartment(dR, "MRI");
	*/
	cout << "Researcher name: " << endl;
	cin >> name;
	cout << "Doctor? (y/n): " <<endl;
	cin >> doctor;
	if(doctor == 'y')
	{
		cout << "Doctor expertise " <<endl;
		cin >> expet;
		cout << "Doctor department: " <<endl;
		cin >> dep;
		DoctorResearcher dR(name, expet);
		H.addResearcher(dR);
		H.addEmployeeoDepartment(dR,dep);
	}
	else
	{
		Researcher r(name);
		H.addResearcher(r);
	}
}

void NewArticle(Hospital& H)
{
	string name;
	string magz;
	int id, day, month, year;
	//H.addArticleToResearcher(Article(Date(1, 2, 2024), "aaa", "ynet"), 7);
	cout << "Researcher badgeID: " << endl;
	cin >> id;
	cout << "Date of published (Day): " << endl;
	cin >> day;
	cout << "Date of published (Month): " << endl;
	cin >> month;
	cout << "Date of published (Year): " << endl;
	cin >> year;
	cout << "Article Name: " << endl;
	cin >> name;
	cout << "Magazine Name: " << endl;
	cin >> magz;
	H.addArticleToResearcher(Article(Date(day, month, year), name, magz), id);
}

void NewVisit(Hospital& H)
{
	string name;
	string dep;
	string purpose;
	int id, day, month, year, gender;
	int id2;
	char visit;
	//H.addPaitent(Paitent(Person("gili"), Date(4, 3, 1998), (Paitent::eGender)(1), 123456));
	//H.addVisit((Visit(Date(4, 1, 2025), "fastHeartBeat")), 123456, 2, "AKG");
	cout << "What is the ID of the Paitent? ";
	cin >> id;
	cout << "Does the Paitent already visit in the Hospital? (y/n): ";
	cin >> visit;
	if (visit == 'n')
	{
		cout << "what is the Paitent name? ";
		cin >> name;
		cout << "Date of birth (Day): " << endl;
		cin >> day;
		cout << "Date of birth (Month): " << endl;
		cin >> month;
		cout << "Date of birth (Year): " << endl;
		cin >> year;
		Paitent::printGender();
		cin >> gender;
		H.addPaitent(Paitent(Person(name), Date(day, month, year), (Paitent::eGender)(gender - 1), id));
	}
	cout << "Who is the main staff member in charge? (badge ID): ";
	cin >> id2;
	cout << "What is the purpose of the visit? ";
	cin >> purpose;
	cout << "Date of arrival (Day): " << endl;
	cin >> day;
	cout << "Date of arrival (Month): " << endl;
	cin >> month;
	cout << "Date of arrival (Year): " << endl;
	cin >> year;
	cout << "Which Department is he here for: ";
	cin >> dep;
	H.addVisit((Visit(Date(day, month, year), purpose)), id, id2, dep);

}

void PrintPaitentInDep(Hospital& H)
{
	string dep;
	//H.printPaitentInDepartment("AKG");
	cout << "Which department's paitents do you want to see ?" << endl;
	H.printDepartment();
	cin >> dep;
	H.printPaitentInDepartment(dep);
}

void PrintPaitentByID(Hospital& H)
{
	int id;
	//H.printPaitentByID(123456);
	cout << "what is the paitent ID you want to search: ";
	cin >> id;
	H.printPaitentByID(id);
}

void CompareAtricles(Hospital& H)
{
	int id,id2;
	/*
	if (H.ResearcherN1HasMoreArticles(7, 8))
		cout << "The researcher with id 7 has more articles compare to id 8" << endl;
	else
		cout << "The researcher with id 7 has less or equal articles compare to id 8" << endl;
	*/
	cout << "The researcher you want to preform the check on (Enter badge ID): " << endl;
	cin >> id;
	cout << "The researcher you want to compare to (Enter badge ID): " << endl;
	cin >> id2;
	if (H.ResearcherN1HasMoreArticles(id, id2))
		cout << "The researcher with id " << id << "has more articles compare to id " << id2 << endl;
	else
		cout << "The researcher with id " << id << "has less or equal articles compare to id " << id2 << endl;
	
}

void ChangeDocToSurg(Hospital& H)
{
	int id, numofSurge;
	//H.changeDoctorToSurgeon(2, 4);
	cout << "Doctor badgeID: " << endl;
	cin >> id;
	cout << "Doctor number of surgeries: " << endl;
	cin >> numofSurge;
	H.changeDoctorToSurgeon(id, numofSurge);
}

void PrintStaffByID(Hospital& H)
{
	int id;
	//H.printStaffbyID(2);
	cout << "what is the paitent ID you want to search: ";
	cin >> id;
	H.printStaffbyID(id);
}

void PrintResearcherArticles(Hospital& H)
{
	int id;
	H.printArticlesbyID(7);
	cout << "what is the Researcher badge ID you want to search: ";
	cin >> id;
	H.printArticlesbyID(id);
}