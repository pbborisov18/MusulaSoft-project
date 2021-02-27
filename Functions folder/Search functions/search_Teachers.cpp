#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

void searchMenu();  //Links to the search menu

vector<string> searchTeacher(string fileName, string searchTerm){ //Creates a function of type vector<string> with variables fileName(The name of the file which is Students.csv) and the searchTerm(The name for which we are searching for)

    vector<string> record; //temporary vector which is used to record the information gathered by the function

    ifstream file;
    file.open(fileName); //Opens the file from the variable fileName() in this case Students.csv

    bool foundRecord = false;

    string firstName;
    string secondName;
    string email;
    string inATeam;

    while(getline(file,firstName,',') && !foundRecord){ //While loop which is entered if there is text between the start of the row and first comma and that the variable foundRecord is false
        getline(file,secondName,',');   //Stores all information between commas in the strings
        getline(file,email,',');
        getline(file,inATeam,'\n');

        if(firstName == searchTerm){ //If the name is found it enteres the if() statement

            foundRecord=true; //After the name is found there is no point to look for it anymore

            record.push_back(firstName);    //Saves the information in the record vector
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(inATeam);
        }
    }

if(foundRecord==true){  //If we found the teacher we display the information about him
        cout << "First Name: " << record[0] << "\n"
             << "Last Name: " << record[1] << "\n"
             << "Email: " << record[2] << "\n"
             << "Team: "<< record[3] << "\n";
}
else{   //Otherwise we tell the user the student was not found
    cout << "Teacher was not found!\n";
}
return record; //

}

void searchTeachers(){

    cout<<"Enter Teacher's Name: ";

    string name;
    cin >> name; //User's search

    searchTeacher("Teachers.csv",name); //we call the function

    system("pause");//Bad practise because users who use different os won't work. Pauses the program so the user can read what he searched for
    searchMenu();

}
