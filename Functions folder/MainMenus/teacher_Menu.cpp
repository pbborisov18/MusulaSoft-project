#include <iostream>
using namespace std;

    void mainMenu();
    void teacherAdd();
    void teachersDelete();
    void teachersEdit();

void teacherMenu(){

    system("cls");
    cout << "      Teacher Editor \n\n";
    cout << "1.Add Teacher \n";
    cout << "2.Remove Teacher \n";
    cout << "3.Edit Teacher Information\n";
    cout << "4.Go back to Team Sorter\n";

    int chooserTeEditor;
    cin >> chooserTeEditor;
    while(cin.fail() || chooserTeEditor < 1 || chooserTeEditor > 4){
    cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
    cin.clear();
    cin.sync();
    cin >> chooserTeEditor;
    }

    if(chooserTeEditor == 1){
        system("cls");
        teacherAdd();
    }

    if(chooserTeEditor == 2){
        system("cls");
        teachersDelete();
    }

    if(chooserTeEditor == 3){
        system("cls");
        teachersEdit();
    }

    if(chooserTeEditor == 4){
        system("cls");
        mainMenu();
    }

}
