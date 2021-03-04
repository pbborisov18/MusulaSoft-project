#include <fstream>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>
using namespace std;

void connectionsChangeStudentTeam(string studentName,string studentTeam){  //Changes the student's team

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

        if(email != studentName){ //We enter the if statement if the name of the student isn't what we want to edit

            vector<string> record; //Vector temporary used to save students information from the variables earlier

            record.push_back(firstName); //Saves the information in the temporary vector record
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(preferredpos);
            record.push_back(classv);
            record.push_back(inATeam);

            fileNew << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," << record[5] << "\n"; //Writing the information we got earlier to the temporary file StudentsTemp.csv
            record.clear(); //Clears the vector of all varibles. Resets it
        }
        else{ //When we find the student we want we enter the if statement and write everything the same except the team's name which we change to the variable of the function studentTeam
            vector<string> record;

            record.push_back(firstName);
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(preferredpos);
            record.push_back(classv);
            record.push_back(inATeam);

            fileNew << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," << studentTeam << "\n";
            record.clear();
        }
    }

    fileNew.close();    //Closes StudentsTemp.csv
    file.close();       //Closes Students.csv

    remove("Students.csv"); //Deletes Students.csv
    rename("StudentsTemp.csv", "Students.csv"); //Renames the temporary file StudentsTemp.csv to Students.csv



return;

}
