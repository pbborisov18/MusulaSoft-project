#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

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

    int chooser;
    cin >> chooser; //User's choice on what menu he wants to go to
    while(cin.fail() || chooser < 1 || chooser > 4){ //If user fails to enter a number mentioned in the menu or enters something not accepted by int type. Allows user to re-enter.
        cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
        cin.clear();
        cin.sync();
        cin >> chooser;
    }

    if(chooser == 1){

            FILE *file;
        if (file = fopen("Students.csv", "r")) {//tries to open Students.csv If it can't open open the file it creates the file Students.csv.
            fclose(file);
        }
        else {
            ofstream file {"Students.csv"};
            file << "First Name," << "Second Name," << "Email," << "Preferred position," << "Class," << "In use or not\n"; //First row of the file is created. For comfort purposes
        }

        studentMenu(); // Goes to the student menu
    }

    if(chooser == 2){

            FILE *file;
        if (file = fopen("Teachers.csv", "r")) {//tries to open Teachers.csv If it can't open the file it creates the file Teachers.csv.
            fclose(file);
        }
        else {
            ofstream file {"Teachers.csv"};
            file << "First Name," << "Second Name," << "Email," << "Leader of teams\n"; //First row of the file is created. For comfort purposes
        }
        teacherMenu(); // Goes to teachers menu

    }

    if(chooser == 3){
            FILE *file;
        if (file = fopen("Teams.csv", "r")) {//tries to open Teams.csv If it can't open the file it creates the file Teams.csv.
            fclose(file);
        }
        else {
            ofstream file {"Teams.csv"};
            file << "Team name," << "Student1," << "Student2," << "Student3," << "Student4," << "Teacher\n"; //First row of the file is created. For comfort purposes
        }
        teamMenu(); // Goes to teachers menu
    }

    if(chooser == 4){
        searchMenu(); // Goes to search menu;
    }

}
