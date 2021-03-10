#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

void teamsAdd();

vector<string> searchStudentTeam(string searchTermS){ //Searches for students in Students.csv to add to the team
    vector<string> record;  //temporary vector to store the student's information

    ifstream file;
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

        if(email == searchTermS){   //If the searched email is found it enters the if() statement

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

        cout << "\nFirst Name: " << record[0] << "\n"
             << "Last Name: " << record[1] << "\n"
             << "Email: " << record[2] << "\n"
             << "Preferred position: " << record[3] << "\n"
             << "Class: " << record[4] << "\n"
             << "Team: "<< record[5] << "\n";

        if(record[5] == "No" || record[5] == "no" || record[5] == "no!" || record[5] == "No!" || record[5] == "NO!" || record[5] == "NO"){} //We check if the student has a team
        else{   // If he has a team we prompt the user to search again
            cout << "\nStudent already in a Team! Search for another Student: ";
            string searchAgain;
            cin >> searchAgain;
            searchStudentTeam(searchAgain);
        }

}
else{   //If the student isn't found we tell the user and prompt him to try again
    cout << "\nStudent was not found!Try again!: ";
    string searchAgain;
    cin >> searchAgain;
    searchStudentTeam(searchAgain);
}

return record;  //returns the vector record to teamsAdd();

}
