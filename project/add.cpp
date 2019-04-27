#include <iostream>
#include <string>
#include <fstream>
#include "function.h"
using namespace std;

//This function is used to add record of information of employee
void add (){

  int temp = 0;
  string name;
  string id;
  string role;
  double salary;
  string att;
  int age;
  string choice;

//open file stream
  ofstream fout;
  fout.open ("data.txt", ios::app);

  if ( fout.fail() ){
    cout << "Failed to open the file " << endl;
    exit(1);}

//Allow user to stored the information if they want

  while (temp == 0){

    cout << "Please enter the new employee's name : ";
    cin.ignore();
    getline(cin, name);
    cout << endl;
    fout << name << endl;

    cout << "Please enter the new employee's ID : " ;
    cin >> id;
    cout << endl;
    fout << id << endl;

    cout << "Please enter the new employee's age (number only) : " ;
    cin >> age;
    cout << endl;
    fout << age << endl;

    cout << "Please enter the new employee's role : ";
    cin.ignore();
    getline(cin, role);
    cout << endl;
    fout << role << endl;

    cout << "Please enter the new employee's salary (number only) : ";
    cin >> salary;
    cout << endl;
    fout << salary << endl;

    //cout << "Please enter the new employee's attributes : ";
    //cin.ignore();
    //getline(cin, att);
    fout << endl;


//User can choose to use add function again without heading back to main menu, if they dont want do so, file stream will be closed

    cout << "Do you want to enter another employee ? (y/n) ";
    cin >> choice;
    if (choice == "n" or choice == "N"){
      temp = 1;
      fout.close();
      cout << endl;
      cout << endl;
      cout << endl;
      cout << endl;}

    else if (choice == "y" or choice == "Y"){
      cout << endl;}

    else{
      cout << "Error, now move back to menu. " << endl;
      temp = 1;
      fout.close();
      cout << endl;
      cout << endl;
      cout << endl;
    }

    }

}
