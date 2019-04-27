#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "function.h"
using namespace std;

//This function is used to delete employee's record
void fire () {
  int *choice = new int;
  string *temp = new string;
  info employ;
  int *count = new int;
  *count = 0;

// give out instruction
  cout << "What type of delete do you want to choose ?" << endl;
  cout << "1 : name " << endl;
  cout << "2 : id " << endl;
  cout << "3 : role" << endl;
  cout << "What is your choice ? Please input a number : " ;
  cin >> *choice;
  cout << endl;

//seperate cases which is according to user's input
  switch (*choice){

    case 1:
      cout << "Please input the name : " ;
      cin.ignore();
      getline(cin,*temp);
      break;

    case 2:
      cout << "Please input the id : " ;
      cin.ignore();
      getline(cin,*temp);
      break;

    case 3:
      cout << "Please input the role : " ;
      cin.ignore();
      getline(cin,*temp);
      break;

//If user enter wrong number, it will be return to the main menu
    default:
      cout << "Error, please input a correct number " << endl;
      cout << "Now move back to main menu" << endl;
      cout << endl;
      delete choice;
      delete temp;
      delete count;
      choice = 0;
      temp = 0;
      count = 0;
      return;
      }

//open file stream
    ifstream fin;
    fin.open("data.txt");
    ofstream fout;
    fout.open("data_new.txt");

    if ( fin.fail() ){
      cout << "Failed to open the file " << endl;
      exit(1);}

    if ( fout.fail() ){
      cout << "Failed to open the file " << endl;
      exit(1);}

////read the value of the file and store them to struct varible which use to make comparsion
      while (getline(fin,employ.name)){

        fin >> employ.id;
        fin >> employ.age;
        fin.ignore();
        getline(fin, employ.role);
        fin >> employ.salary;
        fin.ignore();
        getline(fin, employ.att);

// to make comparsion in different choice and save the employee data which is not meant to be deleted in the new file

      switch (*choice){
        case 1:

          if (employ.name == *temp){
            *count = 1;
            continue;}
          else{
            fout << employ.name << endl;
            fout << employ.id << endl;
            fout << employ.age << endl;
            fout << employ.role << endl;
            fout << employ.salary << endl;
            fout << employ.att << endl;
            break;}

        case 2:

          if (employ.id == *temp){
            *count = 1;
            continue;}
          else{
            fout << employ.name << endl;
            fout << employ.id << endl;
            fout << employ.age << endl;
            fout << employ.role << endl;
            fout << employ.salary << endl;
            fout << employ.att << endl;
            break;}

        case 3:

          if (employ.role == *temp){
            *count = 1;
            continue;}
          else{
            fout << employ.name << endl;
            fout << employ.id << endl;
            fout << employ.age << endl;
            fout << employ.role << endl;
            fout << employ.salary << endl;
            fout << employ.att << endl;
            break;}
          }
        }

//close the in and out file stream and delete the old file / rename the new file in correct file name
        fin.close();
        fout.close();

        remove("data.txt");
        rename("data_new.txt","data.txt");
//if no match result happen
        if (*count == 0){
          cout << " No Match result !! " << endl;}
        else{
          cout << "The employee is fired !" << endl;}

// allow user to use function again without heading back to main menu if user follow the instruction
        cout << "Do you want to fire other employee? (y/n) ";
        cin >> *temp;
        if (*temp == "y" or *temp == "Y"){
          fire();}
        else if (*temp == "n" or *temp == "N"){
          cout << endl;
          cout << endl;
          cout << endl;}
        else{
          cout << "Error, now move to menu. " << endl;
          cout << endl;
          cout << endl;
          }
}
