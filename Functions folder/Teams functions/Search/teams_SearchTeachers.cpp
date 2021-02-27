#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

void teamsAdd();

vector<string> searchTeacherTeam(string fileNameT, string searchTermT){
    vector<string> record;

    ifstream file;
    file.open(fileNameT);

    bool foundRecord = false;

    string firstName;
    string secondName;
    string email;
    string teams;

    while(getline(file,firstName,',') && !foundRecord){
        getline(file,secondName,',');
        getline(file,email,',');
        getline(file,teams,'\n');

        if(firstName == searchTermT){
            foundRecord=true;

            record.push_back(firstName);
            record.push_back(secondName);
            record.push_back(email);
            record.push_back(teams);

        }
    }

if(foundRecord==true){

        cout << "First Name: " << record[0] << "\n"
             << "Last Name: " << record[1] << "\n"
             << "Email: " << record[2] << "\n"
             << "Teams: "<< record[3] << "\n";


}
else{
    cout << "Teacher was not found!Try again!\n";
    string searchAgain;
    cin >> searchAgain;
    searchTeacherTeam("Teachers.csv",searchAgain);
}
return record;

}
