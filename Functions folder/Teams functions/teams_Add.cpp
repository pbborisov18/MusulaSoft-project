#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void teamMenu();
void searchStudentsTm();
void searchTeachers();
vector<string> searchStudentTeam(string fileNameS, string searchTermS);
vector<string> searchTeacherTeam(string fileNameT, string searchTermT);
void changeStudentTeam(string studentName,string studentTeam);

struct TEAMS{
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
    getline(cin,team.teamName);


    cout << "Choose student 1. ";

    cin >> team.teammate1;
    vector<string> data1 = searchStudentTeam("Students.csv",team.teammate1);
    changeStudentTeam(data1[0],team.teamName);

    cout << "Choose student 2. ";

    cin >> team.teammate2;
    vector<string> data2 = searchStudentTeam("Students.csv",team.teammate2);
    changeStudentTeam(data2[0],team.teamName);

    cout << "Choose student 3. ";

    cin >> team.teammate3;
    vector<string> data3 = searchStudentTeam("Students.csv",team.teammate3);
    changeStudentTeam(data3[0],team.teamName);

    cout << "Choose student 4. ";

    cin >> team.teammate4;
    vector<string> data4 = searchStudentTeam("Students.csv",team.teammate4);
    changeStudentTeam(data4[0],team.teamName);

    cout << "Choose Leader. ";

    cin >> team.teacher;
    vector<string> data5 = searchTeacherTeam("Teachers.csv",team.teacher);


    fstream file;

    file.open("Teams.csv", ios::app);

        file << team.teamName << "," << data1[0] << data1[1] << "," << data2[0] << data2[1] << "," << data3[0] << data3[1] << "," << data4[0] << data4[1] << "," << data5[0] << data5[1] << "\n";

    file.close();






    teamMenu();
}
