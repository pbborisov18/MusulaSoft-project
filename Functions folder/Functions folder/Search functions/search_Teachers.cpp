#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

void searchMenu();  //Links to the search menu

void searchTeacher(string searchTerm){ //Creates a function with variable searchTerm(The email for which we are searching for)

    vector<string> record; //temporary vector which is used to record the information gathered by the function

    ifstream file;
    file.open("Teachers.csv"); //Opens the file "Teachers.csv"

    bool foundRecord = false;

    string firstName;
    string secondName;
    string email;
    string inATeam;

    while(getline(file,firstName,',') && !foundRecord){ //While loop which is entered if there is text between the start of the row and first comma and that the variable foundRecord is false
        getline(file,secondName,',');   //Stores all information between commas in the strings
        getline(file,email,',');
        getline(file,inATeam,'\n');

        if(email == searchTerm){ //If the email is found it enteres the if() statement

            foundRecord=true; //After the email is found there is no point to look for it anymor

            record.push_back(firstName);    //Saves the information in the record vector
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(inATeam);
        }
    }

    if(foundRecord==true){  //If we found the teacher we display the information about him
        cout << "\nFirst Name: " << record[0] << "\n"
             << "Last Name: " << record[1] << "\n"
             << "Email: " << record[2] << "\n"
             << "Team: "<< record[3] << "\n\n";
    }

    else{   //Otherwise we tell the user the teacher was not found
    cout << "Teacher was not found!\n";
    }


}
