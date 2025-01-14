#pragma once
//roster.h
#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include <string>

class Roster {
public:
    Roster(int maxSize); //This is the constructor.
    ~Roster(); //This is the call for the constructor.

    //This is the declaration of the add student function.
    //It works by declaring all the variables that will be used
    void addStudent(Student* student);
    //This is the declaration of the add function to use be able to grab the student data.
    void add(const std::string& studentData);
    //This is the declaration to the function removes the student data using studentIDs.
    void remove(const std::string& studentID);
    //This is the declaration to the function prints the student information.
    void printAll() const;
    //This is the declaration to the function takes in the average days in course using the studentID and calculates the average.
    void printAverageDaysInCourse(const std::string& studentID) const;
    //This is the declaration to the function to print invalid emails.
    void printInvalidEmails() const;
    //pseudo code implementation
    void printByDegreeProgram(Degree degreeProgram) const;


private:
    //Pointer nightmare
    Student** classRosterArray;
    int maxSize;
    int currentSize;
};

#endif // ROSTER_H
