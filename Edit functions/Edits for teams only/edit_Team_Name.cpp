#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;

void connectionsChangeTeamNameStudents(string oldTeamName, string newTeamName);

void editTeamName(string teamToBeEdited,string editTo){

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

        if(teamName == teamToBeEdited){
            write << editTo << "," << student1 << "," << student2 << "," << student3 << "," << student4 << "," << teacher << "\n";
            connectionsChangeTeamNameStudents(teamToBeEdited, editTo);
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
