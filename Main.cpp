// ConsoleApplication - WGU Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <windows.h>
using namespace std;


//I decided to have the array as a global function.
//I would assume in a real life situation the data would not be found inside the main function.
//This is why I placed it outside.
const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "011269210,Isaac,Marinero,imarine@wgu.edu,29,45,90,125,SOFTWARE"
};

int main() {

    cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "Student Name: Isaac Marinero" << endl;
    cout << "StudentID: 011269210 " << endl;

    cout << "\n"; 
    cout << "\n";
    cout << "\n";
    cout << "\n";


    //This creates a Roster object with capacity for 5 students
    Roster classRoster(5);

    //Adds a student to the data roster
    for (const auto& data : studentData) {
        classRoster.add(data);
    }

    //Might to be re-evaluated
    cout << "All students:" << endl;
    classRoster.printAll();
    cout << endl;

    //Prints students with invalid email addresses
    classRoster.printInvalidEmails();
    cout << endl;

    //Completes E3b. This allows the removal of function to be validated
    classRoster.remove("A1");
    classRoster.remove("A2");
    classRoster.remove("A3");
    classRoster.remove("A4");
    classRoster.remove("011269210");


    //Attempting to print average days in course for IDs
    //that are no longer in the roster
    for (int i = 1; i <= 5; ++i) {
        classRoster.printAverageDaysInCourse("A" + to_string(i));
    }

    //returns zero
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
