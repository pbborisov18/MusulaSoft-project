#include <iostream>
#include <vector>
#include <string>
using namespace std;

    void mainMenu(); //Link to the main menu
    void studentsAdd();  //Link to the student add function
    void studentsDelete(); // Link to the student delete function
    void studentsEdit(); //Link to the student edit function
    void fileExists(string nameOfFile); //Link to the file exists function

void studentMenu(){

    system("cls"); //Clears the console using system() not recommended because of incompatibility with os other than windows

    cout << "      Student Editor \n\n";
    cout << "1.Add Student\n";
    cout << "2.Remove Student\n";
    cout << "3.Edit Student Information\n";
    cout << "4.Go back to Team Sorter\n";

    int chooserStEditor;
    cin >> chooserStEditor; // User choosing what he wants to do

    while(cin.fail() || chooserStEditor < 1 || chooserStEditor > 4){ //Proofing the user doesn't choose a number not mentioned or a letter. Allows the user to re-enter
    cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
    cin.clear();
    cin.sync();
    cin >> chooserStEditor;
    }

    if(chooserStEditor == 1){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Students.csv"); //Checks if the file Students.csv exists if not creates it

        studentsAdd();   //Goes to the function studentAdd() where a student is created in Students.csv
    }

    if(chooserStEditor == 2){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Students.csv"); //Checks if the file Students.csv exists if not creates it

        studentsDelete();   //Goes to the function studentDelete() where a student is deleted from Students.csv
    }

    if(chooserStEditor == 3){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Students.csv"); //Checks if the file Students.csv exists if not creates it

        studentsEdit(); //Goes to the function studentEdit() where a student's information in Students.csv is edited
    }

    if(chooserStEditor == 4){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Students.csv"); //Checks if the file Students.csv exists if not creates it

        mainMenu();     //Goes back to the main menu
    }

}
