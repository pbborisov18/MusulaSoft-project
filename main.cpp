#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Students menu*/
void studentsAdd(); //function which adds students to Students.csv

void studentsDelete();  //function which deletes students off Students.csv
void connectionsRemoveStudentFromTeam(string studentEmail); //connections from Students.csv to Teams.csv

void studentsEdit();    //function which edits students information in Students.csv

/* Teachers menu*/
void teachersAdd(); //function which adds teachers to Teachers.csv

void teachersDelete();  //function which deletes teachers off Teachers.csv
void connectionsRemoveTeacherFromTeam(string teacherEmail); //connections from Teachers.csv to Teams.csv

void teachersEdit();    //function which edits teachers information in Teachers.csv

/* Teams menu*/
void teamsAdd();    //function which adds teams to Teams.csv
vector<string> searchStudentTeam(string searchTermS);   //connections from Teams.csv to Students.csv Used for displaying information to the user and checking if student is legible to be in a team
vector<string> searchTeacherTeam(string searchTermT);   //connections from Teams.csv to Teachers.csv Used for displaying information to the user
void connectionsChangeStudentTeam(string studentName,string studentTeam);   //connections from Teams.csv to Students.csv Used for changing students team in Students.csv
void connectionsChangeTeacherTeam(string teacherEmail); //connections from Teams.csv to Teachers.csv Used for changing the number of teams the teacher is part in

void teamsDelete(); //function which deletes teams off Teams.csv
void connectionsChangeStudentTeamToNo(string teamName); //connection from Teams.csv to Students.csv Used for changing the team to No after deletion of the team
void connectionsChangeTeacherTeamDown(string teacherEmail); //connection from Teams.csv to Teachers.csv Used for changing the number of teams the teacher is part in

void teamsEdit();   //function which edits teams information in Teams.csv

/* Search menu*/
void searchStudents();  //search function for students      Working as expected

void searchTeachers();  //search function for teachers      Working as expected

void searchTeams(); //search function for teams             Working as expected



void mainMenu();

int main()
{
    mainMenu();
    return 0;
}
