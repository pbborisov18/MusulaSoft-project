#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fileExists(string test);   //Link to a function which checks if a file is created
void teacherMenu(); //Link to last menu
bool connectionsTeachersEmailAlreadyExists(string searchTerm);

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
    if(connectionsTeachersEmailAlreadyExists(teacher.eMail)==true){
        cout << "\nTeacher with that email already exists\n\n";
        system("pause");
        teacherMenu();
    }
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
