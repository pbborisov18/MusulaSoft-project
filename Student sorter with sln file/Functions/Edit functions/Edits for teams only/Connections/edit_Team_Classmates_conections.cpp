#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

void connectionsTeamStudents(string oldStudentEmail, string newStudentEmail,string nameOfTeam){

    ifstream read;
    ofstream fileCreate("StudentsTemp.csv");
    fileCreate.close();
    fstream write;

    read.open("Students.csv");
    write.open("StudentsTemp.csv");

    string cell1;
    string cell2;
    string cell3;
    string cell4;
    string cell5;
    string cell6;

    while(getline(read,cell1,',')){
        getline(read,cell2,',');
        getline(read,cell3,',');
        getline(read,cell4,',');
        getline(read,cell5,',');
        getline(read,cell6,'\n');

        if(cell3 != oldStudentEmail && cell3 != newStudentEmail){
            write << cell1 << "," << cell2 << "," << cell3 << "," << cell4 << "," << cell5 << "," << cell6 << "\n";
        }

        if(cell3 == newStudentEmail){
            write << cell1 << "," << cell2 << "," << cell3 << "," << cell4 << "," << cell5 << "," << nameOfTeam << "\n";
        }

        if(cell3 == oldStudentEmail){
            write << cell1 << "," << cell2 << "," << cell3 << "," << cell4 << "," << cell5 << "," << "No" << "\n";
        }

    }

    read.close();
    write.close();

    remove("Students.csv");
    rename("StudentsTemp.csv","Students.csv");

    return;
}
