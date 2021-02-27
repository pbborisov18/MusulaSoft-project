#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

void studentAdd();     //function which adds students to Students.csv
void teacherAdd();      //function which adds teachers to Teachers.csv
void teamsAdd();        //function which adds teams to Teams.csv
void studentsEdit();    //function which edits students information in Students.csv
void teachersEdit();    //function which edits teachers information in Teachers.csv
void teamsEdit();       //function which edits teams information in Teams.csv
void studentsDelete();  //function which deletes students off Students.csv
void teachersDelete();  //function which deletes teachers off Teachers.csv
void teamsDelete();     //function which deletes teams off Teams.csv
void searchTeams();     //search function for teams
void searchStudents();  //search function for students
void searchTeachers();  //search function for teachers
void searchStudentsTm();//search function for students in teams menu
void searchTeachersTm();//search function for teachers in teams menu
void mainMenu();        //function main menu

int main()
{
    mainMenu();
    return 0;
}
