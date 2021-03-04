#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

void studentsAdd();     //function which adds students to Students.csv                      done
void teachersAdd();      //function which adds teachers to Teachers.csv                     done
void teamsAdd();        //function which adds teams to Teams.csv                            done
void studentsDelete();  //function which deletes students off Students.csv                  done (No connections)
void teachersDelete();  //function which deletes teachers off Teachers.csv                  done (No connections)
void teamsDelete();     //function which deletes teams off Teams.csv
void studentsEdit();    //function which edits students information in Students.csv
void teachersEdit();    //function which edits teachers information in Teachers.csv
void teamsEdit();       //function which edits teams information in Teams.csv
void searchStudents();  //search function for students                                      done
void searchTeachers();  //search function for teachers                                      done
void searchTeams();     //search function for teams                                         done
void searchStudentsTm();//search function for students in teams menu
void searchTeachersTm();//search function for teachers in teams menu
void mainMenu();        //function main menu

int main()
{
    mainMenu();
    return 0;
}
