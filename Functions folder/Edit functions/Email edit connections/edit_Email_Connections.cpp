#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

void connectionsEmailChangeTeams(string emailToBeEdited, string editTo){
    ifstream read;
    ofstream create{"TeamsTemp.csv"};
    create.close();
    fstream writeNew;

    read.open("Teams.csv");
    writeNew.open("TeamsTemp.csv");

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

        if(student1 == emailToBeEdited){ //If the name is found it enteres the if() statement
            writeNew << teamName << "," << editTo << "," << student2 << "," << student3 << "," << student4 << "," << teacher << "\n";

        }

        if(student2 == emailToBeEdited){
            writeNew << teamName << "," << student1 << "," << editTo << "," << student3 << "," << student4 << "," << teacher << "\n";
        }

        if(student3 == emailToBeEdited){
            writeNew << teamName << "," << student1 << "," << student2 << "," << editTo << "," << student4 << "," << teacher << "\n";
        }

        if(student4 == emailToBeEdited){
            writeNew << teamName << "," << student1 << "," << student2 << "," << student4 << "," << editTo << "," << teacher << "\n";
        }

        if(teacher == emailToBeEdited){
            writeNew << teamName << "," << student1 << "," << student2 << "," << student4 << "," << student4 << "," << editTo << "\n";
        }
        if(student1 != emailToBeEdited && student2 != emailToBeEdited && student3 != emailToBeEdited && student4 != emailToBeEdited && teacher != emailToBeEdited){
            writeNew << teamName << "," << student1 << "," << student2 << "," << student4 << "," << student4 << "," << teacher << "\n";
        }
    }

    read.close();
    writeNew.close();

    remove("Teams.csv");
    rename("TeamsTemp.csv","Teams.csv");

    return;

}
