#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void fileExists(string test);   //Link to a function which checks if a file is created
void studentMenu(); //Link to last menu
bool connectionsStudentExists(string studentEmail);

struct STUDENTS{    //Structure used for entering students information
    string firstName;
    string lastName;
    string eMail;
    string prefferedPos;
    char fromClass;
    string inUse;
} student;


void studentsAdd(){

    cout << "Enter First Name:"; //User entering students information
    cin >> student.firstName;
    cout << "Enter Last Name:";
    cin >> student.lastName;
    cout << "Enter Email:";
    cin >> student.eMail;
    if(connectionsStudentExists(student.eMail)==true){
        cout << "\nStudent with that email already exists\n\n";
        system("pause");
        studentMenu();
    }
    cout << "Enter Student's preferred role:";
    cin.ignore(1000, '\n');
    getline(cin,student.prefferedPos);
    transform(student.prefferedPos.begin(), student.prefferedPos.end(), student.prefferedPos.begin(), ::tolower);
    cout << "Enter Student's class(Letter):";
    cin >> student.fromClass;
    cout << "Team(No if he isn't in a team):";
    cin >> student.inUse;

    fstream file;

    fileExists("Students.csv"); //Checks if Students.csv exists otherwise it creates it

    file.open("Students.csv", ios::app); //Open Students.csv in append mode

    file << student.firstName << "," << student.lastName << "," << student.eMail << "," << student.prefferedPos << "," << student.fromClass << "," << student.inUse << endl; //Adds what the user has written about the student to Students.csv at end of the file

    file.close(); //Closes Students.csv

    cout << "\nStudent successfully added!\n\n";

    system("pause");

    studentMenu(); //Goes back to student menu
}
