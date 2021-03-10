#include <iostream>
#include <string>
using namespace std;

void editFirstName(string emailToBeEdited,string fileToEdit,string tempFileName, string editNameTo);
void editSecondName(string emailToBeEdited, string fileToEdit, string tempFileName, string editNameTo);
void editEmail(string emailToBeEdited, string fileToEdit, string tempFileName, string editTo);
void editPreferredPos(string emailToBeEdited, string newPosition);
void editClass(string emailToBeEdited, char newClass);
void studentMenu();

void studentsEditMenu(string studentToBeEdited){

    cout << "\nWhat do you want to edit?\n\n";
    cout << "1.First name\n";
    cout << "2.Last name\n";
    cout << "3.Email\n";
    cout << "4.Preferred position\n";
    cout << "5.Class\n";
    cout << "6.Team\n";
    cout << "7.Back to Student menu\n";

    int chooserStEdit;

    cin >> chooserStEdit; //User's choice on what menu he wants to go to

    while(cin.fail() || chooserStEdit < 1 || chooserStEdit > 7){ //If user fails to enter a number mentioned in the menu or enters something not accepted by int type. Allows user to re-enter.
        cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-7" << endl;
        cin.clear();
        cin.sync();
        cin >> chooserStEdit;
    }

    if(chooserStEdit==1){
        system("cls");
        cout << "Change first name to: ";
        string changeFirstName;
        cin >> changeFirstName;
        editFirstName(studentToBeEdited,"Students.csv","StudentsTemp.csv",changeFirstName);
        studentMenu();
    }

    if(chooserStEdit==2){
        system("cls");
        cout << "Change last name to: ";
        string changeSecondName;
        cin >> changeSecondName;
        editSecondName(studentToBeEdited, "Students.csv", "StudentsTemp.csv", changeSecondName);
        studentMenu();
    }

    if(chooserStEdit==3){
        system("cls");
        cout << "Change email to: ";
        string changeEmail;
        cin >> changeEmail;
        editEmail(studentToBeEdited, "Students.csv", "StudentsTemp.csv", changeEmail);
        studentMenu();
    }

    if(chooserStEdit==4){
        system("cls");
        cout << "Change preferred postion to: ";
        string changePrefferedPos;
        cin >> changePrefferedPos;
        editPreferredPos(studentToBeEdited, changePrefferedPos);
        studentMenu();
    };
    if(chooserStEdit==5){
        system("cls");
        cout << "Change class to: ";
        char changeClass;
        cin >> changeClass;
        editClass(studentToBeEdited, changeClass);
        studentMenu();
    };
    if(chooserStEdit==6){
        system("cls");
        cout << "Can't change student's team from here!\nTo change his team either edit,delete or add a team.\n";
        system("pause");
        studentMenu();
    };
    if(chooserStEdit==7){
        studentMenu();
    }

}
