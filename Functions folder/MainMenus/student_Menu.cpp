#include <iostream>
#include <vector>
#include <string>
using namespace std;

    void mainMenu(); //Link to the functions needed
    void studentsEdit();
    vector<string> studentDelete();
    void studentAdd();

void studentMenu(){

    system("cls"); //Clears the console using system() not recommended because of incompatibility with os other than windows
    cout << "      Student Editor \n\n";
    cout << "1.Add Student\n";
    cout << "2.Remove Student\n";
    cout << "3.Edit Student Information\n";
    cout << "4.Go back to Team Sorter\n";

    int chooserStEditor;
    cin >> chooserStEditor; // User choosing what menu he wants to go to
    while(cin.fail() || chooserStEditor < 1 || chooserStEditor > 4){ //Proofing the user doesn't choose a number not mentioned or a letter. Allows the user to re-enter
    cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
    cin.clear();
    cin.sync();
    cin >> chooserStEditor;
    }

    if(chooserStEditor == 1){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows
        studentAdd();   //Goes to the function studentAdd() where a student is created in Students.csv
    }

    if(chooserStEditor == 2){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows
        studentDelete();//Goes to the function studentDelete() where a student is deleted from Students.csv
    }

    if(chooserStEditor == 3){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows
        studentsEdit(); //Goes to the function studentEdit() where a student's information in Students.csv is edited
    }

    if(chooserStEditor == 4){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows
        mainMenu();     //Goes back to the main menu
    }

}
