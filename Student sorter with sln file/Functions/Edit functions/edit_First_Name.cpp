#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;


void editFirstName(string emailToBeEdited, string fileToEdit, string tempFileName, string editNameTo){

ifstream file;
fstream fileCreate{tempFileName};

file.open(fileToEdit, ios::app);
fileCreate.open(tempFileName, ios::app);

    string cell1;   //string for every column of information
    string cell2;
    string cell3;
    string cell4;
    string cell5;
    string cell6;

    while(getline(file,cell1,',')){
        getline(file,cell2,',');   //Gets the entire rows information in different variables
        getline(file,cell3,',');
        getline(file,cell4,',');
        getline(file,cell5,',');
        getline(file,cell6,'\n');

        if(cell3 == emailToBeEdited){
            fileCreate << editNameTo << "," << cell2 << "," << cell3 << "," << cell4 << "," << cell5 << "," << cell6 << "\n";
        }
        else{
            fileCreate << cell1 << "," << cell2 << "," << cell3 << "," << cell4 << "," << cell5 << "," << cell6 << "\n";
        }
    }
    file.close();
    fileCreate.close();

    remove(fileToEdit.c_str()); //Deletes
    rename(tempFileName.c_str(), fileToEdit.c_str()); //Renames the temporary file StudentsTemp.csv to Students.csv

    cout << "\nFirst name renamed successfully!\n\n";
    system("pause");

    return;
}
