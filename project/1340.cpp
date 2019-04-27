#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "function.h"
using namespace std;

//This is the main menu, it allows user to choose which function they want to use

int main(){
  int *temp1 = new int;
  *temp1 = 10;
  int *choice = new int;

  while (*temp1 == 10){
    cout << " *** Welcome to my system *** " << endl;
    cout << endl;

    cout << "Basic functions" << endl;
    cout << endl;
    cout << "1 : Adding a new employee " << endl;
    cout << endl;
    cout << "2 : Searching employee " << endl;
    cout << endl;
    cout << "3 : Fire a empployee" << endl;
    cout << endl;
    cout << "4 : Edit the detail of the employee" << endl;
    cout << endl;
    cout << "5 : End of program" << endl;
    cout << endl;
    cout << "What is your choice ? Please enter a number : " ;
    cin >> *choice;

    switch (*choice){

      case 1 :
        cout << endl;
        cout << endl;
        cout << endl;
        add();
        break;

      case 2 :
        cout << endl;
        cout << endl;
        cout << endl;
        search ();
        break;

      case 3 :
        cout << endl;
        cout << endl;
        cout << endl;
        fire ();

        break;

      case 4 :
        cout << endl;
        cout << endl;
        cout << endl;
        edit ();
        break;

      case 5 :
        exit(1);
        break;

      default:
        cout << "Error, please input a correct number " << endl;
        cout << endl;

    }
}
    //destroy the varible and reset pointer
    delete choice;
    delete temp1;
    temp1 = 0;
    choice = 0;

}
