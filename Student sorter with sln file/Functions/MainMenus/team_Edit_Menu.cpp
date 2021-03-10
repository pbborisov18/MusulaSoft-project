#include <iostream>
#include <string>
#include <vector>
using namespace std;

void teamMenu();
void editTeamName(string teamToBeEdited,string editTo);
void editTeamClassmates(string studentEmail, string teamNameOfStudent, int studentNumberInTeam);
void editTeamTeachers(string teacherEmail,string teamNameOfTecher);
bool searchStudent(string searchTerm);
bool searchTeacher(string searchTerm);
bool connectionsStudentAlreadyHasATeam(string studentEmail);

void teamsEditMenu(string teamToBeEdited){

    vector<string> test;

    cout << "\nWhat do you want to edit?\n\n";
    cout << "1.Team name\n";
    cout << "2.Student 1\n";
    cout << "3.Student 2\n";
    cout << "4.Student 3\n";
    cout << "5.Student 4\n";
    cout << "6.Teacher\n";
    cout << "7.Back to Team menu\n";

    int chooserTmEdit;

    cin >> chooserTmEdit; //User's choice on what menu he wants to go to

    while(cin.fail() || chooserTmEdit < 1 || chooserTmEdit > 7){ //If user fails to enter a number mentioned in the menu or enters something not accepted by int type. Allows user to re-enter.
        cout << "ERROR -- You did not enter an integer or you didn't enter a number between 1-7" << endl;
        cin.clear();
        cin.sync();
        cin >> chooserTmEdit;
    }

    if(chooserTmEdit==1){

        cout << "\n\nChange team name to: ";
        string changeTeamName;
        cin >> changeTeamName;
        editTeamName(teamToBeEdited, changeTeamName);
        teamMenu();
    }

    if(chooserTmEdit==2){

        cout << "\n\nChange student 1 to: ";
        string changeStudent1;
        cin >> changeStudent1;
        if(searchStudent(changeStudent1)==true){
            if(connectionsStudentAlreadyHasATeam(changeStudent1)==true){
                editTeamClassmates(changeStudent1, teamToBeEdited, 1);
                teamMenu();
            }
            else{
             system("pause");
                teamMenu();
            }
        }
        else{
            system("pause");
            teamMenu();
        }
    }

    if(chooserTmEdit==3){

        cout << "\n\nChange student 2 to: ";
        string changeStudent2;
        cin >> changeStudent2;
        if(searchStudent(changeStudent2)==true){
            if(connectionsStudentAlreadyHasATeam(changeStudent2)==true){
                editTeamClassmates(changeStudent2, teamToBeEdited, 2);
                teamMenu();
            }
            else{
             system("pause");
                teamMenu();
            }
        }
        else{
            system("pause");
            teamMenu();
        }
    }

    if(chooserTmEdit==4){

        cout << "\n\nChange student 3 to: ";
        string changeStudent3;
        cin >> changeStudent3;
        if(searchStudent(changeStudent3)==true){
            if(connectionsStudentAlreadyHasATeam(changeStudent3)==true){
                editTeamClassmates(changeStudent3, teamToBeEdited, 3);
                teamMenu();
            }
            else{
             system("pause");
                teamMenu();
            }
        }
        else{
            system("pause");
            teamMenu();
        }
    }

    if(chooserTmEdit==5){

        cout << "\n\nChange student 4 to: ";
        string changeStudent4;
        cin >> changeStudent4;
        if(searchStudent(changeStudent4)==true){
            if(connectionsStudentAlreadyHasATeam(changeStudent4)==true){
                editTeamClassmates(changeStudent4, teamToBeEdited, 4);
                teamMenu();
            }
            else{
             system("pause");
                teamMenu();
            }
        }
        else{
            system("pause");
            teamMenu();
        }
    }

    if(chooserTmEdit==6){
        system("cls");
        cout << "Changed teacher to: ";
        string changeTeacher;
        cin >> changeTeacher;
        if(searchTeacher(changeTeacher)==true){
                editTeamTeachers(changeTeacher, teamToBeEdited);

        }
        else{
            system("pause");
            teamMenu();
        }
    }

    if(chooserTmEdit==7){
        teamMenu();
    }

}
