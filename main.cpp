#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Students menu*/
void studentsAdd(); //function which adds students to Students.csv
    bool connectionsStudentExists(string studentEmail); //function which checks if a the email of the student you are trying to create already exists

void studentsDelete();  //function which deletes students off Students.csv
    void connectionsRemoveStudentFromTeam(string studentEmail); //connections from Students.csv to Teams.csv

void studentsEdit();    //function which edits students information in Students.csv
    void editFirstName(string emailToBeEdited, string fileToEdit, string tempFileName, string editNameTo);	//Edits students first name
    void editSecondName(string emailToBeEdited, string fileToEdit, string tempFileName, string editNameTo);	//Edits students last name
    void editEmail(string emailToEdit, string fileToEdit, string tempFileName, string editTo); //Edits students email
        void connectionsEmailChangeTeams(string emailToBeEdited, string editTo);	//Connections to teams.csv
    void editPreferredPos(string emailToBeEdited, string newPosition);	//Edits students preferred position
    void editClass(string emailToBeEdited, char newClass);	//Edits students class

/* Teachers menu*/
void teachersAdd(); //function which adds teachers to Teachers.csv
    bool connectionsTeachersEmailAlreadyExists(string teacherEmail);    //function which checks if a the email of the teacher you are trying to create already exists

void teachersDelete();  //function which deletes teachers off Teachers.csv
    void connectionsRemoveTeacherFromTeam(string teacherEmail); //connections from Teachers.csv to Teams.csv

void teachersEdit();    //function which edits teachers information in Teachers.csv
    void editFirstName(string emailToBeEdited, string fileToEdit, string tempFileName, string editNameTo);	//Edits teachers first name
    void editSecondName(string emailToBeEdited, string fileToEdit, string tempFileName, string editNameTo); //Edits teachers second name
    void editEmail(string emailToEdit, string fileToEdit, string tempFileName, string editTo); //Edits teachers email
        void connectionsEmailChangeTeams(string emailToBeEdited, string editTo);	//Connections to teams.csv

/* Teams menu*/
void teamsAdd();    //function which adds teams to Teams.csv
    vector<string> searchStudentTeam(string searchTermS);   //connections from Teams.csv to Students.csv Used for displaying information to the user and checking if student is legible to be in a team
    vector<string> searchTeacherTeam(string searchTermT);   //connections from Teams.csv to Teachers.csv Used for displaying information to the user
    void connectionsChangeStudentTeam(string studentName,string studentTeam);   //connections from Teams.csv to Students.csv Used for changing students team in Students.csv
    void connectionsChangeTeacherTeam(string teacherEmail); //connections from Teams.csv to Teachers.csv Used for changing the number of teams the teacher is part in

void teamsDelete(); //function which deletes teams off Teams.csv
    void connectionsChangeStudentTeamToNo(string teamName); //connection from Teams.csv to Students.csv Used for changing the team to No after deletion of the team
    void connectionsChangeTeacherTeamDown(string teacherEmail); //connection from Teams.csv to Teachers.csv Used for changing the number of teams the teacher is part in

void teamsEdit();   //function which searches if a team exists and prints it in the cmd
    void editTeamName(string teamToBeEdited, string editTo);	//Edits team name
        void connectionsChangeTeamNameStudents(string oldTeamName, string newTeamName);	//Connections to Students.csv
    void editTeamClassmates(string newStudentEmail, string teamNameOfStudent, int studentNumberInTeam);	//Edits students in Teams.csv depending who replaces him
        void connectionsTeamStudents(string oldStudentEmail, string newStudentEmail, string nameOfTeam);	//Connection to Students.csv

/* Search menu*/

bool searchStudent(string searchTerm);	//Searches Students.csv for a student

bool searchTeacher(string searchTerm);	//Searches Teachers.csv for a teacher

bool searchTeam(string searchTerm);		//Searches Teams.csv for a teacher

void searchPrefferedPosition(string searchTerm); //Searches and displays all students from Students.csv who have the role searched for

void searchTeachersWithoutTeam();       //Searches Teachers.csv for teachers without a team


void mainMenu();

int main()
{
    mainMenu();
    return 0;
}
