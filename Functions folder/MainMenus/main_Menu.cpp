#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

void studentMenu();
void teacherMenu();
void teamMenu();
void searchMenu();

void mainMenu(){
    cout << "     Team Sorter\n\n";
    cout << "1.Student Editor\n";
    cout << "2.Teacher Editor\n";
    cout << "3.Team Editor\n";
    cout << "4.Search\n";

    int chooser;
    cin >> chooser;
    while(cin.fail() || chooser < 1 || chooser > 4){
        cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
        cin.clear();
        cin.sync();
        cin >> chooser;
    }

    if(chooser == 1){


            FILE *file;
        if (file = fopen("Students.csv", "r")) {
            fclose(file);
        }
        else {
            ofstream file {"Students.csv"};
            file << "First Name," << "Second Name," << "Preferred position," << "Class," << "In use or not" << endl;
        }

        studentMenu();
    }

    if(chooser == 2){

            FILE *file;
        if (file = fopen("Teachers.csv", "r")) {
            fclose(file);
        }
        else {
            ofstream file {"Teachers.csv"};
            file << "First Name," << "Second Name," << "Leader of teams" << endl;
        }
        teacherMenu();

    }

    if(chooser == 3){
            FILE *file;
        if (file = fopen("Teams.csv", "r")) {
            fclose(file);
        }
        else {
            ofstream file {"Teams.csv"};
        }
        teamMenu();
    }

    if(chooser == 4){
        searchMenu();
    }




}
