#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <string>

class Roster {
public:
    Roster(int maxSize);
    ~Roster();

    void addStudent(Student* student);
    void add(const std::string& studentData);
    void remove(const std::string& studentID);
    void printAll() const;
    void printAverageDaysInCourse(const std::string& studentID) const;
    void printInvalidEmails() const;

private:
    Student** classRosterArray;
    int maxSize;
    int currentSize;
};

#endif // ROSTER_H
