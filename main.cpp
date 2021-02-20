#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

void studentsAdd();     //function which adds students to the excel
void teacherAdd();      //function which adds teams to the excel
void teamsAdd();        //function which adds teachers to the excel
void studentsEdit();    //function which edits students in the excel
void teamsEdit();       //function which edits teams in the excel
void teachersEdit();    //function which edits teachers in the excel
void studentsDelete();  //function which deletes students off the excel
void teamsDelete();     //function which deletes teams off the excel
void teachersDelete();  //function which deletes teachers off the excel
void searchTeams();     //search function for teams
void searchNames();     //search function for names
void mainMenu();        //function main menu

int main()
{
    mainMenu();
    return 0;
}
