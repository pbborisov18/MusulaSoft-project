#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fileExists(string test);   //Link to a function which checks if a file is created
void teacherMenu(); //Link to last menu

struct TEACHERS{    //Structure used for entering teachers information
    string firstName;
    string lastName;
    string eMail;
    int inUse;
} teacher;

void teachersAdd(){
    cout << "Enter First Name:";    //User entering teachers information
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

    fileExists("Teachers.csv"); //Checks if Teachers.csv exists otherwise it creates it

    file.open("Teachers.csv", ios::app); //Open Teachers.csv in append mode

    file << teacher.firstName << "," << teacher.lastName << "," << teacher.eMail << "," << teacher.inUse << endl;

    file.close();   //Closes Teachers.csv

    teacherMenu();  //Goes back to teacher menu
}
