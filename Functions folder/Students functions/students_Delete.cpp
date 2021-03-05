#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void fileExists(string nameOfFile);   //Link to a function which checks if a file is created
void studentMenu(); //Link to student menu
void connectionsRemoveStudentTeam(string studentEmail);

void studentsDelete(){

    vector<string> conStudentChangeTeam;

    cout << "Email of the student wanted to be deleted:";
    string searchTerm;
    cin >> searchTerm; //User enters the name of the student who must be deleted

    fileExists("Students.csv"); //Checks if Students.csv exists otherwise it creates it

    fstream fileCreate {"StudentsTemp.csv"}; //Creates a temporary file

    ifstream file;
    file.open("Students.csv",ios::app); //Opens Students.csv in append mode
    fileCreate.open("StudentsTemp.csv",ios::app); //Opens the temporary file StudentsTemp.csv in append mode

    string firstName;   //string for every column of information
    string secondName;
    string email;
    string preferredpos;
    string classv;
    string inATeam;

    while(getline(file,firstName,',')){ //If there is text between the start of the document and the first comma we enter the while() loop
        getline(file,secondName,',');   //Gets the entire rows information in different variables
        getline(file,email,',');
        getline(file,preferredpos,',');
        getline(file,classv,',');
        getline(file,inATeam,'\n');

        if(email != searchTerm){ //If the name of the student isn't what the user wants deleted we enter the if() statement

            vector<string> record; //Vector temporary used to save students information from the variables earlier

            record.push_back(firstName);
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(preferredpos);
            record.push_back(classv);
            record.push_back(inATeam);

            fileCreate << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," << record[5] << "\n"; //Writing the information we got earlier to the temporary file StudentsTemp.csv

            record.clear(); //Clears the vector of all varibles. Resets it
        }
        else{
            connectionsRemoveStudentTeam(email);
        }
    }

    fileCreate.close(); //Closes StudentsTemp.csv
    file.close();       //Closes Students.csv

    remove("Students.csv"); //Delets Students.csv
    rename("StudentsTemp.csv", "Students.csv"); //Renames the temporary file StudentsTemp.csv to Students.csv

    cout << "Student successfully deleted from Students.csv and Teams.csv\n"; //Confirmation to the user
    system("pause");

    studentMenu();  //Goes back to the student menu

}

