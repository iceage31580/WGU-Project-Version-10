//roster.cpp
#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;

//This function initializes maxSize, and allocates memory for an
//array of student pointers.
Roster::Roster(int maxSize) : maxSize(maxSize), currentSize(0) {
    classRosterArray = new Student * [maxSize];
}

//This is a Destructor that deletes objects in classRoster array, and frees memory
Roster::~Roster() {
    for (int i = 0; i < currentSize; ++i) {
        delete classRosterArray[i];
    }
    delete[] classRosterArray;
}

//This function adds a student to the classRosterArray and creates
//an error message if there is no more space.
void Roster::add(const string& studentData) {
    istringstream ss(studentData);
    string token, studentID, firstName, lastName, email, degreeStr;
    int age, daysInCourse[3];
    Degree degree;

    getline(ss, studentID, ',');
    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, email, ',');
    ss >> age; ss.ignore();
    ss >> daysInCourse[0]; ss.ignore();
    ss >> daysInCourse[1]; ss.ignore();
    ss >> daysInCourse[2]; ss.ignore();
    getline(ss, degreeStr, ',');

    if (degreeStr == "SECURITY") degree = Degree::Security;
    else if (degreeStr == "NETWORK") degree = Degree::Network;
    else degree = Degree::Software;

    classRosterArray[currentSize++] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degree);
}


//Corrects E3b. part one, it still needs to be called in the main function
void Roster::remove(const string& studentID) {
    for (int i = 0; i < currentSize; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            for (int j = i; j < currentSize - 1; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            currentSize--;
            cout << "Removed: " << studentID << endl;
            return;
        }
    }
    cout << "Student ID " << studentID << " not found!" << endl;
}

//This function prints the array.
void Roster::printAll() const {
    for (int i = 0; i < currentSize; ++i) {
        classRosterArray[i]->print();
    }
}

//This function prints the days taken in by the array and prints the average by taking in the studentID.
void Roster::printAverageDaysInCourse(const string& studentID) const {
    for (int i = 0; i < currentSize; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();
            cout << "Average days for " << studentID << ": "
                << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
}

//This function takes in emails and prints invalid emails.
void Roster::printInvalidEmails() const {
    for (int i = 0; i < currentSize; ++i) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << "Invalid email: " << email << endl;
        }
    }
}

//This function prints the students doing a particular software program
void Roster::printByDegreeProgram(Degree degreeProgram) const {
    cout << "Printing students in the degree program: " << degreeToString(degreeProgram) << endl;
    for (int i = 0; i < currentSize; ++i) {
        if (classRosterArray[i]->getDegree() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}
