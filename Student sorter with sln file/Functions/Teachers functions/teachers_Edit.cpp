#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool searchTeacher(string searchTerm);
void teachersEditMenu(string teacherToBeEdited);
void teacherMenu();

void teachersEdit(){
system("cls");

cout << "Which teacher's information do you want to edit(email): ";

string teacherFind;
cin >> teacherFind;

if(searchTeacher(teacherFind)==true){
    teachersEditMenu(teacherFind);
}
else{
    system("pause");
    teacherMenu();
}

}
