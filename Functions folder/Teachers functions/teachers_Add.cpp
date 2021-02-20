#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void teacherMenu();

struct TEACHERS{
    string firstName;
    string lastName;
    int inUse;
} teacher;

void teacherAdd(){
    cout << "Enter First Name:";
    cin >> teacher.firstName;
    cout << "Enter Last Name:";
    cin >> teacher.lastName;
    cout << "In how many teams:";
    cin >> teacher.inUse;
    while(teacher.inUse<0){
        teacher.inUse=0;
    }

    fstream file;

    file.open("Teachers.csv", ios::app);

    file << teacher.firstName << "," << teacher.lastName << "," << teacher.inUse << endl;

    file.close();

    teacherMenu();
}
