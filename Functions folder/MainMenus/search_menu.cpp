#include <iostream>
using namespace std;

    void mainMenu();
    void searchNames();
    void searchTeams();
    void searchStudents();
    void searchTeachers();

void searchMenu(){

    system("cls");
    cout << "      Search \n\n";
    cout << "1.Search students \n";
    cout << "2.Search teachers \n";
    cout << "3.Search teams \n";
    cout << "4.Go back to Team Sorter\n";

    int chooserSearch;
    cin >> chooserSearch;
    while(cin.fail() || chooserSearch < 1 || chooserSearch > 4){
    cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
    cin.clear();
    cin.sync();
    cin >> chooserSearch;
    }

    if(chooserSearch == 1){
        system("cls");
        searchStudents();
    }
    if(chooserSearch == 2){
        system("cls");
        searchTeachers();
    }

    if(chooserSearch == 3){
        system("cls");
        searchTeams();
    }

    if(chooserSearch == 4){
        system("cls");
        mainMenu();
    }

}

