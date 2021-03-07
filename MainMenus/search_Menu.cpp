#include <iostream>
#include <vector>
#include <string>
using namespace std;

void fileExists(string nameOfFile); //Link to a function which checks if a file exists
void mainMenu();    //Link to main menu function
bool searchStudent(string searchTerm);  //Link to function which searches Students.csv
bool searchTeacher(string searchTerm);  //Link to function which searches Teachers.csv
bool searchTeam(string searchTerm); //Link to function which searches Teams.csv

void searchMenu(){

    system("cls"); //Clears the console using system() not recommended because of incompatibility with os other than windows

    cout << "      Search \n\n";
    cout << "1.Search students \n";
    cout << "2.Search teachers \n";
    cout << "3.Search teams \n";
    cout << "4.Go back to Team Sorter\n";

    int chooserSearch;
    cin >> chooserSearch; // User choosing what he wants to search for

    while(cin.fail() || chooserSearch < 1 || chooserSearch > 4){ //Proofing the user doesn't choose a number not mentioned or a letter. Allows the user to re-enter
    cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
    cin.clear();
    cin.sync();
    cin >> chooserSearch;
    }

    if(chooserSearch == 1){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows
        fileExists("Students.csv"); //Checks if the file Students.csv exists if not creates it

        cout<<"Enter Student Email: ";

        string email;
        cin >> email; //User's search

        searchStudent(email); //Goes to the function

        system("pause");//Bad practise because users who use different os won't work. Pauses the program so the user can read what he searched for

        searchMenu();
    }

    if(chooserSearch == 2){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows
        fileExists("Teachers.csv"); //Checks if the file Teachers.csv exists if not creates it

        cout<<"Enter Teacher Email: ";

        string email;
        cin >> email; //User's search

        searchTeacher(email); //we call the function

        system("pause");//Bad practise because users who use different os won't work. Pauses the program so the user can read what he searched for

        searchMenu();

    }

    if(chooserSearch == 3){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows
        fileExists("Teams.csv");    //Checks if the file Teams.csv exists if not creates it

        cout<<"Enter Team Name: ";

        string email;
        cin >> email; //User's search

        searchTeam(email); //we call the function

        system("pause");//Bad practise because users who use different os won't work. Pauses the program so the user can read what he searched for

        searchMenu();

    }

    if(chooserSearch == 4){
        system("cls");  //Clears the console using system() not recommended because of incompatibility with os other than windows
        mainMenu(); //Goes back to the main menu
    }

}

