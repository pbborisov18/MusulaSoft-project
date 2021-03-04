#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void fileExists(string test);                                            //Link to a function which checks if a file is created
void teamMenu();                                                         //Links this cpp file to the team menu
void searchStudentsTm();                                                 //Links this cpp file to search students for a team function
void searchTeachers();                                                   //Links this cpp file to search teachers for a team function
vector<string> searchStudentTeam(string searchTermS);                    //Search for the student in Students.csv
vector<string> searchTeacherTeam(string searchTermT);                    //Search for the student in Teachers.csv
void connectionsChangeStudentTeam(string studentName,string studentTeam);//Changes students team so they can't be in more than 1 team
void connectionsChangeTeacherTeam(string teacherName);                   //Changes the number of teams of the teacher

struct TEAMS{   //Structure for entering a teams information
    string teamName;
    string teammate1;
    string teammate2;
    string teammate3;
    string teammate4;
    string teacher;
} team;

void teamsAdd(){
    cout << "Choose team name:";
    cin.ignore( 1000, '\n' );
    getline(cin,team.teamName); //User enters the team name

    cout << "Choose student 1(Email): ";
    cin >> team.teammate1;  //User enters the 1st student email
    vector<string> data1 = searchStudentTeam(team.teammate1);    //Goes to this function and looks if this email is in Students.csv
    connectionsChangeStudentTeam(data1[2],team.teamName);  //Goes to the function which changes the students team to the team name chosen at the start of the creation process

    cout << "Choose student 2(Email): ";
    cin >> team.teammate2;  //User enters the 2nd student email
    vector<string> data2 = searchStudentTeam(team.teammate2);    //Goes to this function and looks if this email is in Students.csv
    connectionsChangeStudentTeam(data2[2],team.teamName);  //Goes to the function which changes the students team to the team name chosen at the start of the creation process

    cout << "Choose student 3(Email): ";
    cin >> team.teammate3;  //User enters the 3rd student email
    vector<string> data3 = searchStudentTeam(team.teammate3);    //Goes to this function and looks if this email is in Students.csv
    connectionsChangeStudentTeam(data3[2],team.teamName);  //Goes to the function which changes the students team to the team name chosen at the start of the creation process

    cout << "Choose student 4(Email): ";
    cin >> team.teammate4;  //User enters the 3th student email
    vector<string> data4 = searchStudentTeam(team.teammate4);    //Goes to this function and looks if this email is in Students.csv
    connectionsChangeStudentTeam(data4[2],team.teamName);  //Goes to the function which changes the students team to the team name chosen at the start of the creation process

    cout << "Choose Leader(Email): ";
    cin >> team.teacher;    //User enters the teacher's email
    vector<string> data5 = searchTeacherTeam(team.teacher);      //Goes to this function and looks if this email is in Teachers.csv
    connectionsChangeTeacherTeam(data5[2]);    //Goes to the function which changes the number of teams the teacher is in

    fstream file;

    fileExists("Teams.csv"); //Checks if Teams.csv exists otherwise it creates it

    file.open("Teams.csv", ios::app); //Opens the file Teams.csv

        file << team.teamName << "," << data1[2] << "," << data2[2] << "," << data3[2] << "," << data4[2] << "," << data5[2] << "\n"; //Writes the team name, students emails and teachers email

    file.close();   //Closes Teams.csv

    teamMenu();     //Goes back to team menu
}
