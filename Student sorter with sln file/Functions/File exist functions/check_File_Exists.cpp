#include <fstream>
#include <iostream>
using namespace std;

void fileExists(string nameOfFile){ //Function which checks if the file at nameOfFile is created otherwise it creates it

   fstream file;

   file.open(nameOfFile); //Tries to open the file

   if(file){    //Checks if file is used
    return; //If yes returns to the function from which it was called
   }

   else {   //If no creates the file and returns to the function from which it was called
    ofstream fileCreate{nameOfFile};
    return;
   }
}
