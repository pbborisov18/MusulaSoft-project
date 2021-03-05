#include <iostream>
using namespace std;

    void mainMenu();    //Link to the main menu
    void teachersAdd();  //Link to the teacher add function
    void teachersDelete();  // Link to the teacher delete function
    void teachersEdit();    //Link to the teacher edit function
    void fileExists(string nameOfFile); //Link to the file exists function

void teacherMenu(){

    system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows
    cout << "      Teacher Editor \n\n";
    cout << "1.Add Teacher \n";
    cout << "2.Remove Teacher \n";
    cout << "3.Edit Teacher Information\n";
    cout << "4.Go back to Team Sorter\n";

    int chooserTeEditor;
    cin >> chooserTeEditor; // User choosing what he wants to do

    while(cin.fail() || chooserTeEditor < 1 || chooserTeEditor > 4){    //Proofing the user doesn't choose a number not mentioned or a letter. Allows the user to re-enter
    cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
    cin.clear();
    cin.sync();
    cin >> chooserTeEditor;
    }

    if(chooserTeEditor == 1){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Teachers.csv"); //Checks if the file Teachers.csv exists if not creates it

        teachersAdd();   //Goes to the function teacherAdd() where a teacher is created in Teachers.csv
    }

    if(chooserTeEditor == 2){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Teachers.csv"); //Checks if the file Teachers.csv exists if not creates it

        teachersDelete();   //Goes to the function teacher Delete() where a teacher is deleted from Teachers.csv

        cout << "Teacher successfully deleted";
        system("pause");

    }

    if(chooserTeEditor == 3){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Teachers.csv"); //Checks if the file Teachers.csv exists if not creates it

        teachersEdit(); //Goes to the function teacherEdit() where a teacher's information in Teachers.csv is edited
    }

    if(chooserTeEditor == 4){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Teachers.csv"); //Checks if the file Teachers.csv exists if not creates it

        mainMenu(); //Goes back to the main menu
    }

}
