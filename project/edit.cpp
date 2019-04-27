#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include <stdio.h>
#include "function.h"

//This function is used to make edition on employee's information
void edit(){

  int *choice = new int;
  int * count = new int;
  *count = 1;
  string *name = new string;
  string *temp = new string;
  double *sal = new double;
  info employ;

// give out instruction and collect user input
  cout << "Please enter the name of the employee you want to edit : " ;
  cin.ignore();
  getline(cin, *name);
  cout << "Which feature do you want to edit ? " << endl;
  cout << "1.id" << endl;
  cout << "2.age" << endl;
  cout << "3.role" << endl;
  cout << "4.salary" << endl;
  cout << "5.attributes" << endl;
  cout << "What is your choice ? Please input a number :";
  cin >> *choice;

//open file stream
  ifstream fin;
  fin.open("data.txt");
  ofstream fout;
  fout.open("data_new2.txt");

  if ( fin.fail() ){
    cout << "Failed to open the file " << endl;
    exit(1);}

  if ( fout.fail() ){
    cout << "Failed to open the file " << endl;
    exit(1);}

// read the data in the file and stored them in to struct varible for edition
    while (getline(fin,employ.name)){

      //cout << employ.name << endl;
      fin >> employ.id;
      fin >> employ.age;
      fin.ignore();
      getline(fin, employ.role);
      fin >> employ.salary;
      fin.ignore();
      getline(fin, employ.att);

//seperate different cases with different modifrication
    switch (*choice){
      case 1:

        if (employ.name == *name){
          cout << "Please input the new id :" ;
          cin >> *temp;
          employ.id = *temp;
          *count = 2;}
        break;

      case 2:

        if (employ.name == *name){
          cout << "Please input the new age :" ;
          cin >> *temp;
          employ.age = *temp;
          *count = 2;}
        break;

      case 3:

        if (employ.name == *name){
          cout << "Please input the new role :" ;
          cin.ignore();
          getline(cin, *temp);
          employ.role = *temp;
          *count = 2;}
        break;

      case 4:

        if (employ.name == *name){
          cout << "Please input the new salary :" ;
          cin >> *sal;
          employ.salary = *sal;
          *count = 2;}
        break;

      case 5:

        if (employ.name == *name){
          cout << "Please input the new attributes :" ;
          cin.ignore();
          getline(cin, *temp);
          employ.att = *temp;
          *count = 2;}
        break;

//if user in input wrong number, it will return to main menu

      default:
        cout << " Error, please input a correct number !" << endl;
        fin.close();
        fout.close();
        delete choice;
        delete count;
        delete sal;
        delete name;

        choice = 0;
        count = 0;
        sal = 0;
        name = 0;
        cout << endl;
        cout << endl;
        return;
      }
//save the data in a new file
      fout << employ.name << endl;
      fout << employ.id << endl;
      fout << employ.age << endl;
      fout << employ.role << endl;
      fout << employ.salary << endl;
      fout << employ.att << endl;
    }
//close the in and out file stream and delete the old file and rename the new file in correct file name

    fin.close();
    fout.close();
    remove("data.txt");
    rename("data_new2.txt","data.txt");

//display the following string when no match result
    if (*count == 1){
      cout << "No match result, please input correct employee's name !! " << endl;
      cout << endl;}

//destroy the varible and reset pointer
    delete choice;
    delete count;
    delete sal;
    delete name;

    choice = 0;
    count = 0;
    sal = 0;
    name = 0;

// allow user to use function again without heading back to main menu
    cout << "Do you want to edit other employee? (y/n) ";
    cin >> *temp;
    if (*temp == "y" or *temp == "Y"){
      cout << endl;
      edit();}

    else if (*temp == "n" or *temp == "N"){
      cout << endl;
      delete temp;
      temp = 0;
      cout << endl;
      cout << endl;
      cout << endl;}

    else{
      cout << "Error, now move to menu. " << endl;
      delete temp;
      temp = 0;
      cout << endl;
      cout << endl;
      cout << endl;
      cout << endl;}

}
