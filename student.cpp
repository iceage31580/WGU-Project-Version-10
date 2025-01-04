#include <iostream>
#include "student.h"

using namespace std;

Student::Student(const string& studentID, const string& firstName,
                 const string& lastName, const string& emailAddress,
                 int age, const int daysInCourse[], Degree degree)
    : studentID(studentID), firstName(firstName), lastName(lastName),
      emailAddress(emailAddress), age(age), degree(degree) {
    for (int i = 0; i < 3; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}

// Accessors
string Student::getStudentID() const { return studentID; }
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
int* Student::getDaysInCourse() { return daysInCourse; }
Degree Student::getDegree() const { return degree; }

// Mutators
void Student::setStudentID(const string& studentID) { this->studentID = studentID; }
void Student::setFirstName(const string& firstName) { this->firstName = firstName; }
void Student::setLastName(const string& lastName) { this->lastName = lastName; }
void Student::setEmailAddress(const string& emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(const int daysInCourse[]) {
    for (int i = 0; i < 3; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}
void Student::setDegree(Degree degree) { this->degree = degree; }

// Print
void Student::print() const {
    cout << "Student ID: " << studentID << "\t"
         << "First Name: " << firstName << "\t"
         << "Last Name: " << lastName << "\t"
         << "Email: " << emailAddress << "\t"
         << "Age: " << age << "\t"
         << "Days in Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t"
         << "Degree Program: " << degreeToString(degree) << endl;
}

