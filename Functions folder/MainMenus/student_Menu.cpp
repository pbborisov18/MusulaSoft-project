#include <iostream>
using namespace std;

    void mainMenu();
    void studentsEdit();
    void studentsDelete();
    void studentAdd();

void studentMenu(){



    system("cls");
    cout << "      Student Editor \n\n";
    cout << "1.Add Student\n";
    cout << "2.Remove Student\n";
    cout << "3.Edit Student Information\n";
    cout << "4.Go back to Team Sorter\n";

    int chooserStEditor;
    cin >> chooserStEditor;
    while(cin.fail() || chooserStEditor < 1 || chooserStEditor > 4){
    cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-4" << endl;
    cin.clear();
    cin.sync();
    cin >> chooserStEditor;
    }

    if(chooserStEditor == 1){
        system("cls");
        studentAdd();
    }

    if(chooserStEditor == 2){
        system("cls");
        studentsDelete();
    }

    if(chooserStEditor == 3){
        system("cls");
        studentsEdit();
    }

    if(chooserStEditor == 4){
        system("cls");
        mainMenu();
    }

}
