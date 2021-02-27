#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void teacherMenu();

struct TEACHERS{
    string firstName;
    string lastName;
    string eMail;
    int inUse;
} teacher;

void teacherAdd(){
    cout << "Enter First Name:";
    cin >> teacher.firstName;
    cout << "Enter Last Name:";
    cin >> teacher.lastName;
    cout << "Enter Email:";
    cin >> teacher.eMail;
    cout << "In how many teams:";
    cin >> teacher.inUse;
    while(teacher.inUse<0){
        teacher.inUse=0;
    }

    fstream file;

    file.open("Teachers.csv", ios::app);

    file << teacher.firstName << "," << teacher.lastName << "," << teacher.eMail << "," << teacher.inUse << endl;

    file.close();

    teacherMenu();
}
