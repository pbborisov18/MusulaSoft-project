#include <iostream>
using namespace std;

    void mainMenu();
    void teamsAdd();
    void teamsDelete();
    void teamsEdit();

void teamMenu(){



    system("cls");
    cout << "      Team Editor \n\n";
    cout << "1.Add Team \n";
    cout << "2.Remove Team \n";
    cout << "3.Edit Team Information\n";
    cout << "4.Go back to Team Sorter\n";

    int chooserTmEditor;
    cin >> chooserTmEditor;
    while(cin.fail() || chooserTmEditor < 1 || chooserTmEditor > 4){
    cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
    cin.clear();
    cin.sync();
    cin >> chooserTmEditor;
    }

    if(chooserTmEditor == 1){
        system("cls");
        teamsAdd();
    }

    if(chooserTmEditor == 2){
        system("cls");
        teamsDelete();
    }

    if(chooserTmEditor == 3){
        system("cls");
        teamsEdit();
    }

    if(chooserTmEditor == 4){
        system("cls");
        mainMenu();
    }

}

