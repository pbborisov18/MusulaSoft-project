#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void searchMenu();  //Links to the search menu

void searchPrefferedPosition(string searchTerm){ //Creates a function with variable searchTerm(The email for which we are searching for)

    ifstream file;          //Creates variable file
    file.open("Students.csv");    //Opens the file from the variable fileName() in this case Students.csv

    bool found = false;

    string firstName;
    string secondName;
    string email;
    string preferredpos;
    string classv;
    string inATeam;

    while(getline(file,firstName,',')){ //While loop which is entered if there is text between the start of the row and first comma and that the variable foundRecord is false
        getline(file,secondName,',');   //Stores all information between commas in the strings
        getline(file,email,',');
        getline(file,preferredpos,',');
        getline(file,classv,',');
        getline(file,inATeam,'\n');
        if((searchTerm == "scrum" || searchTerm == "scrum trainer" || searchTerm == "st" || searchTerm == "scrumtrainer")&(preferredpos == "scrum" || preferredpos == "scrum trainer" || preferredpos == "st" || preferredpos == "scrumtrainer")){
            cout << "\nFirst Name: " << firstName << "\n"
             << "Last Name: " << secondName << "\n"
             << "Email: " << email << "\n"
             << "Preferred position: " << preferredpos << "\n"
             << "Class: " << classv << "\n"
             << "Team: "<< inATeam << "\n\n";
            found = true;
        }

        else if((searchTerm == "backend" || searchTerm == "back end" || searchTerm == "be" || searchTerm == "back")&(preferredpos == "backend" || preferredpos == "back end" || preferredpos == "be" || preferredpos == "back")){
            cout << "\nFirst Name: " << firstName << "\n"
             << "Last Name: " << secondName << "\n"
             << "Email: " << email << "\n"
             << "Preferred position: " << preferredpos << "\n"
             << "Class: " << classv << "\n"
             << "Team: "<< inATeam << "\n\n";
            found = true;
        }

        else if((searchTerm == "frontend" || searchTerm == "front end" || searchTerm == "fe" || searchTerm == "front")&(preferredpos == "frontend" || preferredpos == "front end" || preferredpos == "fe" || preferredpos == "front")){
            cout << "\nFirst Name: " << firstName << "\n"
             << "Last Name: " << secondName << "\n"
             << "Email: " << email << "\n"
             << "Preferred position: " << preferredpos << "\n"
             << "Class: " << classv << "\n"
             << "Team: "<< inATeam << "\n\n";
            found = true;
        }

        else if((searchTerm == "quality assurance" || searchTerm == "qa" || searchTerm == "quality engineer" || searchTerm == "quality" || searchTerm == "qe")&(preferredpos == "quality assurance" || preferredpos == "qa" || preferredpos == "quality engineer" || preferredpos == "quality" || preferredpos == "qe")){
            cout << "\nFirst Name: " << firstName << "\n"
             << "Last Name: " << secondName << "\n"
             << "Email: " << email << "\n"
             << "Preferred position: " << preferredpos << "\n"
             << "Class: " << classv << "\n"
             << "Team: "<< inATeam << "\n\n";
            found = true;
        }

        else if(preferredpos == searchTerm){ //If the email is found it enters the if() statement
            cout << "\nFirst Name: " << firstName << "\n"
             << "Last Name: " << secondName << "\n"
             << "Email: " << email << "\n"
             << "Preferred position: " << preferredpos << "\n"
             << "Class: " << classv << "\n"
             << "Team: "<< inATeam << "\n\n";
            found = true;
        }
    }

file.close();

if(found = false){   //Otherwise we tell the user the student was not found
    cout << "\nNo Students found with that role!\n\n";
}

}
