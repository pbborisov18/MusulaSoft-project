#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void studentMenu();

struct STUDENTS{
    string firstName;
    string lastName;
    string prefferedPos;
    char fromClass;
    bool inUse;
} student;

void studentAdd(){

    cout << "Enter First Name:";
    cin >> student.firstName;
    cout << "Enter Last Name:";
    cin >> student.lastName;
    cout << "Enter Student's preferred role:";
    cin >> student.prefferedPos;
    cout << "Enter Student's class(Letter):";
    cin >> student.fromClass;
    cout << "In team Or not(1 or 0):";
    cin >> student.inUse;

    fstream file;

    file.open("Students.csv", ios::app);

    file << student.firstName << "," << student.lastName << "," << student.prefferedPos << "," << student.fromClass << "," << student.inUse << endl;

    file.close();

    studentMenu();
}
