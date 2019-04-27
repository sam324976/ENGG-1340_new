#include <iostream>
#include <string>
#include <fstream>
#include "function.h"
using namespace std;

//This function is mainly used to searching on employee's information. There are two types of Searching
//method. One is searching by specific data type (name/role/id) and the other is search by salary(higher or lower).

//This function is main for the searching by specific data type
void search_1 (){
  //using dynamic varible so it can be deleted in the end of the function and free memory

  int *choice = new int;
  info employ;
  string *temp = new string;
  int *count = new int;
  *count = 0;

  //Give instrution for user to follow and choose which data type they want to use
  cout << endl;
  cout << "What feature do you want to use for searching? " << endl;
  cout << "1 : name " << endl;
  cout << "2 : id " << endl;
  cout << "3 : role" << endl;
  cout << "What is your choice ? " ;
  cin >> *choice;
  cout << endl;

  //seperate different choice by switch
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

    default:
//if user input a wrong number, it will return to main menu
      cout << "Error, please input a correct number " << endl;
      delete count;
      delete temp;
      delete choice;

      count = 0;
      temp = 0;
      choice = 0;
      return;}

  //open and read the file
  ifstream fin;
  fin.open("data.txt");

  if ( fin.fail() ){
    cout << "Failed to open the file " << endl;
    exit(1);}

  //read the value of the file and store them to struct varible which use to make comparsion
  while (getline(fin,employ.name)){

    fin >> employ.id;
    fin >> employ.age;
    fin.ignore();
    getline(fin, employ.role);
    fin >> employ.salary;
    fin.ignore();
    getline(fin, employ.att);

  // This is the comparsion parts. It will be different case which is determine by user's input. When result match,
  // it will be display on screen

  switch (*choice){
    case 1:

      if (employ.name == *temp){
        cout << endl;
        cout << "Employee's name : " << employ.name << endl;
        cout << "Employee's id : " << employ.id << endl;
        cout << "Employee's age : " << employ.age << endl;
        cout << "Employee's role : " << employ.role << endl;
        cout << "Employee's salary : "<< employ.salary << endl;
        cout << "Employee's attribute : " << employ.att << endl;
        *count = 1;}
        break;

    case 2:

      if (employ.id == *temp){
        cout << endl;
        cout << "Employee's name : " << employ.name << endl;
        cout << "Employee's id : " << employ.id << endl;
        cout << "Employee's age : " << employ.age << endl;
        cout << "Employee's role : " << employ.role << endl;
        cout << "Employee's salary : "<< employ.salary << endl;
        cout << "Employee's attribute : " << employ.att << endl;
        *count = 1;}
        break;

    case 3:

      if (employ.role == *temp){
        cout << endl;
        cout << "Employee's name : " << employ.name << endl;
        cout << "Employee's id : " << employ.id << endl;
        cout << "Employee's age : " << employ.age << endl;
        cout << "Employee's role : " << employ.role << endl;
        cout << "Employee's salary : "<< employ.salary << endl;
        cout << "Employee's attribute : " << employ.att << endl;
        *count = 1;}
        break;
      }
    }

// If there no match result
  if (*count == 0){
    cout << "No match result !!" << endl;}

// close the ifstream and destroy the varible
  fin.close();
  delete count;
  delete temp;
  delete choice;

  count = 0;
  temp = 0;
  choice = 0;
}

//This function is main for the searching by amount of salary
void search_2 (){

  //using dynamic varible so it can be deleted in the end of the function and free memory
  double *sal = new double;
  int *choice = new int;
  info employ;
  int *count = new int;
  *count = 0;

  //Give out instrution
  cout << endl;
  cout << "Please input the number of the salary : ";
  cin >> *sal;

  cout << "What do you want to display ?" << endl;
  cout << "1. Salary above or equal to the input number " << endl;
  cout << "2. Salary below the input number " << endl;
  cout << "What is your choice ? ";
  cin >> *choice;

  //open the file stream
  ifstream fin;
  fin.open("data.txt");

  if ( fin.fail() ){
    cout << "Failed to open the file " << endl;
    exit(1);}

  //read the file
  while (getline(fin,employ.name)){

    fin >> employ.id;
    fin >> employ.age;
    fin.ignore();
    getline(fin, employ.role);
    fin >> employ.salary;
    fin.ignore();
    getline(fin, employ.att);

  //seperate the cases by the choice of user
  switch(*choice){
    case 1:
      if (employ.salary >= *sal){
        cout << endl;
        cout << "Employee's name : " << employ.name << endl;
        cout << "Employee's id : " << employ.id << endl;
        cout << "Employee's age : " << employ.age << endl;
        cout << "Employee's role : " << employ.role << endl;
        cout << "Employee's salary : "<< employ.salary << endl;
        cout << "Employee's attribute : " << employ.att << endl;
        *count = 1; }
        break;
    case 2:
      if (employ.salary < *sal){
        cout << endl;
        cout << "Employee's name : " << employ.name << endl;
        cout << "Employee's id : " << employ.id << endl;
        cout << "Employee's age : " << employ.age << endl;
        cout << "Employee's role : " << employ.role << endl;
        cout << "Employee's salary : "<< employ.salary << endl;
        cout << "Employee's attribute : " << employ.att << endl;
        *count = 1; }
        break;
    default:

// if user input a wrong number, it will return to the search function.
      cout << " Error, please input a correct number !" << endl;
      fin.close();
      delete choice;
      delete count;
      delete sal;
      choice = 0;
      count = 0;
      sal = 0;
      cout << endl;
      cout << endl;
      return;
   }
   }
   if (*count == 0){
     cout << "No match result !!" << endl;}

    // close the ifstream and destroy the varible
    fin.close();
    delete choice;
    delete count;
    delete sal;
    choice = 0;
    count = 0;
    sal = 0;
}

// This is the main function for searching
void search(){

  //using dynamic varible so it can be deleted in the end of the function and free memory
  int *choice = new int;
  string *choice2 = new string;
  int *temp = new int;
  *temp = 0;

  //give out instrution and make user choose which type of searching they want to use
  while (*temp == 0){
  cout << "What type of search do you want to choose ?" << endl;
  cout << "1 : Seaching with name / id / role " << endl;
  cout << "2 : Seaching employee with their salary " << endl;
  cout << "What is your choice ? " ;
  cin >> *choice;
  switch (*choice){
    case 1:
    search_1();
    cout << endl;
    break;

    case 2:
    search_2();
    cout << endl;
    break;

    default:
    cout << " Error, please input a correct number !" << endl;
  }

  cout << "Do you want to search another employee ? (y/n) ";
  cin >> *choice2;

  if (*choice2 == "n" or *choice2 == "N"){
    cout << endl;
    cout << endl;
    cout << endl;
    return;
  }
  else if (*choice2 == "y" or *choice2 == "Y"){
    cout << endl;
    cout << endl;
    cout << endl;}
  else{
    cout << "Error, now move back to menu. " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    return;
  }
}
  //destroy the varible and reset the pointers
  delete choice;
  delete choice2;
  delete temp;

  choice = 0;
  choice2 = 0;
  temp = 0;

}
