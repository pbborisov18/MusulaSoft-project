#include <fstream>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

void connectionsChangeTeacherTeam(string teacherEmail){ //Changes the number of teams the teacher is in

    ifstream file;
    fstream fileNew{"TeachersTemp.csv"}; //creates a temporary file to write the new data to

    vector<string> record;

    string firstName;
    string secondName;
    string email;
    string inATeam;

    file.open("Teachers.csv", ios::app);        //Opens Teachers.csv and the temporary file TeachersTemp.csv in append mode
    fileNew.open("TeachersTemp.csv", ios::app);

    while(getline(file,firstName,',')){ //While loop which is entered if there is text between the start of the row and first comma
            getline(file,secondName,',');   //Stores all information between commas in the strings until the end of the row
            getline(file,email,',');
            getline(file,inATeam,'\n');

        if(email != teacherEmail){ //We enter the if statement if the name of the teacher isn't what we want to edit

            vector<string> record; //Vector temporary used to save teacher's information from the variables earlier

            record.push_back(firstName);
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(inATeam);

            fileNew << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "\n"; //Writing the information we got earlier to the temporary file TeachersTemp.csv
            record.clear(); //Clears the vector of all varibles. Resets it
        }
        else{ //When we find the teacher we want to edit we enter the if statement
            vector<string> record;

            record.push_back(firstName);
            record.push_back(secondName);
            record.push_back(email);

            int tempNumber=0; //temporary int

            stringstream stringToInt(inATeam); //string to int
            stringToInt >> tempNumber;

            tempNumber++; //we increase the number by one

            inATeam = to_string(tempNumber); //int to string

            record.push_back(inATeam); //save inATeam+1

            fileNew << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "\n"; //Write it to the temporary file TeachersTemp.csv
        }
    }

    fileNew.close();    //Closes StudentsTemp.csv
    file.close();       //Closes Students.csv

    remove("Teachers.csv"); //Delets Students.csv
    rename("TeachersTemp.csv", "Teachers.csv"); //Renames the temporary file StudentsTemp.csv to Students.csv



    return; //Returns back to the function from which it was called from

}
