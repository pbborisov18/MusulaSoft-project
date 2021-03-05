#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void fileExists(string nameOfFile);

void connectionsRemoveTeacherTeam(string teacherEmail){

    ifstream file;
    fstream fileCreate{"TeamsTemp.csv"};    //Creates a temporary file

    vector<string> record; //Vector temporary used to save students information from the variables earlier

    fileExists("Teams.csv");

    file.open("Teams.csv", ios::app);           //We open Teams.csv and the temporary file TeamsTemp.csv in append mode
    fileCreate.open("TeamsTemp.csv", ios::app);

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

            record.push_back(teamName); //Saves the information in the temporary vector record
            record.push_back(student1);
            record.push_back(student2);
            record.push_back(student3);
            record.push_back(student4);
            record.push_back(teacher);

        if(teacher != teacherEmail){

            fileCreate << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," << record[5] << "\n";

            record.clear();
        }
        else{
            fileCreate  << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," << " " << "\n";

            record.clear();
        }

    }

    file.close();       //Closes both files
    fileCreate.close();

    cout << "Teacher successfully deleted from Students.csv and Teams.csv\n";
    system("pause");

    remove("Teams.csv"); //Delets Teams.csv
    rename("TeamsTemp.csv", "Teams.csv"); //Renames the temporary file TeamsTemp.csv to Teams.csv

    return;

}
