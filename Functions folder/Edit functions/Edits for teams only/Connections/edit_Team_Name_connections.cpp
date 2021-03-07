#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

void connectionsChangeTeamNameStudents(string oldTeamName, string newTeamName){

    ifstream read;
    ofstream create("StudentsTemp.csv");
    create.close();
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
        getline(read,cell2,',');   //Gets the entire rows information in different variables
        getline(read,cell3,',');
        getline(read,cell4,',');
        getline(read,cell5,',');
        getline(read,cell6,'\n');

        if(cell6 == oldTeamName){
            write << cell1 << "," << cell2 << "," << cell3 << "," << cell4 << "," << cell5 << "," << newTeamName << "\n";
        }
        else{
            write << cell1 << "," << cell2 << "," << cell3 << "," << cell4 << "," << cell5 << "," << cell6 << "\n";
        }
    }

    read.close();
    write.close();

    remove("Students.csv");
    rename("StudentsTemp.csv","Students.csv");

    return;
}
