#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

void connectionsTeamStudents(string oldStudentEmail, string newStudentEmail,string nameOfTeam);

void editTeamClassmates(string newStudentEmail, string teamNameOfStudent, int studentNumberInTeam){

    ifstream read;
    ofstream fileCreate{"TeamsTemp.csv"};
    fileCreate.close();
    fstream write;

    read.open("Teams.csv");
    write.open("TeamsTemp.csv");

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

        if(teamName == teamNameOfStudent){
            if(studentNumberInTeam == 1){
                write << teamName << "," << newStudentEmail << "," << student2 << "," << student3 << "," << student4 << "," << teacher << "\n";
                connectionsTeamStudents(student1, newStudentEmail, teamNameOfStudent);
             }
            if(studentNumberInTeam == 2){
                write << teamName << "," << student1 << "," << newStudentEmail << "," << student3 << "," << student4 << "," << teacher << "\n";
                connectionsTeamStudents(student2, newStudentEmail, teamNameOfStudent);
            }
            if(studentNumberInTeam == 3){
                write << teamName << "," << student1 << "," << student2 << "," << newStudentEmail << "," << student4 << "," << teacher << "\n";
                connectionsTeamStudents(student3, newStudentEmail, teamNameOfStudent);
            }
            if(studentNumberInTeam == 4){
                write << teamName << "," << student1 << "," << student2 << "," << student3 << "," << newStudentEmail << "," << teacher << "\n";
                connectionsTeamStudents(student4, newStudentEmail, teamNameOfStudent);
            }
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
