#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void connectionsChangeStudentTeamToNo(string teamName){  //Changes the students' team in Students.csv to No team

    ifstream file;
    fstream fileNew{"StudentsTemp.csv"}; //Creates a temporary file

    vector<string> record;  //Creates a temporary vector of type string

    string firstName;
    string secondName;
    string email;
    string preferredpos;
    string classv;
    string inATeam;

    file.open("Students.csv", ios::app);        //We open Students.csv and the temporary file StudentsTemp.csv in append mode
    fileNew.open("StudentsTemp.csv", ios::app);

    while(getline(file,firstName,',')){ //While loop which is entered if there is text between the start of the row and first comma
            getline(file,secondName,',');   //Stores all information between commas in the strings until the end of the row
            getline(file,email,',');
            getline(file,preferredpos,',');
            getline(file,classv,',');
            getline(file,inATeam,'\n');

        if(inATeam == teamName){ //We enter the if statement if team name is the one we are searching for

            record.push_back(firstName); //Saves the information in the temporary vector record
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(preferredpos);
            record.push_back(classv);
            record.push_back(inATeam);

            fileNew << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," << "No" << "\n"; //Writing the same information about the student except the team name which is changed to No because his team was just deleted
            record.clear(); //Clears the vector of all varibles. Resets it
        }
        else{   //If the student is not part of that team everything is written the same

            record.push_back(firstName);
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(preferredpos);
            record.push_back(classv);
            record.push_back(inATeam);

            fileNew << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," << record[5] << "\n";
            record.clear(); //Clears the vector of all varibles. Resets it
        }
    }

    fileNew.close();    //Closes StudentsTemp.csv
    file.close();       //Closes Students.csv

    remove("Students.csv"); //Deletes Students.csv
    rename("StudentsTemp.csv", "Students.csv"); //Renames the temporary file StudentsTemp.csv to Students.csv



return;

}

