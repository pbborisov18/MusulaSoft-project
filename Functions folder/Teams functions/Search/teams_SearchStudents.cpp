#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

void teamsAdd();

vector<string> searchStudentTeam(string fileNameS, string searchTermS){
    vector<string> record;

    ifstream file;
    file.open(fileNameS);

    bool foundRecord = false;

    string firstName;
    string secondName;
    string email;
    string preferredpos;
    string classv;
    string inATeam;

    while(getline(file,firstName,',') && !foundRecord){
        getline(file,secondName,',');
        getline(file,email,',');
        getline(file,preferredpos,',');
        getline(file,classv,',');
        getline(file,inATeam,'\n');


        if(firstName == searchTermS){
            foundRecord=true;

            record.push_back(firstName);
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(preferredpos);
            record.push_back(classv);
            record.push_back(inATeam);

        }
    }

if(foundRecord==true){
        cout << "First Name: " << record[0] << "\n"
             << "Last Name: " << record[1] << "\n"
             << "Email: " << record[2] << "\n"
             << "Preferred position: " << record[3] << "\n"
             << "Class: " << record[4] << "\n"
             << "Team: "<< record[5] << "\n";

        if(record[5] == "No" || record[5] == "no" || record[5] == "no!" || record[5] == "No!" || record[5] == "NO!" || record[5] == "NO"){

            }
        else{
            cout << "Student already in a Team! Search for another Student.\n";
            string searchAgain;
            cin >> searchAgain;
            searchStudentTeam("Students.csv",searchAgain);
        }

}
else{
    cout << "Student was not found!Try again!\n";
    string searchAgain;
    cin >> searchAgain;
    searchStudentTeam("Students.csv",searchAgain);
}
return record;

}
