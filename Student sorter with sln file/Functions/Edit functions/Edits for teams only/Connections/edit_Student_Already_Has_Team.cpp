#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

void teamsAdd();

bool connectionsStudentAlreadyHasATeam(string studentEmail){ //Searches for students in Students.csv to add to the team
    vector<string> record;  //temporary vector to store the student's information

    fstream file;
    file.open("Students.csv"); //opens Students.csv

    bool foundRecord = false;

    string firstName;
    string secondName;
    string email;
    string preferredpos;
    string classv;
    string inATeam;

    while(getline(file,firstName,',') && !foundRecord){ //While loop which is entered if there is text between the start of the row and first comma and that the variable foundRecord is false
        getline(file,secondName,',');   //Stores all information between commas in the strings until the end of the row
        getline(file,email,',');
        getline(file,preferredpos,',');
        getline(file,classv,',');
        getline(file,inATeam,'\n');

        if(email == studentEmail){   //If the searched email is found it enters the if() statement

            foundRecord=true;   //After the email is found there is no point to look for it anymore

            record.push_back(firstName);    //Saves the information in the temporary vector record
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(preferredpos);
            record.push_back(classv);
            record.push_back(inATeam);

        }
    }

if(foundRecord==true){  //If we found the student we display the information about him

        if(record[5] == "No" || record[5] == "no" || record[5] == "no!" || record[5] == "No!" || record[5] == "NO!" || record[5] == "NO"){
            return true;
        } //We check if the student has a team
        else{   // If he has a team we prompt the user to search again
            cout << "\nStudent is already in a Team!\n";
            return false;
        }

}
else{   //If the student isn't found we tell the user and prompt him to try again
    cout << "\nStudent was not found!Try again!: ";
    return false;
}


}

