#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void fileExists(string nameOfFile);

void connectionsRemoveStudentTeam(string studentEmail){ //function responsible for deletion of the students email from Teams.csv

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

        if(student1 != studentEmail && student2 != studentEmail && student3 != studentEmail && student4 !=studentEmail){

            fileCreate << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," << record[5] << "\n"; //Writing the information we got earlier to the temporary file TeamsTemp.csv

            record.clear(); //Clears the vector of all varibles. Resets it

        }

            if(student1 == studentEmail){
                fileCreate << record[0] << "," << " " << "," << record[2] << "," << record[3] << "," << record[4] << "," << record[5] << "\n";  //Writing the information we got earlier to the temporary file TeamsTemp.csv depending on which student we want to remove from Teams.csv
                record.clear(); //Clears the vector of all varibles. Resets it
            }

            if(student2 == studentEmail){
                fileCreate << record[0] << "," << record[1] << "," << " " << "," << record[3] << "," << record[4] << "," << record[5] << "\n";  //Writing the information we got earlier to the temporary file TeamsTemp.csv depending on which student we want to remove from Teams.csv
                record.clear(); //Clears the vector of all varibles. Resets it
            }

            if(student3 == studentEmail){
                fileCreate << record[0] << "," << record[1] << "," << record[2] << "," << " " << "," << record[4] << "," << record[5] << "\n";  //Writing the information we got earlier to the temporary file TeamsTemp.csv depending on which student we want to remove from Teams.csv
                record.clear(); //Clears the vector of all varibles. Resets it
            }

            if(student4 == studentEmail){
                fileCreate << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << " " << "," << record[5] << "\n";  //Writing the information we got earlier to the temporary file TeamsTemp.csv depending on which student we want to remove from Teams.csv
                record.clear(); //Clears the vector of all varibles. Resets it
            }
    }

    file.close();       //Closes both files
    fileCreate.close();

    remove("Teams.csv"); //Delets Teams.csv
    rename("TeamsTemp.csv", "Teams.csv"); //Renames the temporary file TeamsTemp.csv to Teams.csv

    return;


}
