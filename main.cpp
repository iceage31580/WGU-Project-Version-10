#include <iostream>
#include "roster.h"

using namespace std;

const string studentData[] = {
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Isaac,Marinero,imarine@wgu.edu,29,45,90,125,SOFTWARE"
};

int main() {
    Roster classRoster(5);

    for (const auto& data : studentData) {
        classRoster.add(data);
    }

    cout << "All students:" << endl;
    classRoster.printAll();
    cout << endl;

    classRoster.printInvalidEmails();
    cout << endl;

    for (int i = 1; i <= 5; ++i) {
        classRoster.printAverageDaysInCourse("A" + to_string(i));
    }

    return 0;
}

