#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

void connectionsChangeTeacherTeamDown(string teacherEmail);
void connectionsChangeTeacherTeam(string teacherEmail);

void editTeamTeachers(string teacherEmail,string teamNameOfTecher){

    ifstream read;
    ofstream fileCreate{"TeamsTemp.csv"};
    fileCreate.close();
    fstream write;

    read.open("Teams.csv", ios::app);
    write.open("TeamsTemp.csv", ios::app);

    string teamName;
    string student1;
    string student2;
    string student3;
    string student4;
    string teacher;


    while(getline(read,teamName,',')){ //While loop which is entered if there is text between the start of the row and first comma and that the variable foundRecord is false
        getline(read,student1,',');     //Stores all information between commas in the strings
        getline(read,student2,',');
        getline(read,student3,',');
        getline(read,student4,',');
        getline(read,teacher,'\n');

        if(teamName == teamNameOfTecher){
            write << teamName << "," << student1 << "," << student2 << "," << student3 << "," << student4 << "," << teacherEmail << "\n";
            connectionsChangeTeacherTeam(teacherEmail);
            connectionsChangeTeacherTeamDown(teacher);
        }

        else{
            write << teamName << "," << student1 << "," << student2 << "," << student3 << "," << student4 << "," << teacher << "\n";
        }


    }

    read.close();
    write.close();

    remove("Teams.csv");
    rename("TeamsTemp.csv","Teams.csv");

    return;
}
