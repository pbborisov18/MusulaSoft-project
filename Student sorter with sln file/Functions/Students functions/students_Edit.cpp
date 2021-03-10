#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void studentsEditMenu(string studentToBeEdited);
bool searchStudent(string searchTerm);
void studentMenu();

void studentsEdit(){
system("cls");
cout << "Which student's information do you want to edit(email): ";

string studentFind;
cin >> studentFind;

if(searchStudent(studentFind)==true){
    studentsEditMenu(studentFind);
}
else{
    system("pause");
    studentMenu();
}


}
