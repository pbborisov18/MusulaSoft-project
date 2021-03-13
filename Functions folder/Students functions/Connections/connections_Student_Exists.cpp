#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool connectionsStudentExists(string studentEmail){

    vector<string> record; //temporary vector which is used to record the information gathered by the function

    ifstream file;          //Creates variable file
    file.open("Students.csv");    //Opens the file from the variable fileName() in this case Students.csv

    bool foundRecord = false;

    string firstName;
    string secondName;
    string email;
    string preferredpos;
    string classv;
    string inATeam;

    while(getline(file,firstName,',') && !foundRecord){ //While loop which is entered if there is text between the start of the row and first comma and that the variable foundRecord is false
        getline(file,secondName,',');   //Stores all information between commas in the strings
        getline(file,email,',');
        getline(file,preferredpos,',');
        getline(file,classv,',');
        getline(file,inATeam,'\n');

        if(email == studentEmail){ //If the email is found it enters the if() statement

            foundRecord=true; //After the email is found there is no point to look for it anymore

            record.push_back(firstName);    //Saves the information in the record vector
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(preferredpos);
            record.push_back(classv);
            record.push_back(inATeam);
        }
    }

if(foundRecord==true){  //If we found the student we display the information about him
        cout << "\nFirst Name: " << record[0] << "\n"
             << "Last Name: " << record[1] << "\n"
             << "Email: " << record[2] << "\n"
             << "Preferred position: " << record[3] << "\n"
             << "Class: " << record[4] << "\n"
             << "Team: "<< record[5] << "\n\n";
        return true;
}
else{
    return false;
}
}
