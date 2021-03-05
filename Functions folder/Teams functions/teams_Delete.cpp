//No connections to Teachers.csv
//No connections to Students.csv

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void teamMenu();
void fileExists(string nameOfFile);

void teamsDelete(){
    cout << "Name of the team wanted to be deleted:";
    string searchTerm;

    cin.ignore( 1000, '\n' );
    getline(cin,searchTerm); //User enters the name of the team which must be deleted

    fileExists("Teams.csv"); //Checks if Teams.csv exists otherwise it creates it

    fstream fileCreate {"TeamsTemp.csv"}; //Creates a temporary file

    ifstream file;
    file.open("Teams.csv",ios::app); //Opens Teams.csv in append mode
    fileCreate.open("TeamsTemp.csv",ios::app); //Opens the temporary file TeamsTemp.csv in append mode

    string teamName;   //string for every column of information
    string student1;
    string student2;
    string student3;
    string student4;
    string teacher;

    while(getline(file,teamName,',')){ //If there is text between the start of the document and the first comma we enter the while() loop
        getline(file,student1,',');   //Gets the entire rows information in different variables
        getline(file,student2,',');
        getline(file,student3,',');
        getline(file,student4,',');
        getline(file,teacher,'\n');

        if(teamName != searchTerm){ //If the name of the team isn't what the user wants deleted we enter the if() statement

            vector<string> record; //Vector temporary used to save students information from the variables earlier

            record.push_back(teamName);
            record.push_back(student1);
            record.push_back(student2);
            record.push_back(student3);
            record.push_back(student4);
            record.push_back(teacher);

            fileCreate << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," << record[5] << "\n"; //Writing the information we got earlier to the temporary file TeamsTemp.csv

            record.clear(); //Clears the vector of all varibles. Resets it
        }
    }

    fileCreate.close(); //Closes TeamsTemp.csv
    file.close();       //Closes Teams.csv

    remove("Teams.csv"); //Delets Teams.csv
    rename("TeamsTemp.csv", "Teams.csv"); //Renames the temporary file TeamsTemp.csv to Teams.csv

    teamMenu();  //Goes back to the student menu
}
