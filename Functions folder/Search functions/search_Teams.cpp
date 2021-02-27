#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

void searchMenu();  //Links to the search menu

vector<string> searchTeam(string fileName, string searchTerm){ //Creates a function of type vector<string> with variables fileName(The name of the file which is Students.csv) and the searchTerm(The name for which we are searching for)

    vector<string> record; //temporary vector which is used to record the information gathered by the function

    ifstream file;
    file.open(fileName); //Opens the file from the variable fileName() in this case Students.csv

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

if(foundRecord==true){  //If we found the student we display the information about him
        cout << "Team Name: " << record[0] << "\n"
             << "Student1: " << record[1] << "\n"
             << "Student2: " << record[2] << "\n"
             << "Student3: " << record[3] << "\n"
             << "Student4 " << record[4] << "\n"
             << "Teacher: " << record[5] << "\n";
}
else{   //Otherwise we tell the user the student was not found
    cout << "Team was not found!\n";
}
return record; //

}

void searchTeams(){

    cout<<"Enter Team Name: ";

    string name;
    cin >> name; //User's search

    searchTeam("Teams.csv",name); //we call the function

    system("pause");//Bad practise because users who use different os won't work. Pauses the program so the user can read what he searched for
    searchMenu();

}

