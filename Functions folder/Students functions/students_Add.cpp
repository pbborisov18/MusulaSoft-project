#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void studentMenu(); //Link to last menu

struct STUDENTS{    //Structure used for entering students information
    string firstName;
    string lastName;
    string eMail;
    string prefferedPos;
    char fromClass;
    string inUse;
} student;


void studentAdd(){

    cout << "Enter First Name:"; //User entering students information
    cin >> student.firstName;
    cout << "Enter Last Name:";
    cin >> student.lastName;
    cout << "Enter Email:";
    cin >> student.eMail;
    cout << "Enter Student's preferred role:";
    cin >> student.prefferedPos;
    cout << "Enter Student's class(Letter):";
    cin >> student.fromClass;
    cout << "Team(No if he isn't in a team):";
    cin >> student.inUse;

    fstream file;

    file.open("Students.csv", ios::app); //Open Students.csv in append mode

    file << student.firstName << "," << student.lastName << "," << student.eMail << "," << student.prefferedPos << "," << student.fromClass << "," << student.inUse << endl; //Adds what the user has written about the student to Students.csv at end of the file

    file.close(); //Closes Students.csv

    studentMenu(); //Goes back to student menu
}
