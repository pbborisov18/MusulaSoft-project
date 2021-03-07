#include <iostream>
#include <string>
using namespace std;

void editFirstName(string emailToBeEdited,string fileToEdit,string tempFileName, string editNameTo);
void editSecondName(string emailToBeEdited, string fileToEdit, string tempFileName, string editNameTo);
void editEmail(string emailToEdit, string fileToEdit, string tempFileName, string editTo);
void teacherMenu();

void teachersEditMenu(string teacherToBeEdited){

    cout << "\nWhat do you want to edit?\n\n";
    cout << "1.First name\n";
    cout << "2.Last name\n";
    cout << "3.Email\n";
    cout << "4.Number of teams\n";
    cout << "5.Back to Teacher menu\n";

    int chooserTeEdit;

    cin >> chooserTeEdit; //User's choice on what menu he wants to go to

    while(cin.fail() || chooserTeEdit < 1 || chooserTeEdit > 5){ //If user fails to enter a number mentioned in the menu or enters something not accepted by int type. Allows user to re-enter.
        cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-5" << endl;
        cin.clear();
        cin.sync();
        cin >> chooserTeEdit;
    }

    if(chooserTeEdit==1){
        system("cls");
        cout << "Change first name to: ";
        string changeFirstName;
        cin >> changeFirstName;
        editFirstName(teacherToBeEdited,"Teachers.csv","TeachersTemp.csv",changeFirstName);
        teacherMenu();
    }
    if(chooserTeEdit==2){
        system("cls");
        cout << "Change last name to: ";
        string changeSecondName;
        cin >> changeSecondName;
        editSecondName(teacherToBeEdited,"Teachers.csv","TeachersTemp.csv", changeSecondName);
        teacherMenu();
    }
    if(chooserTeEdit==3){
        system("cls");
        cout << "Change email to: ";
        string changeEmail;
        cin >> changeEmail;
        editEmail(teacherToBeEdited, "Teachers.csv", "TeachersTemp.csv", changeEmail);
        teacherMenu();
    }
    if(chooserTeEdit==4){
        system("cls");
        cout  << "You can't change the number of teams of the teacher!\nTo change it delete, add or edit a team with the teacher as a leader\n\n";
        system("pause");
        teacherMenu();
    }
    if(chooserTeEdit==5){
        teacherMenu();
    }

}
