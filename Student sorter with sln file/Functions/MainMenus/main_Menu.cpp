#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

void fileExists(string test);   //Link to a function which checks if a file is created
void studentMenu(); //Link to student menu
void teacherMenu(); //Link to teacher menu
void teamMenu();    //Link to team menu
void searchMenu();  //Link to search menu

void mainMenu(){

    cout << "     Team Sorter\n\n";
    cout << "1.Student Editor\n";
    cout << "2.Teacher Editor\n";
    cout << "3.Team Editor\n";
    cout << "4.Search\n";

    string checkIfExists; //String used to check if a file exists

    int chooser;
    cin >> chooser; //User's choice on what menu he wants to go to
    while(cin.fail() || chooser < 1 || chooser > 4){ //If user fails to enter a number mentioned in the menu or enters something not accepted by int type. Allows user to re-enter.
        cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
        cin.clear();
        cin.sync();
        cin >> chooser;
    }

    if(chooser == 1){

        checkIfExists="Students.csv";
        fileExists(checkIfExists);    //Checks if Students.csv exists otherwise it creates it

        studentMenu(); // Goes to the student menu
    }

    if(chooser == 2){

        checkIfExists="Teachers.csv";
        fileExists(checkIfExists);    //Checks if Teachers.csv exists otherwise it creates it

        teacherMenu(); // Goes to teachers menu

    }

    if(chooser == 3){

        checkIfExists="Teams.csv";
        fileExists(checkIfExists);    //Checks if Teams.csv exists otherwise it creates it

        teamMenu(); // Goes to teachers menu
    }

    if(chooser == 4){
        searchMenu(); // Goes to search menu;
    }

}
