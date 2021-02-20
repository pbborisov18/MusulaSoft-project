#include <iostream>
using namespace std;

    void mainMenu();
    void searchNames();
    void searchTeams();

void searchMenu(){



    system("cls");
    cout << "      Search \n\n";
    cout << "1.Names \n";
    cout << "2.Teams \n";
    cout << "3.Go back to Team Sorter\n";

    int chooserSearch;
    cin >> chooserSearch;
    while(cin.fail() || chooserSearch < 1 || chooserSearch > 3){
    cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-3" << endl;
    cin.clear();
    cin.sync();
    cin >> chooserSearch;
    }

    if(chooserSearch == 1){
        system("cls");
        searchNames();
    }

    if(chooserSearch == 2){
        system("cls");
        searchTeams();
    }

    if(chooserSearch == 3){
        system("cls");
        mainMenu();
    }

}

