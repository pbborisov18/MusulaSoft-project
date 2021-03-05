#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
using namespace std;

void connectionsRemoveTeacherTeam(string email);
void fileExists(string nameOfFile);   //Link to a function which checks if a file is created
void teacherMenu(); //Link to teacher menu

void teachersDelete(){

cout << "Email of the teacher wanted to be deleted:";
    string searchTerm;
    cin >> searchTerm; //User enters the name of the teacher who must be deleted

    fileExists("Teachers.csv"); //Checks if Teachers.csv exists otherwise it creates it

    fstream fileCreate {"TeachersTemp.csv"}; //Creates a temporary file

    ifstream file;
    file.open("Teachers.csv",ios::app); //Opens Teachers.csv in append mode
    fileCreate.open("TeachersTemp.csv",ios::app); //Opens the temporary file TeachersTemp.csv in append mode

    string firstName;   //string for every column of information
    string secondName;
    string email;
    string inATeam;

    while(getline(file,firstName,',')){ //If there is text between the start of the document and the first comma we enter the while() loop
        getline(file,secondName,',');   //Gets the entire rows information in different variables
        getline(file,email,',');
        getline(file,inATeam,'\n');

        if(email != searchTerm){ //If the name of the teacher isn't what the user wants deleted we enter the if() statement

            vector<string> record; //Vector temporary used to save teachers information from the variables earlier

            record.push_back(firstName);
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(inATeam);

            fileCreate << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "\n"; //Writing the information we got earlier to the temporary file TeachersTemp.csv

            record.clear(); //Clears the vector of all varibles. Resets it
        }
        else{
            connectionsRemoveTeacherTeam(email);
        }
    }

    fileCreate.close(); //Closes TeachersTemp.csv
    file.close();       //Closes Teachers.csv

    remove("Teachers.csv"); //Delets Teachers.csv
    rename("TeachersTemp.csv", "Teachers.csv"); //Renames the temporary file TeachersTemp.csv to Teachers.csv

    teacherMenu();  //Goes back to the teacher menu

}
