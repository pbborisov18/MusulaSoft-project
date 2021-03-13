#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void searchMenu();  //Links to the search menu

void searchTeachersWithoutTeam(){ //Creates a function with variable searchTerm(The email for which we are searching for)

    ifstream file;          //Creates variable file
    file.open("Teachers.csv");    //Opens the file from the variable fileName() in this case Students.csv

    bool found = false;

    string firstName;
    string secondName;
    string email;
    string inATeam;

    while(getline(file,firstName,',')){ //While loop which is entered if there is text between the start of the row and first comma and that the variable foundRecord is false
        getline(file,secondName,',');   //Stores all information between commas in the strings
        getline(file,email,',');
        getline(file,inATeam,'\n');

        if(inATeam == "0"){
            cout << "\nFirst Name: " << firstName << "\n"
             << "Last Name: " << secondName << "\n"
             << "Email: " << email << "\n"
             << "Teams: "<< inATeam << "\n\n";
             found = true;
        }

    }

file.close();

if(found = false){   //Otherwise we tell the user the student was not found
    cout << "\nEvery teacher has a at least 1 team!\n\n";
}
return;
}
