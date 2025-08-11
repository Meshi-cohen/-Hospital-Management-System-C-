🏥 Hospital Management System
📌 Overview
The Hospital Management System is a C++ console-based application built in Visual Studio to simulate and manage hospital operations.
It handles departments, staff (doctors, surgeons, nurses), patients, visits, researchers, and research articles, using Object-Oriented Programming (OOP) principles.

The project supports:

Managing departments and assigning staff to them.

Handling patients and their visits.

Adding and managing researchers and articles.

Searching and printing detailed hospital data.

Changing a Doctor into a Surgeon dynamically.

🎯 Features
🏢 Department Management
Add new departments.

Assign doctors, surgeons, and nurses to specific departments.

View patients assigned to a department.

👩‍⚕️ Staff Management
Add:

Doctors (with medical expertise)

Nurses (with years of experience)

Surgeons (number of surgeries performed)

Doctor-Researchers (dual role: medical + research)

Search staff by badge ID.

Change a Doctor into a Surgeon.

🧍 Patient Management
Add new patients (name, birth date, gender, ID).

Search patients by ID.

📅 Visit Management
Schedule visits:

Link a patient to a department.

Assign a main staff member to the visit.

Record purpose and date.

View patient visit history.

🔬 Research Management
Add Researchers and Doctor-Researchers.

Assign Articles to researchers.

Print all articles of a specific researcher.

Compare two researchers by number of articles.

🛠 Technologies Used
Language: C++17

IDE: Microsoft Visual Studio 2019/2022

OOP Concepts:

Inheritance (e.g., Doctor → Surgeon)

Multiple Inheritance (DoctorResearcher inherits from both Doctor and Researcher)

Composition (Departments contain Doctors, Nurses, Visits)

Operator Overloading (<<, >)

STL: vector for dynamic storage and management

📂 Project Structure
bash
Copy code
Hospital.sln                      # Visual Studio Solution
Hospital/
 ├── main.cpp                      # Entry point & menu logic
 ├── hospital.h / hospital.cpp     # Core hospital management
 ├── department.h / department.cpp # Department logic
 ├── employee.h / employee.cpp     # Abstract employee class
 ├── doctor.h / doctor.cpp         # Doctor class
 ├── nurse.h / nurse.cpp           # Nurse class
 ├── surgeon.h / surgeon.cpp       # Surgeon class
 ├── doctorResearcher.h / doctorResearcher.cpp # Dual role
 ├── researcher.h / researcher.cpp # Researcher logic
 ├── researchCenter.h / researchCenter.cpp     # Research center
 ├── article.h / article.cpp       # Articles
 ├── date.h / date.cpp             # Date handling
 ├── person.h / person.cpp         # Base person class
 ├── paitent.h / paitent.cpp       # Patient class
 ├── visit.h / visit.cpp           # Visit management
🚀 Getting Started
1️⃣ Requirements
Microsoft Visual Studio 2019/2022

C++17 support enabled

2️⃣ Build & Run
Clone or download the repository.

Open Hospital.sln in Visual Studio.

Build (Ctrl + Shift + B).

Run (F5).

📖 Example Menu
pgsql
Copy code
Menu
1. Add Department
2. Add Doctor
3. Add Nurse
4. Add Researcher
5. Add Article to Researcher
6. Add Patient Visit
7. Print All Medical Staff
8. Print All Patients in Department
9. Print All Researchers
10. Search Patient by ID
11. Search Staff by badgeID
12. Print Articles of Researcher
13. Compare Researchers by Articles
14. Change Doctor to Surgeon
15. Exit

👩‍💻 Authors
Omer Vetcher
Meshi Cohen
