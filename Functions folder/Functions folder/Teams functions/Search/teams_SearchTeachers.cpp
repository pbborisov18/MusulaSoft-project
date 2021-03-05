#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

void teamsAdd();

vector<string> searchTeacherTeam(string searchTermT){   //Searches for teachers in Teachers.csv to add to the team
    vector<string> record;  //temporary vector to store the student's information

    ifstream file;
    file.open("Teachers.csv");  //opens Teachers.csv

    bool foundRecord = false;

    string firstName;
    string secondName;
    string email;
    string teams;

    while(getline(file,firstName,',') && !foundRecord){ //While loop which is entered if there is text between the start of the row and first comma and that the variable foundRecord is false
        getline(file,secondName,',');   //Stores all information between commas in the strings until the end of the row
        getline(file,email,',');
        getline(file,teams,'\n');

        if(email == searchTermT){   //If the searched email is found it enters the if() statement

            foundRecord=true;   //After the email is found there is no point to look for it anymore

            record.push_back(firstName);    //Saves the information in the temporary vector record
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(teams);

        }
    }

if(foundRecord==true){  //If we found the teacher we display the information about him
        cout << "\nFirst Name: " << record[0] << "\n"
             << "Last Name: " << record[1] << "\n"
             << "Email: " << record[2] << "\n"
             << "Teams: "<< record[3] << "\n";

}
else{   //If the teacher isn't found we tell the user and prompt him to try again
    cout << "\nTeacher was not found!Try again(Email): ";
    string searchAgain;
    cin >> searchAgain;
    searchTeacherTeam(searchAgain);
}
return record;

}
