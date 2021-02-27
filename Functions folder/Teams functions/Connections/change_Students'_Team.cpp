#include <fstream>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>
using namespace std;

void changeStudentTeam(string studentName,string studentTeam){

    fstream file;

    vector<string> record;

    bool foundRecord = false;

    string firstName;
    string secondName;
    string email;
    string preferredpos;
    string classv;
    string inATeam;

    file.open("Students.csv", ios::app);

    while(getline(file,firstName,',') && !foundRecord){
            getline(file,secondName,',');
            getline(file,email,',');
            getline(file,preferredpos,',');
            getline(file,classv,',');
            getline(file,inATeam,'\n');

        if(firstName == studentName){
            foundRecord=true;
        }

    }

if(foundRecord==true){
    record[5]=studentTeam;
    file << record[0] << "," << record[1] << "," << record[2] << "," << record[3] << "," << record[4] << "," << record[5] << endl;

}

file.close();

return;

}
