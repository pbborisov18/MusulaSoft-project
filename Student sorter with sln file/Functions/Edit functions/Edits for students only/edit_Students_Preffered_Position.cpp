#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

void editPreferredPos(string emailToBeEdited,string newPosition){
    ifstream read;
    ofstream fileCreate{"StudentsTemp.csv"};
    fileCreate.close();
    fstream write;

    read.open("Students.csv", ios::app);
    write.open("StudentsTemp.csv", ios::app);

    string cell1;   //string for every column of information
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

        if(cell3 == emailToBeEdited){
            write << cell1 << "," << cell2 << "," << cell3 << "," << newPosition << "," << cell5 << "," << cell6 << "\n";
        }
        else{
            write << cell1 << "," << cell2 << "," << cell3 << "," << cell4 << "," << cell5 << "," << cell6 << "\n";
        }
    }

    read.close();
    write.close();

    remove("Students.csv");
    rename("StudentsTemp.csv","Students.csv");

    cout << "\nStudent's preferred position changed successfully!\n\n";
    system("pause");

    return;
}
