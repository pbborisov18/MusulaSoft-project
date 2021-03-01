#include <iostream>
using namespace std;

    void mainMenu();    //Link to the main menu
    void teamsAdd();    //Link to the team add function
    void teamsDelete(); // Link to the team delete function
    void teamsEdit();   //Link to the team edit function
    void fileExists(string nameOfFile); //Link to the file exists function

void teamMenu(){

    system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

    cout << "      Team Editor \n\n";
    cout << "1.Add Team \n";
    cout << "2.Remove Team \n";
    cout << "3.Edit Team Information\n";
    cout << "4.Go back to Team Sorter\n";

    int chooserTmEditor;
    cin >> chooserTmEditor; // User choosing what he wants to do

    while(cin.fail() || chooserTmEditor < 1 || chooserTmEditor > 4){    //Proofing the user doesn't choose a number not mentioned or a letter. Allows the user to re-enter
    cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
    cin.clear();
    cin.sync();
    cin >> chooserTmEditor;
    }

    if(chooserTmEditor == 1){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Teams.csv");    //Checks if the file Teams.csv exists if not creates it

        teamsAdd(); //Goes to the function teamsAdd() where a tean is created in Teams.csv
    }

    if(chooserTmEditor == 2){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Teams.csv");    //Checks if the file Teams.csv exists if not creates it

        teamsDelete();  //Goes to the function teamsDelete() where a team is deleted from Teams.csv
    }

    if(chooserTmEditor == 3){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Teams.csv");    //Checks if the file Teams.csv exists if not creates it

        teamsEdit();    //Goes to the function teamsEdit() where a team's information in Teams.csv is edited
    }

    if(chooserTmEditor == 4){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows

        fileExists("Teams.csv");    //Checks if the file Teams.csv exists if not creates it

        mainMenu(); //Goes back to the main menu
    }

}
