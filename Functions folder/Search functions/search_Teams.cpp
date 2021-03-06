#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

void searchMenu();  //Links to the search menu

void searchTeam(string searchTerm){ //Creates a function with variable searchTerm(The name for which we are searching for)

    vector<string> record; //temporary vector which is used to record the information gathered by the function

    ifstream file;
    file.open("Teams.csv"); //Opens the file Teams.csv

    bool foundRecord = false;

    string teamName;
    string student1;
    string student2;
    string student3;
    string student4;
    string teacher;

    while(getline(file,teamName,',') && !foundRecord){ //While loop which is entered if there is text between the start of the row and first comma and that the variable foundRecord is false
        getline(file,student1,',');     //Stores all information between commas in the strings
        getline(file,student2,',');
        getline(file,student3,',');
        getline(file,student4,',');
        getline(file,teacher,'\n');

        if(teamName == searchTerm){ //If the name is found it enteres the if() statement

            foundRecord=true; //After the name is found there is no point to look for it anymore

            record.push_back(teamName);     //Saves the information in the record vector
            record.push_back(student1);
            record.push_back(student2);
            record.push_back(student3);
            record.push_back(student4);
            record.push_back(teacher);
        }
    }

if(foundRecord==true){  //If we found the team we display the information about him
        cout << "\nTeam Name: " << record[0] << "\n"
             << "Student1: " << record[1] << "\n"
             << "Student2: " << record[2] << "\n"
             << "Student3: " << record[3] << "\n"
             << "Student4 " << record[4] << "\n"
             << "Teacher: " << record[5] << "\n\n";
}
else{   //Otherwise we tell the user the team was not found
    cout << "\nTeam was not found!\n\n";
}


}

