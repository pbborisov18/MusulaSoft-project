#include <iostream>
using namespace std;

void teamMenu();
void teamsEditMenu(string teamToBeEdited);
bool searchTeam(string searchTerm);

void teamsEdit(){
   system("cls");
    cout << "Which team's information do you want to edit(team name): ";

    string teamFind;
    cin >> teamFind;

    if(searchTeam(teamFind)==true){
        teamsEditMenu(teamFind);
    }
    else{
        system("pause");
        teamMenu();
    }
}
